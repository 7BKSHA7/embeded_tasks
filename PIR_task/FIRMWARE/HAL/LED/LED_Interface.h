#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/COMMON_MACROS.h"

#include "LED_config.h"
#include "LED_private.h"

#include "../../MCAL/DIO/DIO_interface.h"

void LED_init();
void LED_on();
void LED_off();
void LED_toggle();

#endif
