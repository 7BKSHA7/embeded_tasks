#include "PIR_interface.h"

void PIR_init()
{
    DIO_set_pin_direction(Pir_group,Pir_pin,input);
}
Pir_state_t PIR_motion_read()
{
    u8 pin_state = 0 ;
    pin_state = DIO_get_pin_value(Pir_group,Pir_pin);
    return (Pir_state_t)pin_state; // we must cast it to not createa a bug 
}
