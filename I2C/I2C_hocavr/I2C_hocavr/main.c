#include "main.h"
#include "I2C.h"
#include "LCD_I2C.h"


int main(void)
{
	I2C_Init();
	//
	Lcd_Init();
	Lcd_Write_String("PHAM QUANG PHUOC");	
	Lcd_Set_Cursor(2,1);	
	Lcd_Write_String("TU DONG HOA - 57");	
	while(1)
	{
		
	}
}
