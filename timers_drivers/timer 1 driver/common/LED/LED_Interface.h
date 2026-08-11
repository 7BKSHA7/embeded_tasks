#ifndef _LED_INTERFACE_H
#define _LED_INTERFACE_H

#include "LED_Private.h"
#include "LED_Config.h"
#include "../DIO/DIO_interface.h"

void Led_Init(u8 GroupName , u8 PinNumber , u8 ConnectionType );
void Led_on(u8 GroupName , u8 PinNumber );
void Led_off(u8 GroupName , u8 PinNumber );
void Led_Toggle(u8 GroupName , u8 PinNumber);
#endif