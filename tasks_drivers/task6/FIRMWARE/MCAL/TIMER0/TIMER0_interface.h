/**
 * @file      TIMER0_interface.h
 * @author    Beshoy
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Interface of the TIMER0 (Digital Input/Output) Driver.
 * @details   This file contains the function prototypes and public APIs used by 
 *            upper layers to control the direction and state of microcontroller 
 *            pins and ports.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */


#ifndef _TIMER0_INTERFACE_H_
#define _TIMER0_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/COMMON_MACROS.h"
#include "../REG_MAP.h"
#include "TIMER0_config.h"
#include "TIMER0_private.h"

void TIMER0_init(Timer0_config_t config); 

void TIMER0_start(Timer0_config_t config);

void TIMER0_stop();

void TIMER0_set_preload(u8 preload_value);

void TIMER0_set_compare_value (u8 compare_value);

void TIMER0_set_duty_cycle (u8 duty_cycle);

void TIMER0_set_call_back_fucntion (u8 timer_interupt_type , void (*PF)(void));

#endif
