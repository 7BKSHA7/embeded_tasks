#include <stdio.h>
#include "STD_TYPES.h"

/*
Write a C program to input any number
from user and count number of trailing
zeros in the given number using bitwise
operator
*/


int main ()
{
    u8 input = 0;
    u8 counter = 0 ;
    u8 counter_of_zeros = 0 ;
    printf("please enter a number : ");
    scanf("%hhd",&input);
    for (counter = 0 ; counter < 8 ; counter++)
    {
        if (((input >> counter) & 1) == 1)
        {
            break; // cause if we find it we just exit the loop
        }
        else 
        {
            counter_of_zeros++;
        }
    }

    printf("the number of traling zeros : %hhd" , counter_of_zeros);
    return 0 ;
}
