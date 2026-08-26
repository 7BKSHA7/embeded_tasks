#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/COMMON_MACROS.h"
#include "../REG_MAP.h"

#include "EXTI_config.h"
#include "EXTI_private.h"

void EXTI_init(u8 interrupt_name , Exti_sense_t config);
void EXTI_enable(u8 interrupt_name);
void EXTI_disable(u8 interrupt_name);

void EXTI_set_call_back(u8 interrupt_name , void (*PF)(void));


void __vector_1(void)   __attribute__((signal,used));  // interput 0 
void __vector_2(void)   __attribute__((signal,used));  // interput 1 
void __vector_18(void)  __attribute__((signal,used));  // interput 2 



#endif