#include <stdio.h>
#include "STD_TYPES.h"

/*
Write a C program to input any two
numbers from user and swap values of
both numbers using bitwise operator,    
*/

int main ()
{
    u8 num1 = 0;
    u8 num2 = 0;

    printf("please enter first number : ");
    scanf("%hhd",&num1);
    printf("\n");
    printf("please enter 2nd number : ");
    scanf("%hhd",&num2);
    printf("\n");
    printf("after swaping : ");

    /* 
        lets says a number like 
        5 and 10
        5 - > 0 0 0 0 0 1 0 1
        10- > 0 0 0 0 1 0 1 0
        remember xor if similer its 0 if differnt then its 1
        after we xor 
        0 0 0 0 0 1 0 1 num1 old
        0 0 0 0 1 0 1 0 num2 old
        ---------------
        0 0 0 0 1 1 1 1 now that is in num 1 = 15 
        now we do it again but with num2 
        0 0 0 0 1 1 1 1 num1 new
        0 0 0 0 1 0 1 0 num2 old
        ---------------
        0 0 0 0 0 1 0 1 now thats 5 but stored in num 2

        we do it now with num1 
        0 0 0 0 1 1 1 1 num1 new
        0 0 0 0 0 1 0 1 num2 new
        ---------------
        0 0 0 0 1 0 1 0 now that 10 but stored in num 1
    */
    num1 ^= num2;
    num2 ^= num1;
    num1 ^= num2;

    printf("first number after swaping : %hhd\n" , num1);
    printf("secound number after swaping : %hhd\n" , num2);
    return 0 ;
}