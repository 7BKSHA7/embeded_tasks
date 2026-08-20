#ifndef _PET_INTERFACE_H_
#define _PET_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/COMMON_MACROS.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/ADC/ADC_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "PET_config.h"
#include "PET_private.h"

void POT_init();

u16 POT_read_value();

#endif