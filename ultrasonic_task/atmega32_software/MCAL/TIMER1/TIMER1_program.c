#include "TIMER1_interface.h"
#include "../DIO/DIO_interface.h"

static void (*timer1_OVFcallback)(void) = Null;
static void (*timer1_CTCcallbackA)(void) = Null;
static void (*timer1_CTCcallbackB)(void) = Null;
static void (*timer1_ICcallback)(void) = Null;

void TIMER1_init(timer1_config_t config) // timer config 
{
    if (config.timer_mode == Timer1_NormalMode) // to make it normal mode 
    {
        // set normal mode in tccr1 and enable interput
        ClearBit(TCCR1A , Timer1_WGM10);
        ClearBit(TCCR1A , Timer1_WGM11);
        ClearBit(TCCR1B , Timer1_WGM12);
        ClearBit(TCCR1B , Timer1_WGM13);
        TCNT1H = (u8)(config.preload_value >> move_to_low_byte);
        TCNT1L = (u8)config.preload_value;        // enable interput 
        SetBit(TIMSK, Timer1_TOIE1);
        SetBit(TIMSK, Timer1_TICIE1);
    }
    else if (config.timer_mode == Timer1_CTCMode) // to make it compare mode
    {
        // set ctc mode in tccr1 and enable interput 
        ClearBit(TCCR1A , Timer1_WGM10);
        ClearBit(TCCR1A , Timer1_WGM11);
        SetBit(TCCR1B , Timer1_WGM12);
        ClearBit(TCCR1B , Timer1_WGM13);
        OCR1AH = (u8)(config.compare_match_value >> move_to_low_byte);
        OCR1AL = (u8)config.compare_match_value;
        // enable interput
        SetBit(TIMSK, Timer1_OCIE1A);
    }
    else if (config.timer_mode == Timer1_InputCaptureMode) // to make it input capture mode
    {
        // set input capture mode in tccr1 and enable interput 
        ClearBit(TCCR1A , Timer1_WGM10);
        ClearBit(TCCR1A , Timer1_WGM11);
        ClearBit(TCCR1B , Timer1_WGM12);
        ClearBit(TCCR1B , Timer1_WGM13);
        TCNT1H = 0;
        TCNT1L = 0; 
        // default to rising edge first capture
        TIMER1_set_input_capture_edge(Timer1_rising_edge);
        
        // enable interput 
        TIMER1_enable_input_capture_interrupt();
    }
}
void TIMER1_start(u8 clock_select_value) // start and select prescaller
{
    // select prescaller
    if (clock_select_value != Timer1_Disable)
    {
        TCCR1B = (TCCR1B &~ clock_select_mask) | clock_select_value ;
    }
}
void TIMER1_stop(void)
{
    TCCR1B = (TCCR1B &~ clock_select_mask) | Timer1_Disable ;
}

void TIMER1_set_preload (u16 preload_value) // set the value to start from
{
    TCNT1H = (u8)(preload_value >> move_to_low_byte);
    TCNT1L = (u8)preload_value;
}

void TIMER1_set_compare_match (u16 compare_match_value) // set the value to compare to
{
    OCR1AH = (u8)(compare_match_value >> move_to_low_byte);
    OCR1AL = (u8)compare_match_value;
}

void TIMER1_set_input_capture_edge(u8 edge)
{
    if (edge == Timer1_rising_edge)
    {
        SetBit(TCCR1B, Timer1_ICES1);
    }
    else if (edge == Timer1_falling_edge)
    {
        ClearBit(TCCR1B, Timer1_ICES1);
    }
}

void TIMER1_enable_input_capture_interrupt(void)
{
    SetBit(TIMSK, Timer1_TICIE1);
}

void TIMER1_disable_input_capture_interrupt(void)
{
    ClearBit(TIMSK, Timer1_TICIE1);
}

u16 TIMER1_get_input_capture_value(void)
{
    u8 low_byte  = ICR1L;   
    u8 high_byte = ICR1H;
    return (u16)((high_byte << move_to_low_byte) | low_byte);
}

void TIMER1_set_call_back_fucntion (u8 timer_interupt_type , void (*PF)(void))
{
    if (timer_interupt_type == Timer1_overflow_interput)
    {
        if (PF != Null)
        {
            timer1_OVFcallback = PF;
        }
    }
    else if (timer_interupt_type == Timer1_compare_match_A_interput)
    {
        if (PF != Null)
        {
            timer1_CTCcallbackA = PF;
        }
    }
    else if (timer_interupt_type == Timer1_compare_match_B_interput)
    {
        if (PF != Null)
        {
            timer1_CTCcallbackB = PF;
        }
    }
    else if (timer_interupt_type == Timer1_input_capture_interput)
    {
        if (PF != Null)
        {
            timer1_ICcallback = PF;
        }
    }
}

// inpute capture
void __vector_6(void)
{   
    if (timer1_ICcallback != Null)
    {
        timer1_ICcallback();
    }
}
// compare match A
void __vector_7(void)
{   
    if (timer1_CTCcallbackA != Null)
    {
        timer1_CTCcallbackA();
    }
}
// compare match B
void __vector_8(void)
{
    if (timer1_CTCcallbackB != Null)
    {
        timer1_CTCcallbackB();
    }
}
// overflow 
void __vector_9(void)
{
    if (timer1_OVFcallback != Null)
    {
        timer1_OVFcallback();
    }
}