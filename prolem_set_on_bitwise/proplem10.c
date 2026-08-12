#include <stdio.h>
#include "STD_TYPES.h"

/*
Write a C program to input a number
from user and flip all bits of the given
number (in binary representation) using
bitwise operator.
*/

int main ()
{
    u8 input = 0;
    printf("please enter a number : ");
    scanf("%hhd",&input);
    input = ~input; 
    printf("the number flipped  is %hhd" , input);
    return 0;
}