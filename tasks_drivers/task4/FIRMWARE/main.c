#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TIMER0/TIMER0_interface.h"
#include "HAL/PET/PET_interface.h"
#include "HAl/LED/LED_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"

void main()
{
    Led_Init(Dio_groupB, Dio_pin3, SourceConnection);
    GIE_Enable();
    DIO_set_pin_direction(Dio_groupD , Dio_pin2 , input);
    u8 sensor_state = 0 ;
    while(1)
    {
        sensor_state = DIO_get_pin_value(Dio_groupD , Dio_pin2);
        if (sensor_state == high)
        {
            DIO_set_pin_value(Dio_groupB, Dio_pin3 , high);
        }
        else if (sensor_state == low)
        {
            DIO_set_pin_value(Dio_groupB, Dio_pin3 , low);
        }
    }

}

