#include <stdio.h>
#include "STD_TYPES.h"
/* proplem 1 
Write a C program to input any number
from user and check whether the Least
Significant Bit (LSB) of the given number
is set (1) or not (O).
*/

/*
    first we take in the input from the user 
    like in the bit math file the read bit is 
    #define ReadBit(reg, bitno)        (((reg) >> (bitno)) & 1)
*/

int main ()
{
    u8 input = 0;
    u8 result = 0;
    printf("please enter a number : ");
    scanf("%hhd",&input);
    result = input & 1 ; // here we dont need to bitshift cause its the first bit anyway 
    printf("the lsb is %hhd" , result);
    return 0;
}

// cause i forgot to compilet the code we do gcc <name> then we do ./a.exe
// and to go into the folder just do cd <name_of_folder> like cd prolem_set_on_bitwise