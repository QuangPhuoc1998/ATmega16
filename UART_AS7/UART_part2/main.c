/*
 * UART_part2.c
 *
 * Created: 30/04/2019 11:26:06
 * Author : ADMIN
 */ 

#define RS eS_PORTC0
#define EN eS_PORTC1
#define D4 eS_PORTC2
#define D5 eS_PORTC3
#define D6 eS_PORTC4
#define D7 eS_PORTC5

#include "main.h"
#include "UART.h"
#include "lcd.h"
#include "avr/interrupt.h"

unsigned char u;
char data[8];
unsigned int x_value, y_value;
void Lcd_Display(unsigned int x, unsigned int y);
int main(void)
{
    //unsigned char a;
    // port
	DDRC = 0xFF;
	sbi(DDRA, PA0);
	// chuong trinh con
	UART_init(9600);
	Lcd4_Init();
	sei();
	// begin
	Lcd4_Write_String("x = ");
	Lcd4_Set_Cursor(2,0);
	Lcd4_Write_String("y = ");
    while (1) 
    {
	  Lcd_Display(x_value, y_value);
    }
}
void Lcd_Display(unsigned int x, unsigned int y)
{
	Lcd4_Set_Cursor(1, 4);
	Lcd4_Write_Char(x/1000+48);
	Lcd4_Write_Char((x%1000)/100+48);
	Lcd4_Write_Char((x%100)/10+48);
	Lcd4_Write_Char(x%10+48);

	Lcd4_Set_Cursor(2, 4);
	Lcd4_Write_Char(y/1000+48);
	Lcd4_Write_Char((y%1000)/100+48);
	Lcd4_Write_Char((y%100)/10+48);
	Lcd4_Write_Char(y%10+48);
}
ISR (USART_RXC_vect)
{
  u = UDR;
  if(u == ':')
  {
    UART_Read_Text(data, 8);
	x_value = data[0]*1000+data[1]*100+data[2]*10+data[3];
	y_value = data[4]*1000+data[5]*100+data[6]*10+data[7];
  }
}

