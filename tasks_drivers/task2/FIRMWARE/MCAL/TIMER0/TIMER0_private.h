/**
 * @file      TIMER0_private.h
 * @author    Beshoy
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Private definitions for the TIMER0 Driver.
 * @details   This file contains internal macros representing the microcontroller 
 *            ports (groups) and pins. These are used by the TIMER0 implementation 
 *            and are essential for hardware configuration.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */


#ifndef _TIMER0_PRIVATE_H_
#define _TIMER0_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"

// TCCR0 
// this bit must be set to zero if you working in pwm mode 
// if you write a one on it an imidate compare match happens 
#define Timer0_FOC0     7 // force output compare 

// waveform generation bits
#define Timer0_WGM00    6
#define Timer0_WGM01    3 
// table controled by wgm

#define Timer0_normal               0 // mode
#define Timer0_PWM_phasecorrect     1 // mode
#define Timer0_CTC                  2 // mode
#define Timer0_PWM_fast             3 // mode

// compare output mode
// bits
#define Timer0_COM00    4
#define Timer0_COM01    5
/*  not used compare output mode


    // table for Compare Output Mode, non-PWM Mode
    // all this controls the OC0 register 

    #define Timer0_CTC_NonPWM_normal      0 // ctc_now_pwm
    #define Timer0_CTC_NonPWM_toggle      1 // ctc_now_pwm
    #define Timer0_CTC_NonPWM_clear       2 // ctc_now_pwm
    #define Timer0_CTC_NonPWM_set         3 // ctc_now_pwm

    // table for Compare Output Mode, Fast PWM Mode
    // all on oc0
    #define Timer0_CTC_FPWM_normal          0       // ocr disocnntected
    #define Timer0_CTC_FPWM_N_inverting     2       // clear on match | set at bottom  
    #define Timer0_CTC_FPWM_inverting       3       // set on match   | claer at bottom

    // table for Compare Output Mode, phase_correct PWM Mode
    // all on oc0
    #define Timer0_CTC_PCPWM_normal         0   // ocr disconected
    #define Timer0_CTC_PCPWM_clear_set      2   // clear on match upcounting | set on match downcouting
    #define Timer0_CTC_PCPWM_set_clear      3   // set on match upcounting   | clear on match downcouting
*/

// or even better insted of doing all that just make an enum

typedef enum // all modes using the COM to make it ezier
{
    Timer0_COM_normal = 0 ,     // all ctc
    Timer0_COM_toggle,
    Timer0_COM_clear,
    Timer0_COM_set,
    Timer0_COM_non_inverting, // pwm // clear on match | set at bottom  
    Timer0_COM_inverting,     // pwm // set on match   | clear at bottom
}Timer0_compare_output_mode_t ; 
// clock select 
/*  not used
    cs00
    cs01
    cs02
*/

typedef enum 
{
    no_clock = 0, 
    clk_1 , 
    clk_8 , 
    clk_64 , 
    clk_256 , 
    clk_1024 , 
    external_clock_t0_falling , 
    external_clock_t0_rising , 
}Timer0_prescaler_t;

#define Timer0_mask_clock_select  0x07 
// registter TCNT0 , OCR0 contiue the output numbers

// timsk
// interpuput match enable // I bit must be set

#define Timer0_TOIE0  0
#define Timer0_OCIE0  1

#define Timer0_overflow_interput 0 
#define Timer0_compare_match_interput 1
// tifr 
// flags // the interput must be enabled

#define Timer0_TOV0  0
#define Timer0_OCF0  1

// sfior

#define Timer0_PSR10  0 // prescaler reset

// we create a strcut that is gonna contiue all variables to
// start the timer

typedef struct 
{
    u8 timer_mode;
    u8 preload_value;
    u8 compare_match_value;
    u8 PWM_init_duty_cycle_precentage;
    Timer0_compare_output_mode_t compare_output_mode;
    Timer0_prescaler_t presacler;
}Timer0_config_t;

// for pwm mode 
#define Timer0_max_PWM         255UL
#define Timer0_max_duty_cycle   100


#endif 