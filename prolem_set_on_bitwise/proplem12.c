#include <stdio.h>
#include "STD_TYPES.h"
// not sure if its correct 
/*
Write a C program to input a number
and rotate bits of number using bitwise
shift operators
*/

/*
    ok so this means if a number like this
    1 1 1 1 0 0 0 1 
    if we rotate it right -> we move the lsb to the msb 
    so 
    1 1 1 1 1 0 0 0 
    if we retate it left we move the msb to the lsb 
    ok if store has same number
    1 1 1 1 0 0 0 1
    and we just shift right for ex
    0 1 1 1 1 0 0 0 
    we want the last one the MSB to be the LSB 
    so we read the bit of the lsb to see if its 1 or 0
    if its one we write the lsb on the update store using OR 
    if its zero we write the lsb on the update store using or too ?

*/
#define rotate_left  0
#define rotate_right 1 

int main ()
{
    u8 input = 0 ;
    u8 store_bit = 0 ;
    u8 rotate = 0 ;
    u8 no_of_rotations = 0 ;
    u8 counter = 0 ;
    printf("please enter a number : ");
    scanf("%hhd",&input);
    printf("\n");
    printf("please enter the direction of rotation : ");
    scanf("%hhd",&rotate);
    printf("\n");
    if (rotate > 1)
    {
        printf("the rotation can only be right or left\n");
        return 0;
    }
    printf("please enter the no of rotations : ");
    scanf("%hhd",&no_of_rotations);
    if (no_of_rotations > 7)
    {
        printf("the no of rotations is more than 7 which means its the same number agian\n");
        return 0;
    }
    printf("\n");
    if (rotate == rotate_right)
    {
        for (counter = no_of_rotations ; counter > 0 ; counter--)
        {
            store_bit = (input & 1);  // we store the lsb _> why and ? to get only 1 0 0 0 0 0 0 0 1 
            input = input >> 1;     // we move it by 1
            store_bit = store_bit << 7; // we move the lsb to the msb
            input = input | store_bit;  // we oring it to make sure if its 1 then 1 if 0 and 0 then its 0
        }
    }
    else if (rotate == rotate_left)
    {
        for (counter = no_of_rotations ; counter > 0 ; counter--)
        {
            store_bit = (input >> 7) & 1 ;  // we store the msb
            input = input << 1;     // we move it by 1
            input = input | store_bit;  // we oring it to make sure if its 1 then 1 if 0 and 0 then its 0
        }
    }
    printf("the number after %hhd rotation is : %hhd", no_of_rotations ,input);        
}