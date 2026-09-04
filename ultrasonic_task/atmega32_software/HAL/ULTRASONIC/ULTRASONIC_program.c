#include "ULTRASONIC_interface.h"
#include <util/delay.h>

void ULTRASONIC_init(void)
{
    DIO_set_pin_direction(ULTRASONIC_trig_port, ULTRASONIC_trig_pin, output);
    DIO_set_pin_direction(ULTRASONIC_echo_port, ULTRASONIC_echo_pin, input);
    timer1_config_t timer1_config =
    {
        .timer_mode = Timer1_NormalMode,   // we do it in normal mode
        .preload_value = 0,
        .compare_match_value = 0
    };
    TIMER1_init(timer1_config);
    // SetBit(TIFR, Timer1_ICF1);
    TIMER1_set_input_capture_edge(Timer1_rising_edge);  
    // TIMER1_set_call_back_fucntion(Timer1_input_capture_interput, ULTRASONIC_ISR_handler);
    TIMER1_start(Timer1_Prescaler8);
    // GIE_Enable();
}

u16 ULTRASONIC_get_distance(void)
{
    u16 rising_time;
    u16 falling_time;
    u16 echo_time;
    SetBit(TIFR, Timer1_ICF1);

    // the trigger 
    DIO_set_pin_value(ULTRASONIC_trig_port,ULTRASONIC_trig_pin,high);
    _delay_us(100);
    DIO_set_pin_value(ULTRASONIC_trig_port,ULTRASONIC_trig_pin,low);

    // we capture the rising edge 
    TIMER1_set_input_capture_edge(Timer1_rising_edge);
    while (ReadBit(TIFR, Timer1_ICF1) == 0);
    SetBit(TIFR, Timer1_ICF1);
    rising_time = TIMER1_get_input_capture_value();

    // change to falling
    TIMER1_set_input_capture_edge(Timer1_falling_edge);
    while (ReadBit(TIFR, Timer1_ICF1) == 0);
    falling_time = TIMER1_get_input_capture_value();
    SetBit(TIFR, Timer1_ICF1);

    // caluatle the time
    echo_time = falling_time - rising_time;

    // back to rising 
    TIMER1_set_input_capture_edge(Timer1_rising_edge);
    // now we covert the time 
    // speed of sound is 343 m/s = 0.0343 cm/μs <-- 34,320 cm / 1,000,000 µs
    // and we devive by 2 cause its a round trip 
    // 343 m = 34300 cm
    // total ditance = speed * time 
    // time about is 58.3 uS
    // speed of sound in cm/μs
    // THE 5.8090379 IS FOR BETTER PRESCIOSN
    return (u16)(echo_time / 5.8090379);
}


