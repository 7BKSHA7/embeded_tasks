#ifndef _TIMER1_INTERFACE_H_
#define _TIMER1_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/COMMON_MACROS.h"
#include "../REG_MAP.h"
#include "TIMER1_config.h"
#include "TIMER1_private.h"

void TIMER1_init(timer1_config_t config);
void TIMER1_start(u8 clock_select_value);
void TIMER1_stop(void);
void TIMER1_set_preload (u16 preload_value);
void TIMER1_set_compare_match (u16 compare_match_value);

u16  TIMER1_get_input_capture_value(void);
void TIMER1_disable_input_capture_interrupt(void);
void TIMER1_enable_input_capture_interrupt(void);
void TIMER1_set_input_capture_edge(u8 edge);

void TIMER1_set_call_back_fucntion (u8 timer_interupt_type , void (*PF)(void));

void __vector_7(void)   __attribute__((signal,used));
void __vector_6(void)   __attribute__((signal,used));
void __vector_8(void)   __attribute__((signal,used));
void __vector_9(void)   __attribute__((signal,used));


#endif
