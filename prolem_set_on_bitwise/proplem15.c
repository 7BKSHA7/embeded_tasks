#include <stdio.h>
#include "STD_TYPES.h"
/* proplem 1 
Write a C program to input any decimal
number from user and convert it to
binary number system using bitwise
operator.
*/


int main ()
{
    u8 input = 0;
    s8 counter = 0 ;
    u8 bit = 0 ;
    printf("please enter a number : ");
    scanf("%hhd",&input);
    for (counter = 7 ; counter >= 0 ; counter --)
    {
        bit = (input >> counter) & 1;  
        printf ("%hhd" , bit);
        // if (counter == 0)  // this used if the counter is u8 but cause its s8 now we just check if its 0 not less
        // {
        //     break;
        // }
    }
    return 0;
}
