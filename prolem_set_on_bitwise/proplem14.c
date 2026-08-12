#include <stdio.h>
#include "STD_TYPES.h"
/* proplem 1 
Write a C program to input any number
and check whether the given number is
even or odd using bitwise operator,
*/


int main ()
{
    u8 input = 0;
    printf("please enter a number : ");
    scanf("%hhd",&input);
    if (input & 1) // to check if the lsb is 0 or not cause all odd number have the lsb as 1 
    {
        printf("the number is odd");
    }
    else 
    {
        printf("the number is even");
    }
    return 0;
}
