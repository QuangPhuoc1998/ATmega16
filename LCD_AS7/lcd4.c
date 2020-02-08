
#include "main.h"
#include "lcd4.h"



void Lcd_Port(char a)
{
	if(a & 1)
		(1 << D4);
	else
		(0 << D4);

	if(a & 2)
		(1 << D5);
	else
		(0 << D5);

	if(a & 4)
		(1 << D6);
	else
		(0 << D6);

	if(a & 8)
		(1 << D7);
	else
		(0 << D7);
}
void Lcd_Cmd(char a)
{
	(0 << RS);             // => RS = 0
	Lcd_Port(a);
	(1 << EN);             // => E = 1
    _delay_ms(4);
    (0 << EN);;             // => E = 0
}

void Lcd_Clear()
{
	Lcd_Cmd(0);
	Lcd_Cmd(1);
}

void Lcd_Set_Cursor(char a, char b)
{
	char temp,z,y;
	if(a == 1)
	{
	  temp = 0x80 + b - 1;
		z = temp>>4;
		y = temp & 0x0F;
		Lcd_Cmd(z);
		Lcd_Cmd(y);
	}
	else if(a == 2)
	{
		temp = 0xC0 + b - 1;
		z = temp>>4;
		y = temp & 0x0F;
		Lcd_Cmd(z);
		Lcd_Cmd(y);
	}
}

void Lcd_Init()
{
  Lcd_Port(0x00);
  _delay_ms(20);
  Lcd_Cmd(0x03);
  _delay_ms(5);
  Lcd_Cmd(0x03);
  _delay_ms(11);
  Lcd_Cmd(0x03);
  /////////////////////////////////////////////////////
  Lcd_Cmd(0x02);
  Lcd_Cmd(0x02);
  Lcd_Cmd(0x08);
  Lcd_Cmd(0x00);
  Lcd_Cmd(0x0C);
  Lcd_Cmd(0x00);
  Lcd_Cmd(0x06);
}

void Lcd_Write_Char(char a)
{
   char temp,y;
   temp = a&0x0F;
   y = a&0xF0;
   (1 << RS);             // => RS = 1
   Lcd_Port(y>>4);             //Data transfer
   (1 << EN);
   _delay_us(40);
   (0 << EN);
   Lcd_Port(temp);
   (1 << EN);
   _delay_us(40);
   (0 << EN);
}

void Lcd_Write_String(char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++)
	   Lcd_Write_Char(a[i]);
}

void Lcd_Shift_Right()
{
	Lcd_Cmd(0x01);
	Lcd_Cmd(0x0C);
}

void Lcd_Shift_Left()
{
	Lcd_Cmd(0x01);
	Lcd_Cmd(0x08);
}

