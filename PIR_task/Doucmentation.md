# PIR motion sensor - notes

## what it does 
the pir sensor detects motion by sensing changes in the IR from a warm body 
it gives the atmega32 a signal its either HIGH or LOW 

- if its high then motion detected
- if its low then no motion detected 

**no need for ADC at all just DIO**

## good idea to use in later projects 

```c
typedef enum
{
    Pir_no_motion = 0 ,
    Pir_motion_detected = 1,
}Pir_state_t;
```

what is this ? cause isnted of raning from 0 to 255 we just 0 or 1 to save a bit of memory ..  i think

## proplem

the sensor is slow like it takes secounds to register a person but i dont know how to fix it but i think if 
i read like part of the signal like the rising edge only and not read each time its gonna lower time
also its says something in the datasheet that the timer on the board called BISS0001 it has a fucntion
**Tx = 24576 × 10K × 0.01µF ≈ 2.5s** 
so that has to do with it maybe 