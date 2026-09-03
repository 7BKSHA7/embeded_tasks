#include "ULTRASONIC_interface.h"
#include <util/delay.h>

static u16 rising_time  = 0;
static u16 falling_time = 0;
static u8  capture_state = 0;   // 0 = waiting for rising, 1 = waiting for falling
static u8  capture_done  = 0;   // flag for main loop to check


void ULTRASONIC_ISR_handler(void);

void ULTRASONIC_init(void)
{
    timer1_config_t timer1_config =
    {
        .timer_mode = Timer1_InputCaptureMode, // normal mode but we turn on the iterputs 
        .preload_value = 0,
        .compare_match_value = 0
    };
    TIMER1_init(timer1_config);
    TIMER1_set_call_back_fucntion(Timer1_input_capture_interput, ULTRASONIC_ISR_handler);
    TIMER1_start(Timer1_Prescaler8);
    DIO_set_pin_direction(ULTRASONIC_trig_port, ULTRASONIC_trig_pin, output);
    DIO_set_pin_direction(ULTRASONIC_echo_port, ULTRASONIC_echo_pin, input);
    GIE_Enable();
}
void ULTRASONIC_trigger(void)
{
    DIO_set_pin_value(ULTRASONIC_trig_port, ULTRASONIC_trig_pin, high);
    _delay_us(10);
    DIO_set_pin_value(ULTRASONIC_trig_port, ULTRASONIC_trig_pin, low);
}
u16  ULTRASONIC_get_pulse_width(void)
{
    return(falling_time - rising_time) ;

}
u16  ULTRASONIC_get_distance(void)
{
    u16 pulse_width = ULTRASONIC_get_pulse_width();
    u16 distance = (pulse_width * 0.0343) / 2;  // speed of sound in cm/μs
    return distance;
}

void ULTRASONIC_ISR_handler(void)
{
    if (capture_state == 0)   // we just captured a rising edge
    {
        rising_time = TIMER1_get_input_capture_value();
        TIMER1_set_input_capture_edge(Timer1_falling_edge);
        capture_state = 1;
    }
    else   // we just captured a falling edge
    {
        falling_time = TIMER1_get_input_capture_value();
        TIMER1_set_input_capture_edge(Timer1_rising_edge);
        capture_state = 0;
        capture_done = 1;
    }

}