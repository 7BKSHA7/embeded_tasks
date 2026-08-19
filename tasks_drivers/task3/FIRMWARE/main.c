#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TIMER0/TIMER0_interface.h"
#include "HAL/PET/PET_interface.h"
#include "HAl/LED/LED_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"

void schulder ();
#define preload_value_of_1sec   192
#define _1_sec_  3907
void main()
{
    Timer0_config_t config_main_t =
    {
        .timer_mode = Timer0_normal,
        .presacler = clk_8,
        .preload_value = preload_value_of_1sec,
    };

    Led_Init(Dio_groupB, Dio_pin3, SinkConnection);
    TIMER0_init(config_main_t);
    TIMER0_start(config_main_t);
    TIMER0_set_call_back_fucntion(Timer0_overflow_interput , schulder);
    GIE_Enable();

    while(1)
    {

    }

}
/*
    to calualte each secound
    tick 8 / 8M
    1uS
    and we do 1uS * 256 
    then its 256uS  
    we do 
    1 M <- that is 1 sec
    1 000 000 / 256
    = 3906.25
    so we count up to 3907
    and set a preload of 256 * (1-0.y)
    so its 192 
*/
void schulder ()
{
    static u16 count = 0 ;
    count ++ ;
    if (count == _1_sec_)
    {
        Led_Toggle(Dio_groupB , Dio_pin3);
        TIMER0_set_preload(preload_value_of_1sec);
        count = 0 ;
    }

}
