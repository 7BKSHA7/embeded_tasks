/**
 * @file      DIO_interface.h
 * @author    Beshoy
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Interface of the DIO (Digital Input/Output) Driver.
 * @details   This file contains the function prototypes and public APIs used by 
 *            upper layers to control the direction and state of microcontroller 
 *            pins and ports.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */


#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

#include "../STD_TYPES.h"
#include "../REG_MAP.h"
#include "../BIT_MATH.h"
#include "../COMMON_MACROS.h"
#include "DIO_config.h"
#include "DIO_private.h"


void DIO_set_pin_direction(u8 group_name , u8 pin_number , u8 direction);  
void DIO_set_pin_value(u8 group_name , u8 pin_number , u8 value);  
u8   DIO_get_pin_value(u8 group_name , u8 pin_number);   

void DIO_set_group_direction(u8 group_name , u8 direction);
void DIO_set_group_value(u8 group_name , u8 value);
u8   DIO_get_group_value(u8 group_name);


#endif
