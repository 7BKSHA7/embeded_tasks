#include <stdio.h>
#include "STD_TYPES.h"

/*
Write a C program to input any number
from user and find total number of
leading zeros of the given number,
*/


int main ()
{
    u8 input = 0;
    u8 counter = 0 ;
    u8 last_set_bit = 0 ;
    u8 counter_of_zeros = 0 ;
    printf("please enter a number : ");
    scanf("%hhd",&input);
    for (counter = 0 ; counter < 8 ; counter++)
    {
        if (((input >> counter) & 1) == 1)
        {
            last_set_bit = counter ;
        }
    }
    counter_of_zeros = 7 - last_set_bit;  // 7 not 8 cause the bit no 0 is not counted like that
    if (input == 0)
    {
        counter_of_zeros++;
    }
    printf("the number of leading zeros : %hhd" , counter_of_zeros);
    return 0 ;
}
