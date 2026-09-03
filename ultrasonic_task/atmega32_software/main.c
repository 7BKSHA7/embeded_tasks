#include "MCAL/TIMER1/TIMER1_interface.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/GIE/GIE_interface.h"
#include "HAL/ULTRASONIC/ULTRASONIC_interface.h"
#include <util/delay.h>

static volatile u16 distance = 0 ;
void main()
{
    DIO_set_group_direction(Dio_groupC)
    ULTRASONIC_init();
    while(1)
    {
        ULTRASONIC_trigger();
        _delay_ms(50);
        distance = ULTRASONIC_get_distance();

    }
}
