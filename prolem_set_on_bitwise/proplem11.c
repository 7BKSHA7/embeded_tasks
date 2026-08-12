#include <stdio.h>
#include "STD_TYPES.h"

/*
Write a C program to input a number
from user and count total number of
ones (Is) and zeros (Os) 
*/

int main ()
{
    u8 input = 0;
    u8 counter = 0 ;
    u8 no_of_zeros = 0 ;
    u8 no_of_ones = 0 ;
    printf("please enter a number : ");
    scanf("%hhd",&input);
    for (counter = 0 ; counter < 8 ; counter++)
    {
        if (((input >> counter) & 1) == 1)
        {
            no_of_ones++;
        }
        else 
        {
            no_of_zeros++;
        }
    }
    printf("the number zeros is %hhd" , no_of_zeros);
    printf("\n");
    printf("the number ones is %hhd" , no_of_ones);
    return 0;
}