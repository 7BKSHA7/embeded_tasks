#include <stdio.h>
#include "STD_TYPES.h"

/*
Write a C program to input any number
from user and check whether nth bit of
the given number is set (1) or not (O)
*/

int main ()
{
    u8 input = 0;
    u8 bitno = 0;
    u8 result = 0;
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
    result = (input >> bitno) & 1 ; 
    printf("the %hhd bit is %hhd" , bitno , result);
    return 0;
}
