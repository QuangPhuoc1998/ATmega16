#include "main.h"
#include "I2C.h"
#include "LCD_I2C.h"


#define CLK 1
#define Da 0
#define PORT PORTB
int32_t ReadCount()        /* Function to read measurement from HX711 */
{
	int32_t Count = 0;
	uint8_t i;
	sbi(PORT,Da);
	cbi(PORT,CLK);                    /* Clear Clock line to start conversion */
	Count = 0;
	while(bit_is_set(PINB, Da));      /* Wait for measurement conversion. */
	for (i=0; i<24; i++)
	{
		sbi(PORT,CLK);           /* Clock signal High */
		Count = Count << 1;       /* Shift value left */
		_delay_us(10);
		cbi(PORT,CLK);            /* Clock signal Low */
		if(bit_is_set(PINB, Da)) Count++;
		_delay_us(10);
	}
	sbi(PORT,CLK); 
	Count=Count^0x800000;
	_delay_us(10);
	cbi(PORT,CLK);
	return Count;
} 
int main(void)
{
	//
	int32_t data;
	// char buffer[20];
	//
	cbi(DDRB,0);
	sbi(DDRB,1);
	sbi(DDRB,2);
	//
    I2C_Init();
	Lcd_Init();
	//
	Lcd_Write_String("khoi luong: ");
	Lcd_Set_Cursor(4,10);
	Lcd_Write_String("Gram");
    while (1) 
    {
		data = (ReadCount()-8586000)/7.95526;
		if(data < 0) data = 0;
		Lcd_Set_Cursor(2,1);
		Lcd_Write_Char(data%10000000/1000000+48);
		Lcd_Write_Char(data%1000000/100000+48);
		Lcd_Write_Char(data%100000/10000+48);
		Lcd_Write_Char(data%10000/1000+48);
		Lcd_Write_Char(data%1000/100+48);
		Lcd_Write_Char('.');
		Lcd_Write_Char(data%100/10+48);
	    Lcd_Write_Char(data%10+48);
		_delay_ms(500);
    }
}

