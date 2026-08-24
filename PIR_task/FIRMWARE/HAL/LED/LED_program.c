#include "LED_interface.h"

void LED_init()
{
    DIO_set_pin_direction(Led_group, Led_pin , output);
    DIO_set_pin_value(Led_group, Led_pin , low);
}
void LED_on()
{
    DIO_set_pin_value(Led_group, Led_pin , high);
}
void LED_off()
{
    DIO_set_pin_value(Led_group, Led_pin , low);
}
void LED_toggle()
{
    DIO_tog_pin(Led_group, Led_pin);
}
