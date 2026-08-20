#include"LED_Interface.h"

static u8 StaticConnectionType = 0 ; 
void Led_Init(u8 GroupName , u8 PinNumber,u8 ConnectionType)
{
    DIO_set_pin_direction(GroupName,PinNumber,output);
    StaticConnectionType=ConnectionType;
}

/* leave for later but fix
// void Led_on(u8 GroupName , u8 PinNumber )
// {
//     if(StaticConnectionType==SourceConnection)
//         {
//             DIO_WritePin(GroupName,PinNumber,high);
//         }
//         else if (StaticConnectionType==SinkConnection)
//         {
//             DIO_WritePin(GroupName,PinNumber,low);
 
//         }

// }

// void Led_off(u8 GroupName , u8 PinNumber)
// {

//     if(StaticConnectionType==SourceConnection)
//         {
//             DIO_WritePin(GroupName,PinNumber,low);
//         }
//         else if (StaticConnectionType==SinkConnection)
//         {
//             DIO_WritePin(GroupName,PinNumber,high);
//         }

// }
*/

void Led_Toggle(u8 GroupName , u8 PinNumber)
{
    DIO_tog_pin(GroupName,PinNumber);
}
