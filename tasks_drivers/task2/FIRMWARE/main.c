#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TIMER0/TIMER0_interface.h"
#include "HAL/PET/PET_interface.h"
#include "HAl/LED/LED_Interface.h"

#include <util/delay.h>
void main()
{
    Timer0_config_t config_main_t =
    {
        .timer_mode = Timer0_PWM_fast,
        .presacler = clk_8,
        .preload_value = 0,
        .compare_match_value = 0,
        .compare_output_mode = Timer0_COM_inverting,
    };

    Led_Init(Dio_groupB, Dio_pin3, SinkConnection);
    TIMER0_init(config_main_t);
    TIMER0_start(config_main_t);
    PET_init();

    while(1)
    {
        u16 pot_value = PET_read_value();
        u8 duty_cycle =(u8)(((u32)pot_value * 100UL) / 1023UL);  // inverted
        TIMER0_set_duty_cycle(duty_cycle);
    }

}