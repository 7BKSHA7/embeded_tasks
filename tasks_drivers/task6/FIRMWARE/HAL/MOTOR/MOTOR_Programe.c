#include"MOTOR_Interface.h"

void MOTOR_init()
{
    Timer0_config_t config_main_t =
    {
        .timer_mode = Timer0_PWM_fast,
        .presacler = clk_8,
        .preload_value = 0,
        .compare_match_value = 0,
        .compare_output_mode = Timer0_COM_non_inverting,
    };
    // set the dio for the OC0
    DIO_set_pin_direction(Motor_group , Motor_pin , output);
    // set the direction 
    DIO_set_pin_direction(Motor_IN1_group, Motor_IN1_pin, output);
    DIO_set_pin_direction(Motor_IN2_group, Motor_IN2_pin, output);
    // set the speed
    DIO_set_pin_value(Motor_IN1_group, Motor_IN1_pin, low);
    DIO_set_pin_value(Motor_IN2_group, Motor_IN2_pin, low);

    TIMER0_init(config_main_t);
    TIMER0_start(config_main_t);
    GIE_Enable();
}

void MOTOR_set_speed(u8 speed)
{
    TIMER0_set_compare_value(speed);
}

void MOTOR_set_direction(u8 direction)
{
    switch(direction)
    {
        case Motor_forward :
            DIO_set_pin_value(Motor_IN1_group, Motor_IN1_pin, high);
            DIO_set_pin_value(Motor_IN2_group, Motor_IN2_pin, low);
            break;
        case Motor_backward :
            DIO_set_pin_value(Motor_IN1_group, Motor_IN1_pin, low);
            DIO_set_pin_value(Motor_IN2_group, Motor_IN2_pin, high);
            break;
        default :
            DIO_set_pin_value(Motor_IN1_group, Motor_IN1_pin, low);
            DIO_set_pin_value(Motor_IN2_group, Motor_IN2_pin, low);
            break;
    }
}
void MOTOR_stop()
{
    TIMER0_set_compare_value(0);
}