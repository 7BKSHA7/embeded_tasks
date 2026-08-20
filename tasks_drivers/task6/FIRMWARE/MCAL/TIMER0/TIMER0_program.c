/**
 * @file      TIMER0_program.c
 * @author    Beshoy
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Implementation of the TIMER0 (Digital Input/Output) Driver.
 * @details   This file contains the implementation of functions to control the 
 *            direction and value of individual pins and entire ports (groups) 
 *            on the microcontroller. Includes defensive checks for valid inputs.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */



#include "TIMER0_interface.h"

/*
    to start the init firstly
    first we gonna need to select the mode 
    and when we select the mode we select what values go with it
*/
static u8 static_pwm_mode = 0; 
static void (*timer0_OVFcallback)(void) = Null;
static void (*timer0_CTCcallback)(void) = Null;

void TIMER0_init(Timer0_config_t config)
{
    if(config.timer_mode == Timer0_normal)
    {
        // by doing 2 clear we made it into normal OVERFLOW
        // so we must set the perload value too
        ClearBit(TCCR0 , Timer0_WGM00);
        ClearBit(TCCR0 , Timer0_WGM01);
        //the preload
        TCNT0 = config.preload_value;
        // enable the interput 
        SetBit(TIMSK,Timer0_TOIE0);
    }
    else if (config.timer_mode == Timer0_CTC)
    {
        // now we are in compare match mode
        ClearBit(TCCR0 , Timer0_WGM00);
        SetBit(TCCR0 , Timer0_WGM01);
        // we set the value
        OCR0 = config.compare_match_value ;

        if (config.compare_output_mode == Timer0_COM_normal)
        {
            ClearBit(TCCR0 , Timer0_COM00);
            ClearBit(TCCR0 , Timer0_COM01);
        }
        else if (config.compare_output_mode == Timer0_COM_toggle)
        {
            SetBit(TCCR0 , Timer0_COM00);
            ClearBit(TCCR0 , Timer0_COM01);
        }
        else if (config.compare_output_mode == Timer0_COM_clear)
        {
            ClearBit(TCCR0 , Timer0_COM00);
            SetBit(TCCR0 , Timer0_COM01);
        }
        else if (config.compare_output_mode == Timer0_COM_set)
        {
            SetBit(TCCR0 , Timer0_COM00);
            SetBit(TCCR0 , Timer0_COM01);
        }

        // enable the interput
        SetBit(TIMSK,Timer0_OCIE0);
    }
    else if (config.timer_mode == Timer0_PWM_fast)
    {
        SetBit(TCCR0 , Timer0_WGM00);
        SetBit(TCCR0 , Timer0_WGM01);        
        // set duty cycle 
        if (config.compare_output_mode == Timer0_COM_normal)
        {
            ClearBit(TCCR0 , Timer0_COM00);
            ClearBit(TCCR0 , Timer0_COM01);
        }
        else if (config.compare_output_mode == Timer0_COM_non_inverting)
        {
            ClearBit(TCCR0 , Timer0_COM00);
            SetBit(TCCR0 , Timer0_COM01);
            static_pwm_mode = Timer0_COM_non_inverting;
        }
        else if (config.compare_output_mode == Timer0_COM_inverting)
        {
            SetBit(TCCR0 , Timer0_COM00);
            SetBit(TCCR0 , Timer0_COM01);
            static_pwm_mode = Timer0_COM_inverting;
            
        }
        OCR0 = clear_register;
    }
    else if (config.timer_mode == Timer0_PWM_phasecorrect)
    {
        SetBit(TCCR0 , Timer0_WGM00);
        ClearBit(TCCR0 , Timer0_WGM01);        
        // set duty cycle 
        if (config.compare_output_mode == Timer0_COM_normal)
        {
            ClearBit(TCCR0 , Timer0_COM00);
            ClearBit(TCCR0 , Timer0_COM01);
        }
        else if (config.compare_output_mode == Timer0_COM_non_inverting)
        {
            ClearBit(TCCR0 , Timer0_COM00);
            SetBit(TCCR0 , Timer0_COM01);
            static_pwm_mode = Timer0_COM_non_inverting;

        }
        else if (config.compare_output_mode == Timer0_COM_inverting)
        {
            SetBit(TCCR0 , Timer0_COM00);
            SetBit(TCCR0 , Timer0_COM01);
            static_pwm_mode = Timer0_COM_inverting;
            
        }
        OCR0 = clear_register;
    }
}

void TIMER0_start(Timer0_config_t config)
{
    if (config.presacler != no_clock)
    {
        TCCR0 = (TCCR0 &~ Timer0_mask_clock_select) | config.presacler ;
    }   
}   

void TIMER0_stop()
{
    TCCR0 = (TCCR0 &~ Timer0_mask_clock_select) | no_clock ;
}

void TIMER0_set_preload(u8 preload_value)
{
    TCNT0 = preload_value;
}

void TIMER0_set_compare_value (u8 compare_value)
{
    OCR0 = compare_value;
}

void TIMER0_set_duty_cycle (u8 duty_cycle)
{
    /*
        in non inverting mode 
            2^n * duty_cycle
        but in inverting mode
            2^n * (1-duty_cycle)
    */
    if (duty_cycle <= Timer0_max_duty_cycle)
    {
        u8 local_compare_value = 0 ;
        if (static_pwm_mode == Timer0_COM_inverting)
        {
            local_compare_value = Timer0_max_PWM - (u8)((Timer0_max_PWM*(u32)duty_cycle)/Timer0_max_duty_cycle) ; 
        }
        else if (static_pwm_mode == Timer0_COM_non_inverting)
        {
            local_compare_value = (u8)(((u32)duty_cycle * Timer0_max_PWM) / Timer0_max_duty_cycle); 
        }
        OCR0  = local_compare_value;
    }
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