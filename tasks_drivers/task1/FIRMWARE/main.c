#include "MCAL/DIO/DIO_interface.h"
#include <util/delay.h>
void main()
{
    DIO_set_pin_direction(Dio_groupA,Dio_pin0,output);
    while(1)
    {
        DIO_tog_pin(Dio_groupA , Dio_pin0);
        _delay_ms(500);
    }

}