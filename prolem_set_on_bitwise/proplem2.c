#include <stdio.h>
#include "STD_TYPES.h"

/*
Write a C program to input any number
from user and check whether Most
Significant Bit (MSB) of given number is
set (1) or not (O).
*/
#define lastbit 7
int main ()
{
    u8 input = 0;
    u8 result = 0;
    printf("please enter a number : ");
    scanf("%hhd",&input);
    result = (input >> lastbit) & 1 ; // here we bitshift till we reach the final number 
    printf("the msb is %hhd" , result);
    return 0;
}
// to test it just input a negative number