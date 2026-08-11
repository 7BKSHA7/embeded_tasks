#include"LED_Interface.h"

static u8 StaticConnectionType = 0 ; 
void Led_Init(u8 GroupName , u8 PinNumber,u8 ConnectionType)
{
    DIO_set_pin_direction(GroupName,PinNumber,output);
    StaticConnectionType=ConnectionType;
}

void Led_on(u8 GroupName , u8 PinNumber )
{
    if(StaticConnectionType==SourceConnection)
    {
        DIO_set_pin_value(GroupName,PinNumber,high);
    }
    else if (StaticConnectionType==SinkConnection)
    {
        DIO_set_pin_value(GroupName,PinNumber,low);
    }
}

void Led_off(u8 GroupName , u8 PinNumber)
{

    if(StaticConnectionType==SourceConnection)
        {
            DIO_set_pin_value(GroupName,PinNumber,low);
        }
        else if (StaticConnectionType==SinkConnection)
        {
            DIO_set_pin_value(GroupName,PinNumber,high);
        }

}


