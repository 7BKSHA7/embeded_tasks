/**
 * @file      TIMER_private.h
 * @author    Beshoy
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Private definitions for the TIMER0 Driver.
 * @details   This file contains internal macros representing the microcontroller 
 *            register bits for Timer0 (TCCR0, TIMSK), along with configuration 
 *            constants and the configuration structure used by the driver.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */


#ifndef _TIMER_PRIVATE_H_
#define _TIMER_PRIVATE_H_
#include "../common/STD_TYPES.h"

// wavegenration 
#define Timer0_FOC0     7
#define Timer0_WGM00    6
#define Timer0_WGM01    3

//output mode
#define Timer0_COM01    5
#define Timer0_COM00    4

//clock select 
#define Timer0_CS02     2
#define Timer0_CS01     1
#define Timer0_CS00     0

// choose mode 
#define Timer0_normalmode 0 
#define Timer0_CTCmode    1

// choose comapre 
#define Timer0_OC0disconnect 0
#define Timer0_OC0toggle     1
#define Timer0_OC0clear      2
#define Timer0_OC0set        3

// to choose the prescaller
#define Timer0_Disable        0
#define Timer0_Prescaler1     1
#define Timer0_Prescaler8     2
#define Timer0_Prescaler64    3
#define Timer0_Prescaler256   4
#define Timer0_Prescaler1024  5

// choose the type 
#define Timer0_extrenalfalling 6
#define Timer0_extrenalrising  7

#define clock_select_mask  0x07

// interput enable
#define Timer0_OCIE0    1
#define Timer0_TOIE0     0

#define Timer0_overflow_interput 0 
#define Timer0_compare_match_interput 1

/*
    caluation for 50 ms 
    timer 8bit  / sys frequency = 8mhz  / prescaller 8 
    clc time --> 8/8M = 1uS
    overflow 1u * 256 = 256uS
    req > overflowtime
    no of of count --> 195.3125
    preload --> 176
*/


typedef struct 
{
    u8 timer_mode;
    u8 preload_value;
    u8 compare_match_value;
}timer0_config_t;


#endif
