#ifndef _PIR_INTERFACE_H_
#define _PIR_INTERFACE_H_

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/COMMON_MACROS.h"

#include "PIR_config.h"
#include "PIR_private.h"

//pir task 

void PIR_init();
Pir_state_t PIR_motion_read();

#endif