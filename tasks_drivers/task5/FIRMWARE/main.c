#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TIMER0/TIMER0_interface.h"
#include "HAL/PET/PET_interface.h"
#include "HAl/LED/LED_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "HAL/MOTOR/MOTOR_Interface.h"
#include <util/delay.h>

void main()
{
    MOTOR_init();
    // MOTOR_set_direction(Motor_backward);
    // MOTOR_set_speed(170);
    while(1)
    {
        MOTOR_set_direction(Motor_forward);
        MOTOR_set_speed(170);
        _delay_ms(500);
        MOTOR_set_direction(Motor_forward);
        MOTOR_set_speed(255);
        _delay_ms(500);
        MOTOR_set_direction(Motor_backward);
        MOTOR_set_speed(60);
        _delay_ms(500);
        MOTOR_set_direction(Motor_backward);
        MOTOR_set_speed(20);
        _delay_ms(500);
    }

}

