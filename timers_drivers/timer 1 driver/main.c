#include "timer1/TIMER_interface.h"
#include "common/GIE/GIE_Interface.h"
#include "common/lED/LED_Interface.h"
#include "common/DIO/DIO_interface.h"

// turn on a green led every 50 ms 
/*
    ok so tick time is 1uS cause 8/ 8m 
    and since its 50 ms its less than 2^16
    we do -1 cause we dont start from 0 
*/

timer1_config_t config_timer =  // timer configuration to start the timer in normal mode with prescaler 8 and preload value 100
{
    .timer_mode = Timer1_CTCMode,
    .compare_match_value = 49999,
};
void schudle();

void main()
{
    GIE_Enable();
    Led_Init(Dio_groupA , Dio_pin0 , SourceConnection);
    // Led_on(Dio_groupA , Dio_pin0);
    TIMER1_init(config_timer);
    TIMER1_start(Timer1_Prescaler8);
    TIMER1_set_call_back_fucntion(Timer1_compare_match_A_interput , schudle);
    while (1)
    {

    }
}

void schudle()
{
    static u16 counter = 0 ;
    counter++;
    if (counter == 10)
    {
        Led_off(Dio_groupA , Dio_pin0);
    }
    if (counter == 20) // every sec
    {
        Led_on(Dio_groupA , Dio_pin0);
        counter = 0 ;
    }
} 