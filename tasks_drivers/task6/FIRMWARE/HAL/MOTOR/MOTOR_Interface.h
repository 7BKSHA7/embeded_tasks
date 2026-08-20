#ifndef _MOTOR_INTERFACE_H
#define _MOTOR_INTERFACE_H


#include"MOTOR_Private.h"
#include"MOTOR_Config.h"
#include"../../MCAL/DIO/DIO_interface.h"
#include"../../MCAL/TIMER0/TIMER0_interface.h"

void MOTOR_init();
void MOTOR_set_speed(u8 speed);
void MOTOR_set_direction(u8 direction);
void MOTOR_stop();
#endif