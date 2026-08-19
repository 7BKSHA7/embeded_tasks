#include "PET_interface.h"

void PET_init()
{
    DIO_set_pin_direction(POT_Port,POT_Pin,input);
      
    ADC_init(AVCC);
    ADC_adjust_direction(Adc_right_adjust);

}

u16 PET_read_value()
{
    u16 local_pot_value = 0;
    ADC_channel(Adc_channel_0);
    local_pot_value = ADC_ReadResult();

    return local_pot_value;
}