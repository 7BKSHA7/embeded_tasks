/**
 * @file      TIMER_interface.h
 * @author    Beshoy
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Interface of the TIMER0 Driver.
 * @details   This file contains the function prototypes and public APIs used by 
 *            upper layers to initialize, configure, start, and stop Timer0, 
 *            as well as assigning callback functions for its interrupts.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */


#ifndef _TIMER_INTERFACE_H_
#define _TIMER_INTERFACE_H_

#include "../common/STD_TYPES.h"
#include "../common/BIT_MATH.h"
#include "../common/COMMON_MACROS.h"
#include "../common/REG_MAP.h"
#include "TIMER_config.h"
#include "TIMER_private.h"

void TIMER1_init(timer1_config_t config);
void TIMER1_start(u8 clock_select_value);
void TIMER1_stop(void);
void TIMER1_set_preload (u16 preload_value);
void TIMER1_set_compare_match (u16 compare_match_value);


void TIMER1_set_call_back_fucntion (u8 timer_interupt_type , void (*PF)(void));


// compare match
void __vector_10(void)   __attribute__((signal));
// overflow 
void __vector_11(void)   __attribute__((signal));

#endif
