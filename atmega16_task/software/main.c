#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/ADC/ADC_interface.h"
#include "MCAL/GIE/GIE_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
// #include <util/delay.h>

void ISR_handler();


// void main()
// {
//     Adc_config_t config_defualt_ADC = 
//     {
//         .volt_reference = Adc_defualt_VOLT_REF,
//         .adjust_direction = Adc_defualt_ADJUST,
//         .channel = Adc_defualt_CHANNEL,
//         .source = Adc_defualt_TRIGGER_SOURCE,
//         .prescaler = Adc_defualt_PRESCALER,
//     };

//     DIO_set_pin_direction(Dio_groupA,Dio_pin0,input);

//     ADC_init(config_defualt_ADC);
//     ADC_start_conversion();
//     u16 data = 0;
//     while(1)
//     {
//         data = ADC_read_result();
//     }

// }

void main()
{
    // init the pin for the led
    DIO_set_pin_direction(Dio_groupB, Dio_pin0, output);
    // init the pin for INT0
    DIO_set_pin_direction(Dio_groupD, Dio_pin2, input);

    EXTI_set_call_back(Exti_interrupt0 , ISR_handler);

    EXTI_init(Exti_interrupt0 , any_change);

    EXTI_enable(Exti_interrupt0);

    GIE_Enable();

    while(1)
    {

    }

}

void ISR_handler()
{
    DIO_tog_pin(Dio_groupB, Dio_pin0);
}