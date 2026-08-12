#include <stdio.h>
#include "STD_TYPES.h"

/*
Write a C program to input any number
from user and set nth bit of the given
number as 1,
#define SetBit(reg, bitno)         ((reg) |=  (1 << (bitno)))   // to make it 1
*/

int main ()
{
    u8 input = 0;
    u8 bitno = 0;
    printf("please enter a number : ");
    scanf("%hhd",&input);
    printf("\n");
    printf("please enter the bit number : ");
    scanf("%hhd",&bitno);
    if (bitno >= 8)
    {
        printf("bit no cant be higher than 8 ");
        return 0;
    }
    printf("the number before setting : %hhd" , input);
    printf("\n");
    input |= (1 << bitno) ; 
    printf("the number after setting : %hhd" , input);

    return 0;
}
