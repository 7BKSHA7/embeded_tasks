#include <stdio.h>
#include "STD_TYPES.h"

/*
Write a C program to input any number
from user and find highest order set bit
of given number using bitwise operator,
*/


int main ()
{
    u8 input = 0;
    u8 last_set_bit = 0;
    u8 counter = 0 ;
    printf("please enter a number : ");
    scanf("%hhd",&input);
    while (counter < 8 )  // from 0 to 7
    {
        if (((input >> counter) & 1) == 1)
        {
            last_set_bit = counter ;
            counter++;
        }
        else 
        {
            counter++;
        }
    }
    // also can be done with for !!!! the for loop is much more effeicnt than the while loop but the while loop is eizer to read !!!
    /*  
        for (counter = 0 ; counter < 8 ; counter++)
        {
            if (((input >> counter) & 1) == 1)
            {
                last_set_bit = counter ;
            }
        }
    */
    printf("the last set bit is : %hhd" , last_set_bit);
    return 0 ;
}
