/**
 * @file      LCD_program.c
 * @author    Rohayem
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Implementation of the LCD (Liquid Crystal Display) Driver.
 * @details   This file contains the core implementation for initializing and controlling 
 *            the LCD in both 4-bit and 8-bit modes. It includes functions for writing 
 *            data, commands, strings, and numbers, as well as cursor positioning.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/COMMON_MACROS.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/REG_MAP.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include <util/delay.h>

#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"

void LCD_WriteData(u8 data , u8 ModeType)
{
    /*
    when we use 4bit mode when we send data we send it in 2 times
    here i will use pins (D4 D5 D6 D7)
    i can name first part(First_4bits >> 0011), secoundpart(Secound_4bits >> 0011)
    there's a problem here/ i wann 00110011 next each other to get ma char
    so i can add both next to each othe 0011+0011==00110011 so i will save 4 bits then send anor=ther 4bits then save them.*/
    if (ModeType==Lcd_4bitMode)
    {
        DIO_set_pin_value(LCD_RSGroup , LCD_RSPin , high);

        /*here i will explain how it wok _______i want send char (A==0100 0001) so i will read each bit in nd put it in pin
        after save 4 bits i make enable to save first 4 bits then i put second 4 bits then save them with enable
        */
        DIO_set_pin_value(LCD_DataGroup , Dio_pin4 , ReadBit(data,4));
        DIO_set_pin_value(LCD_DataGroup , Dio_pin5 , ReadBit(data,5));
        DIO_set_pin_value(LCD_DataGroup , Dio_pin6 , ReadBit(data,6));
        DIO_set_pin_value(LCD_DataGroup , Dio_pin7 , ReadBit(data,7));

        DIO_set_pin_value(LCD_EGroup , LCD_EPin , high);
        _delay_ms(1);
        DIO_set_pin_value(LCD_EGroup , LCD_EPin , low);

        // 
        DIO_set_pin_value(LCD_DataGroup , Dio_pin4 , ReadBit(data,0));
        DIO_set_pin_value(LCD_DataGroup , Dio_pin5 , ReadBit(data,1));
        DIO_set_pin_value(LCD_DataGroup , Dio_pin6 , ReadBit(data,2));
        DIO_set_pin_value(LCD_DataGroup , Dio_pin7 , ReadBit(data,3));

        DIO_set_pin_value(LCD_EGroup , LCD_EPin , high);
        _delay_ms(1);
        DIO_set_pin_value(LCD_EGroup , LCD_EPin , low);
    }   

    /*
    when we use 8bit mode when we send data we send it in one time
    EX: I WANNA SEND 00110011 IT WILL SEND IN 1 TIME LIKE
    D7 D6 D5 D4 D3 D2 D1 D0
    0  0  1  1  0  0  1  1
    */
     else if(ModeType==Lcd_8bitMode)
    {
        DIO_set_pin_value(LCD_RSGroup , LCD_RSPin,high);
        DIO_set_group_value(LCD_DataGroup , data ); //saved all 8 bits one time

        DIO_set_pin_value(LCD_EGroup , LCD_EPin , high); //saved the data
        _delay_ms(1);
        DIO_set_pin_value(LCD_EGroup , LCD_EPin , low);
    }

}


void LCD_WriteCommand(u8 command , u8 ModeType)
{
    if(ModeType == Lcd_4bitMode)
    {
        DIO_set_pin_value(LCD_RSGroup , LCD_RSPin , low); //LOW CUZ I WILL USE ORDER

        DIO_set_pin_value(LCD_DataGroup , Dio_pin4 , ReadBit(command,4));
        DIO_set_pin_value(LCD_DataGroup , Dio_pin5 , ReadBit(command,5));
        DIO_set_pin_value(LCD_DataGroup , Dio_pin6 , ReadBit(command,6));
        DIO_set_pin_value(LCD_DataGroup , Dio_pin7 , ReadBit(command,7));

        DIO_set_pin_value(LCD_EGroup , LCD_EPin , high);
        _delay_ms(1);
        DIO_set_pin_value(LCD_EGroup , LCD_EPin , low);

        DIO_set_pin_value(LCD_DataGroup , Dio_pin4 , ReadBit(command,0));
        DIO_set_pin_value(LCD_DataGroup , Dio_pin5 , ReadBit(command,1));
        DIO_set_pin_value(LCD_DataGroup , Dio_pin6 , ReadBit(command,2));
        DIO_set_pin_value(LCD_DataGroup , Dio_pin7 , ReadBit(command,3));

        DIO_set_pin_value(LCD_EGroup , LCD_EPin , high);
        _delay_ms(1);
        DIO_set_pin_value(LCD_EGroup , LCD_EPin , low);
    }
    else if(ModeType == Lcd_8bitMode)
    {
        DIO_set_pin_value(LCD_RSGroup , LCD_RSPin , low);
        DIO_set_group_value(LCD_DataGroup , command);

        DIO_set_pin_value(LCD_EGroup , LCD_EPin , high);
        _delay_ms(1);
        DIO_set_pin_value(LCD_EGroup , LCD_EPin , low);
    }
}

void LCD_INIT(u8 ModeType)
{
    if(ModeType==Lcd_4bitMode)                      
    {   
        DIO_set_group_direction(LCD_DataGroup , LCD_datapins);  //here i will use D4:D7     
        DIO_set_pin_direction(LCD_RSGroup , LCD_RSPin , output);  // resgister select pin
        DIO_set_pin_direction(LCD_EGroup  , LCD_EPin  , output);  // enable pin
        _delay_ms(35);
        /*HERE CODE TO MAKE LCD 4 BITS____becouse its automatically work with 8 bit mode*/
        LCD_WriteCommand(LCD_RETURN_HOME , Lcd_4bitMode); // returen to first postion
        _delay_ms(2);
        LCD_WriteCommand(LCD_MODETYBE_4BIT , Lcd_4bitMode); // 4bit mode
        _delay_ms(1);
        LCD_WriteCommand(LCD_DISPLAY_ON , Lcd_4bitMode); // display on cursor off
        _delay_ms(1);
        LCD_WriteCommand(LCD_CLEAR_DISPLAY , Lcd_4bitMode); // clear display 
        _delay_ms(2);
        LCD_WriteCommand(LCD_ENTRY_MODE , Lcd_4bitMode); // set cursor move to right
        _delay_ms(1);

    } 
    else if(ModeType==Lcd_8bitMode)
    {
        DIO_set_group_direction(LCD_DataGroup , LCD_datapins_all); //ALL OUTPUT CUZ I WILL USE ALL BITS IN PINS
        DIO_set_pin_direction(LCD_RSGroup , LCD_RSPin , output);
        DIO_set_pin_direction(LCD_EGroup , LCD_EPin , output);
        _delay_ms(35);
        LCD_WriteCommand(LCD_MODETYBE_8BIT , Lcd_8bitMode);
        _delay_ms(1);
        LCD_WriteCommand(LCD_OnlyCursor_ON , Lcd_8bitMode);
        _delay_ms(1);
        LCD_WriteCommand(LCD_CLEAR_DISPLAY , Lcd_8bitMode);
        _delay_ms(2);
        LCD_WriteCommand(LCD_ENTRY_MODE , Lcd_8bitMode);
        _delay_ms(1);
    }

}

void LCD_WriteString (u8*string , u8 ModeType)
{
     uint8_t counter=0;

     while(string[counter] !='\0')
     {
         LCD_WriteData(string[counter] , ModeType);
         counter++; 
     }    
}
void LCD_GoToXY(u8 row , u8 column, u8 ModeType)
{
    u8 DigitAddress = 0 ;
    switch(row)
      {
        case 0 : DigitAddress = Row1_Pos1 +column ; break; //first row start with 0x00
        case 1 : DigitAddress = Row2_Pos1 +column ; break; //second row start with 0x40
      }
    LCD_WriteCommand(DigitAddress | 0x80 , ModeType);
}

void LCD_WriteNUMBER (u16 Number, u8 ModeType)
{
        u8 array[10];
        u8 counter=0;
        s8 num;   //i had a bug here cuz i used u8 so it made noninfinity loop 
                 //so i used s8 signed cuz after 0 will se -1 so loop stop (s: -127:127 , u: 0:255) 
    if(Number == 0)
    {
        LCD_WriteData(48, ModeType);
        return;
    }
    while(Number > 0)
    {
        array[counter++] = (Number % 10) + 48; // '0'==48 is zero in char. here i save numbers in array, bt i save last number at first
        Number /= 10;                         //num %10 will save lasst number_ using number/10 delete last number that we saved in array
    }                                        //while wil worl till we reach 0

    for(num = counter-1 ;num >= 0 ;num --) // here i will print numbers by using lcd_writedata bt from last number
    {                                                       // in array till reach first one - to print number like we got it
        LCD_WriteData(array[num] , ModeType);
    }

}


