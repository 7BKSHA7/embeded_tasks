#include "MCAL/TIMER1/TIMER1_interface.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/GIE/GIE_interface.h"
#include "HAL/ULTRASONIC/ULTRASONIC_interface.h"
#include "HAL/LCD/LCD_interface.h"
#include <util/delay.h>

static  u16 distance = 0 ;
void main()
{
    LCD_INIT(Lcd_4bitMode);
    ULTRASONIC_init();
    while(1)
    {
        distance = ULTRASONIC_get_distance();
        LCD_WriteString("Distance: ", Lcd_4bitMode);
        LCD_GoToXY(1, 0, Lcd_4bitMode);
        LCD_WriteNUMBER(distance, Lcd_4bitMode);
        LCD_WriteString("    cm", Lcd_4bitMode);
        LCD_GoToXY(0, 0, Lcd_4bitMode);
        _delay_ms(50);  
    }
}
