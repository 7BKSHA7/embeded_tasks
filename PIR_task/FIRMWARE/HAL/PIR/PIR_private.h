#ifndef _PIR_PRIVATE_H_
#define _PIR_PRIVATE_H_


// we create pin state to reserve memory isnted of using u8  cause its only on or off
typedef enum
{
    Pir_no_motion = 0 ,
    Pir_motion_detected = 1,
}Pir_state_t;

#endif