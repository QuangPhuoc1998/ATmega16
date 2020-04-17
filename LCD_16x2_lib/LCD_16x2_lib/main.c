#include "main.h"
#include "My_LCD.h"

int main(void)
{
	Lcd_Init();
	Lcd_Set_Cursor(1,1);
	Lcd_Write_String("PHUOC");
	Lcd_Set_Cursor(2,1);
	Lcd_Write_String("PHUOC");
    while (1) 
    {

    }
}

