#ifndef _REG_MAP_H_
#define _REG_MAP_H_

#include "../LIB/STD_TYPES.h"

#define SREG           *((volatile u8*)0x5F)

#define MCUCR          *((volatile u8*)0x55)
#define MCUCSR         *((volatile u8*)0x54)

#define GICR           *((volatile u8*)0x5B)
#define GIFR           *((volatile u8*)0x5A)

// gorup A
#define DDRA           *((volatile u8*)0x3A)
#define PORTA          *((volatile u8*)0x3B)
#define PINA           *((volatile u8*)0x39)
// gorup B
#define DDRB           *((volatile u8*)0x37)
#define PORTB          *((volatile u8*)0x38)
#define PINB           *((volatile u8*)0x36)
// gorup C
#define DDRC           *((volatile u8*)0x34)
#define PORTC          *((volatile u8*)0x35)
#define PINC           *((volatile u8*)0x33)
// gorup D
#define DDRD           *((volatile u8*)0x31)
#define PORTD          *((volatile u8*)0x32)
#define PIND           *((volatile u8*)0x30)


#define ADMUX          *((volatile u8*)0x27)

#define ADCSRA         *((volatile u8*)0x26)


#define ADCH           *((volatile u8*)0x25)
#define ADCL           *((volatile u8*)0x24)


#define SFIOR          *((volatile u8*)0x50)


// #define TCCR0          *((volatile u8*)0x53)
// #define TCNT0          *((volatile u8*)0x52)
// #define OCR0           *((volatile u8*)0x5C)
// #define TIMSK          *((volatile u8*)0x59)
// #define TIFR           *((volatile u8*)0x58)

// #define UDR           *((volatile u8*)0x2C)
// #define UCSRA         *((volatile u8*)0x2B)
// #define UCSRB         *((volatile u8*)0x2A)
// #define UCSRC         *((volatile u8*)0x40)
// #define UBRRL         *((volatile u8*)0x29)
// #define UBRRH         *((volatile u8*)0x40)


#endif 