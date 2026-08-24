#include "MCAL/DIO/DIO_interface.h"
#include "HAL/PIR/PIR_interface.h"
#include "HAL/LED/LED_Interface.h"
// #include <util/delay.h>
void main()
{
    LED_init();
    PIR_init();
    u8 state = 0;
    while(1)
    {
        state = PIR_motion_read();
        if (state == true)
        {
            LED_on();
        }
        else 
        {
            LED_off();
        }
    }
}