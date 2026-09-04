/**
 * @file      LCD_interface.h
 * @author    Rohayem
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Interface of the LCD (Liquid Crystal Display) Driver.
 * @details   This file contains the function prototypes and public APIs used by 
 *            upper layers to initialize and interact with the LCD module.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "LCD_config.h"
#include "LCD_private.h"

void LCD_INIT        (u8 ModeType);
void LCD_WriteCommand(u8 command , u8 ModeType);
void LCD_WriteData   (u8 data , u8 ModeType);
void LCD_WriteString (u8*str , u8 ModeType);
void LCD_GoToXY      (u8 row , u8 column, u8 ModeType);
void LCD_WriteNUMBER (u16 Number, u8 ModeType);

#endif
