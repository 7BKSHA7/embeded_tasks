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

static void (*timer0_OVFcallback)(void) = Null;
static void (*timer0_CTCcallback)(void) = Null;

void TIMER0_init(timer0_config_t config) // timer config 
{
    if (config.timer_mode == Timer0_normalmode) // to make it normal mode 
    {
        // set normal mode in tccr0 and enable interput
        ClearBit(TCCR0 , Timer0_WGM00);
        ClearBit(TCCR0 , Timer0_WGM01);
        TCNT0 = config.preload_value;
        // enable interput 
        SetBit(TIMSK, Timer0_TOIE0);
    }
    else if (config.timer_mode == Timer0_CTCmode) // to make it compare mode
    {
        // set ctc mode in tccr0 and enable interput 
        ClearBit(TCCR0 , Timer0_WGM00);
        SetBit(TCCR0 , Timer0_WGM01);
        OCR0 = config.compare_match_value;
        // enable interput
        SetBit(TIMSK, Timer0_OCIE0);
    }
}
void TIMER0_start(u8 clock_select_value) // start and select prescaller
{
    // select prescaller
    if (clock_select_value != Timer0_Disable)
    {
        TCCR0 = (TCCR0 &~ clock_select_mask) | clock_select_value ;
    }
}
void TIMER0_stop(void)
{
    TCCR0 = (TCCR0 &~ clock_select_mask) | Timer0_Disable ;
}

void TIMER0_set_preload (u8 preload_value) // set the value to start from
{
    TCNT0 = preload_value;
}

void TIMER0_set_compare_match (u8 compare_match_value) // set the value to compare to
{
    OCR0= compare_match_value;
}


void TIMER0_set_call_back_fucntion (u8 timer_interupt_type , void (*PF)(void))
{
    if (timer_interupt_type == Timer0_overflow_interput)
    {
        if (PF != Null)
        {
            timer0_OVFcallback = PF;
        }
    }
    else if (timer_interupt_type == Timer0_compare_match_interput)
    {
        if (PF != Null)
        {
            timer0_CTCcallback = PF;
        }
    }
}


// compare match
void __vector_10(void)   __attribute__((signal));
void __vector_10(void)
{   
    if (timer0_CTCcallback != Null)
    {
        timer0_CTCcallback();
    }
}
// overflow isr
void __vector_11(void)   __attribute__((signal));
void __vector_11(void)
{
    if (timer0_OVFcallback != Null)
    {
        timer0_OVFcallback();
    }
}
