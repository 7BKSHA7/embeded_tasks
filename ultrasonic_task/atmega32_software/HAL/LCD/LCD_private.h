/**
 * @file      LCD_private.h
 * @author    Rohayem
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Private definitions for the LCD Driver.
 * @details   This file contains private macros, memory addresses, and command instructions 
 *            used internally by the LCD driver implementation. It should not be included by upper layers.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#ifndef _LCD_PRIVATE_H_
#define _LCD_PRIVATE_H_

#define Lcd_4bitMode     0
#define Lcd_8bitMode     1

#define Row1_Pos1 0x00
#define Row2_Pos1 0x40

#define Lcd_line0 0 
#define Lcd_line1 1

#define Lcd_column0  0 
#define Lcd_column1  1 
#define Lcd_column2  2 
#define Lcd_column3  3 
#define Lcd_column4  4 
#define Lcd_column5  5 
#define Lcd_column6  6 
#define Lcd_column7  7 
#define Lcd_column8  8 
#define Lcd_column9  9 
#define Lcd_column10 10
#define Lcd_column11 11
#define Lcd_column12 12
#define Lcd_column13 13
#define Lcd_column14 14
#define Lcd_column15 15


#define LCD_CLEAR_DISPLAY        0x01 //clear all lcd and back to first position

#define LCD_RETURN_HOME          0x02 //make the cursor back to first position but with out delete anything

#define LCD_ENTRY_MODE           0x06 //Sets the cursor movement direction after typing:
                                      //0x06 cursor move to right___0x04 cursor move to left

#define LCD_DISPLAY_ON           0x0C //dispaly on and cursor off

#define LCD_OnlyCursor_ON        0x0E //dispaly on+ cursor on

#define LCD_DISPLAY_OFF          0x08 //display off+cursor off

#define LCD_DISPLAY_ON_BLINK     0x0F //dispaly on+ cursor on+ cursor blinking

#define LCD_MODETYBE_4BIT        0x28 

#define LCD_MODETYBE_8BIT        0x38

#define LCD_CURSOR_LEFT          0x10 //cursor move 1 position to left

#define LCD_CURSOR_RIGHT         0x14 //cursor move 1 position to right

#define LCD_SHIFT_LEFT           0x18 //move all screen to left

#define LCD_SHIFT_RIGHT          0x1C //move all screen to left

#endif
