/**
 * @file      ADC_program.c
 * @author    Beshoy
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Implementation of the ADC (Digital Input/Output) Driver.
 * @details   This file contains the implementation of functions to control the 
 *            direction and value of individual pins and entire ports (groups) 
 *            on the microcontroller. Includes defensive checks for valid inputs.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */

#include "ADC_interface.h"

void ADC_init(Adc_voltage_reference_t reference)
{
    switch (reference)
    {
        case AREF : 
            ClearBit(ADMUX,Adc_REFS0 );
            ClearBit(ADMUX,Adc_REFS1 );
            break;
        case AVCC :
            SetBit(ADMUX,Adc_REFS0 );
            ClearBit(ADMUX,Adc_REFS1 );
            break;
        case INTERNAL :
            SetBit(ADMUX,Adc_REFS0 );
            SetBit(ADMUX,Adc_REFS1 );
            break;
        default: 
            break;  
        }
        ADC_Prescaler(Adc_prescaler_64);
        ADC_enable();
}

void ADC_enable()
{
    SetBit(ADCSRA ,Adc_ADEN );
}

void ADC_disable()
{
    ClearBit(ADCSRA ,Adc_ADEN );
}

static u8 direction_of_adjust = 0 ;
void ADC_adjust_direction(Adc_adjust_t direction)
{
    switch (direction)
    {
        case Adc_left_adjust :
            SetBit(ADMUX,Adc_ADlAR);
            direction_of_adjust = 1 ;
            break;
        case Adc_right_adjust :
            ClearBit(ADMUX,Adc_ADlAR);
            direction_of_adjust = 0 ;
            break;  
        default :
            break;
    }
}

void ADC_StartConversion()
{
    SetBit(ADCSRA , Adc_ADSC) ;
}

void ADC_channel(Adc_channel_t channel)
{
    ADMUX = (ADMUX &~ Adc_mask_channel) | channel ; 
}

void ADC_Prescaler(Adc_prescaler_t Prescaler)
{
    ADCSRA = (ADCSRA &~ Adc_mask_prescaler) | Prescaler ;
}

void ADC_source_selection(Adc_interput_source_t source)
{
    SFIOR = (SFIOR &~ Adc_mask_interput_sources) | source ;
}

u16 ADC_ReadResult()
{
    u16 data = 0;

    ADC_StartConversion();

    while (ReadBit(ADCSRA, Adc_ADIF) == 0);

    SetBit(ADCSRA, Adc_ADIF);

    if (direction_of_adjust == Adc_right_adjust)
    {
        data = ADCL;
        data |= ((u16)ADCH << 8);
    }
    else
    {
        data = ((u16)ADCH << 2);
        data |= (ADCL >> 6);
    }

    return data;
}


void ADC_auto_trigger_enable()
{
    SetBit(ADCSRA, Adc_ADATE);
}

void ADC_auto_trigger_disable()
{
    ClearBit(ADCSRA, Adc_ADATE);
}

void ADC_interrupt_enable()
{
    SetBit(ADCSRA, Adc_ADIE);
}

void ADC_interrupt_disable()
{
    ClearBit(ADCSRA, Adc_ADIE);
}