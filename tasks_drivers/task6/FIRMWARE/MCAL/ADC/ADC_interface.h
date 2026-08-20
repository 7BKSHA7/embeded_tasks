/**
 * @file      ADC_interface.h
 * @author    Beshoy
 * @author    Hesham Ahmed (Reviewer)
 * @brief     Interface of the ADC (Digital Input/Output) Driver.
 * @details   This file contains the function prototypes and public APIs used by 
 *            upper layers to control the direction and state of microcontroller 
 *            pins and ports.
 * @version   1.0.0
 * @date      3 August 2026
 * @copyright Copyright (c) 2026, Gestell Company
 */


#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/COMMON_MACROS.h"
#include "../REG_MAP.h"

#include "ADC_config.h"
#include "ADC_private.h"

// Adc_voltage_reference_t refrence ;
// Adc_channel_t channel;
// Adc_interput_source_t soruce;

void ADC_init(Adc_voltage_reference_t mode);
void ADC_enable();
void ADC_disable();
void ADC_adjust_direction(Adc_adjust_t direction);
void ADC_channel(Adc_channel_t channel);
void ADC_StartConversion();
void ADC_Prescaler(Adc_prescaler_t Prescaler);
void ADC_source_selection(Adc_interput_source_t source);
void ADC_auto_trigger_enable();
void ADC_auto_trigger_disable();
void ADC_interrupt_enable();
void ADC_interrupt_disable();

u16  ADC_ReadResult();

#endif
