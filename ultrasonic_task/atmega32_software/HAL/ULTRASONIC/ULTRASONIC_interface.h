#ifndef _ULTRASONIC_INTERFACE_H_
#define _ULTRASONIC_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/COMMON_MACROS.h"

#include "ULTRASONIC_private.h"
#include "ULTRASONIC_config.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMER1/TIMER1_interface.h"
#include "../../MCAL/GIE/GIE_interface.h"

void ULTRASONIC_init(void);
void ULTRASONIC_trigger(void);
u16  ULTRASONIC_get_pulse_width(void);
u16  ULTRASONIC_get_distance(void);


#endif