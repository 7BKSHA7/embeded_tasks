#include "EXTI_interface.h"

static void (*INT0_call_back)(void) = Null;
static void (*INT1_call_back)(void) = Null;
static void (*INT2_call_back)(void) = Null;

void EXTI_init(u8 interrupt_name , Exti_sense_t config)
{
    if (interrupt_name < 3 && config < 4)
    {
        if (interrupt_name == Exti_interrupt0)
        {
            if(config == low_level)
            {
                ClearBit(MCUCR , Exti_ISC00);
                ClearBit(MCUCR , Exti_ISC01);
            }
            else if (config == any_change)
            {
                SetBit(MCUCR , Exti_ISC00);
                ClearBit(MCUCR , Exti_ISC01);   
            }
            else if (config == falling)
            {
                ClearBit(MCUCR , Exti_ISC00);
                SetBit(MCUCR , Exti_ISC01);   
            }
            else if (config == rising)
            {
                SetBit(MCUCR , Exti_ISC00);
                SetBit(MCUCR , Exti_ISC01);
            }
        }
        else if (interrupt_name == Exti_interrupt1)
        {
            if(config == low_level)
            {
                ClearBit(MCUCR , Exti_ISC10);
                ClearBit(MCUCR , Exti_ISC11);
            }
            else if (config == any_change)
            {
                SetBit(MCUCR , Exti_ISC10);
                ClearBit(MCUCR , Exti_ISC11);   
            }
            else if (config == falling)
            {
                ClearBit(MCUCR , Exti_ISC10);
                SetBit(MCUCR , Exti_ISC11);   
            }
            else if (config == rising)
            {
                SetBit(MCUCR , Exti_ISC10);
                SetBit(MCUCR , Exti_ISC11);
            }
        }
        else if (interrupt_name == Exti_interrupt2)
        {
            if (config == falling)
            {
                ClearBit(MCUCSR,Exti_ISC2);
            }
            else if (config == rising)
            {
                SetBit(MCUCSR,Exti_ISC2);
            }
        }
    }
}
void EXTI_enable(u8 interrupt_name)
{
    if (interrupt_name < 3)
    {
        if(interrupt_name==Exti_interrupt0)
        {
            SetBit(GICR , Exti_INT0);
        }
        else if(interrupt_name==Exti_interrupt1)
        {
            SetBit(GICR , Exti_INT1);
        }
        else if(interrupt_name==Exti_interrupt2)
        {
            SetBit(GICR , Exti_INT2);
        }
    }
}
void EXTI_disable(u8 interrupt_name)
{
    if (interrupt_name < 3)
    {
        if(interrupt_name==Exti_interrupt0)
        {
            ClearBit(GICR , Exti_INT0);
        }
        else if(interrupt_name==Exti_interrupt1)
        {
            ClearBit(GICR , Exti_INT1);
        }
        else if(interrupt_name==Exti_interrupt2)
        {
            ClearBit(GICR , Exti_INT2);
        }
    }
}
void EXTI_set_call_back(u8 interrupt_name , void (*PF)(void))
{
    if(interrupt_name==Exti_interrupt0)
    {
        if ( PF != Null)
        {
            INT0_call_back = PF;
        }
    }
    else if(interrupt_name==Exti_interrupt1)
    {
        if ( PF != Null)
        {
            INT1_call_back = PF;
        }
    }
    else if(interrupt_name==Exti_interrupt2)
    {
        if ( PF != Null)
        {
            INT2_call_back = PF;
        }
    }
}

void __vector_1(void)
{
    if( INT0_call_back != Null)
    {
        INT0_call_back();
    }
}
void __vector_2(void)
{
    if( INT1_call_back != Null)
    {
        INT1_call_back();
    }
}
void __vector_18(void)
{
    if( INT2_call_back != Null)
    {
        INT2_call_back();
    }
}