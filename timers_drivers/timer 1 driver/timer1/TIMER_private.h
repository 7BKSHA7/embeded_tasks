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

// wavegenaration mode 

#define Timer1_WGM13  4    // in TCCR1B
#define Timer1_WGM12  3    // in TCCR1B
#define Timer1_WGM11  1    // in TCCR1A
#define Timer1_WGM10  0    // in TCCR1A

// chose mode 

#define Timer1_NormalMode 0
#define Timer1_CTCMode    1 // |0|1|0|0|CTC|OCR1A|Immediate| MAX
// #define Timer1_CTCMode_input_capture   2  // <- not gonna use it rn
// choose comapre 
#define Timer1_OC_disconnect 0
#define Timer1_OC_toggle     1
#define Timer1_OC_clear      2
#define Timer1_OC_set        3


// output compare mode  
#define Timer1_COM1A1   7  // in TCCR1A
#define Timer1_COM1A0   6  // in TCCR1A
#define Timer1_COM1B1   5  // in TCCR1A
#define Timer1_COM1B0   4  // in TCCR1A

// force output mode
#define Timer1_FOC1A 3  // in TCCR1A
#define Timer1_FOC1B 2  // in TCCR1A

#define Timer1_ICNC1 7 // in TCCR1B  Input Capture Noise Canceler
#define Timer1_ICES1 6 // in TCCR1B  Input Capture Edge Select  

// clock select
#define Timer1_CS12 2 // in TCCR1B
#define Timer1_CS11 1 // in TCCR1B 
#define Timer1_CS10 0 // in TCCR1B

// interupt enable

#define Timer1_TICIE1    5  // IN TIMSK Input Capture Interrupt Enable
#define Timer1_OCIE1A    4  // IN TIMSK Output Compare A Interrupt Enable
#define Timer1_OCIE1B    3  // IN TIMSK Output Compare B Interrupt Enable
#define Timer1_TOIE1     2  // IN TIMSK Timer Overflow Interrupt Enable

// interput flags

#define Timer1_ICF1     5  // IN TIFR Input Capture Flag
#define Timer1_OCF1A    4  // IN TIFR Output Compare A Flag
#define Timer1_OCF1B    3  // IN TIFR Output Compare B Flag
#define Timer1_TOV1     2  // IN TIFR Timer Overflow Flag

// to choose the prescaller
#define Timer1_Disable        0
#define Timer1_Prescaler1     1
#define Timer1_Prescaler8     2
#define Timer1_Prescaler64    3
#define Timer1_Prescaler256   4
#define Timer1_Prescaler1024  5

// interput modes
#define Timer1_overflow_interput        0 
#define Timer1_compare_match_A_interput 1
#define Timer1_compare_match_B_interput 2
#define Timer1_input_capture_interput   3


#define clock_select_mask  0x07

#define move_to_low_byte  8

typedef struct 
{
    u8 timer_mode;
    u16 preload_value;      
    u16 compare_match_value;
}timer1_config_t;


#endif
