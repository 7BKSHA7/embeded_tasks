#include <stdio.h>
#include "STD_TYPES.h"

/*
Write a C program to input any number
from user and find lowest order set bit
of given number using bitwise operator,
*/


int main ()
{
    u8 input = 0;
    u8 first_set_bit = 0;
    u8 counter = 0 ;
    printf("please enter a number : ");
    scanf("%hhd",&input);
    for (counter = 0 ; counter < 8 ; counter++)
    {
        if (((input >> counter) & 1) == 1)
        {
            first_set_bit = counter ;
            break; // cause if we find it we just exit the loop
        }
    }

    printf("the first set bit is : %hhd" , first_set_bit);
    return 0 ;
}
