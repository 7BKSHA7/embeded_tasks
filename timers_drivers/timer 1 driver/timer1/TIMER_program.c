/**
 * @file      TIMER_program.c
 * @author    Beshoy
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Implementation of the TIMER0 Driver.
 * @details   This file contains the implementation of Timer0 initialization, 
 *            start, stop, and callback assignment functions. It supports 
 *            Normal (Overflow) and CTC (Compare Match) modes.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "TIMER_interface.h"

static void (*timer1_OVFcallback)(void) = Null;
static void (*timer1_CTCcallbackA)(void) = Null;
static void (*timer1_CTCcallbackB)(void) = Null;
static void (*timer1_ICcallback)(void) = Null;

void TIMER1_init(timer1_config_t config) // timer config 
{
    if (config.timer_mode == Timer1_NormalMode) // to make it normal mode 
    {
        // set normal mode in tccr0 and enable interput
        ClearBit(TCCR1A , Timer1_WGM10);
        ClearBit(TCCR1A , Timer1_WGM11);
        ClearBit(TCCR1B , Timer1_WGM12);
        ClearBit(TCCR1B , Timer1_WGM13);
        TCNT1H = (u8)(config.preload_value >> move_to_low_byte);
        TCNT1L = (u8)config.preload_value;        // enable interput 
        SetBit(TIMSK, Timer1_TOIE1);
    }
    else if (config.timer_mode == Timer1_CTCMode) // to make it compare mode
    {
        // set ctc mode in tccr0 and enable interput 
        ClearBit(TCCR1A , Timer1_WGM10);
        ClearBit(TCCR1A , Timer1_WGM11);
        SetBit(TCCR1B , Timer1_WGM12);
        ClearBit(TCCR1B , Timer1_WGM13);
        OCR1AH = (u8)(config.compare_match_value >> move_to_low_byte);
        OCR1AL = (u8)config.compare_match_value;
        // enable interput
        SetBit(TIMSK, Timer1_OCIE1A);
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
void __vector_6(void)   __attribute__((signal));
void __vector_6(void)
{   
    if (timer1_ICcallback != Null)
    {
        timer1_ICcallback();
    }
}
// compare match A
void __vector_7(void)   __attribute__((signal));
void __vector_7(void)
{   
    if (timer1_CTCcallbackA != Null)
    {
        timer1_CTCcallbackA();
    }
}
// compare match B
void __vector_8(void)   __attribute__((signal));
void __vector_8(void)
{
    if (timer1_CTCcallbackB != Null)
    {
        timer1_CTCcallbackB();
    }
}
// overflow 
void __vector_9(void)   __attribute__((signal));
void __vector_9(void)
{
    if (timer1_OVFcallback != Null)
    {
        timer1_OVFcallback();
    }
}