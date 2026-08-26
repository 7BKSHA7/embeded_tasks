#ifndef _PRIVATE_INTERFACE_H_
#define _PRIVATE_INTERFACE_H_

// there are 3 interputs in the EXTI int 0 , 1 , 2 

// MCUCR

// sense control bits for int 1
#define Exti_ISC11 3
#define Exti_ISC10 2 

// sense control bits for int 0 
#define Exti_ISC01 1 
#define Exti_ISC00 0 

// sense control bit for int 2 
#define Exti_ISC2  6 

// states of sense control

typedef enum
{
    low_level = 0 ,
    any_change,
    falling,
    rising,

}Exti_sense_t;

// GICR 

// External Interrupt Request 1 Enable
#define Exti_INT1  7 // if set to 1 and the I bit is also set the pin is enabled 

// External Interrupt Request 0 Enable  
#define Exti_INT0  6 

// External Interrupt Request 2 Enable
#define Exti_INT2  5

// GIFR

// External Interrupt Flag 1
#define Exti_INTF1  7 

// External Interrupt Flag 0
#define Exti_INTF0  6

// External Interrupt Flag 2
#define Exti_INTF2  5


#define Exti_interrupt0    0 
#define Exti_interrupt1    1 
#define Exti_interrupt2    2 



#endif