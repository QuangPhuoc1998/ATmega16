#include "main.h"
#include "My_LCD.h"

void Lcd_Port(char a)
{
	(a&1)? sbi(PORT_Data, D4) : cbi(PORT_Data, D4);
	(a&2)? sbi(PORT_Data, D5) : cbi(PORT_Data, D5);
	(a&4)? sbi(PORT_Data, D6) : cbi(PORT_Data, D6);
	(a&8)? sbi(PORT_Data, D7) : cbi(PORT_Data, D7);
}
void Lcd_cmd(char a)
{
	cbi(PORT_RS, RS);
	Lcd_Port(a);
	sbi(PORT_EN, EN);
	_delay_ms(5);
	cbi(PORT_EN, EN);
	_delay_ms(1);
}
void Lcd_Init()
{
	/*------PIN------*/
	sbi(DDR_RS, RS);
	sbi(DDR_EN, EN);
	sbi(DDR_Data, D7);
	sbi(DDR_Data, D6);
	sbi(DDR_Data, D5);
	sbi(DDR_Data, D4);
	/*------------*/
	Lcd_Port(0x00);
	_delay_ms(15);
	/*------------*/
	Lcd_cmd(0x03);
	_delay_ms(5);
	Lcd_cmd(0x03);
	_delay_ms(11); /*--- ? ---*/
	Lcd_cmd(0x03);
	/*---------*/
	Lcd_cmd(0x02);
	Lcd_cmd(0x02);
	Lcd_cmd(0x08);
	Lcd_cmd(0x00);
	Lcd_cmd(0x08);
	Lcd_cmd(0x00);
	Lcd_cmd(0x0C);
	Lcd_cmd(0x00);
	Lcd_cmd(0x06);
}
void Lcd_Write_Char(char a)
{
	
	char temp,y;
	temp = a&0x0F;
	y = a&0xF0;
	sbi(PORT_RS,RS);             // => RS = 1
	Lcd_Port(y>>4);             //Data transfer
	sbi(PORT_EN, EN);
	_delay_ms(1);
	cbi(PORT_EN, EN);
	_delay_ms(1);
	Lcd_Port(temp);
	sbi(PORT_EN, EN);
	_delay_ms(1);
	cbi(PORT_EN, EN);
	_delay_ms(1);
}
void Lcd_Write_String(char *a)
{
	for(int i=0;a[i] != '\0';i++)
	Lcd_Write_Char(a[i]);
}
void Lcd_Set_Cursor(char a, char b)
{
	char temp,z,y;
	if(a == 1)
	{
		temp = 0x80 + b;
		z = temp>>4;
		y = (0x80+b) & 0x0F;
		Lcd_cmd(z);
		Lcd_cmd(y);
	}
	else if(a == 2)
	{
		temp = 0xC0 + b;
		z = temp>>4;
		y = (0xC0+b) & 0x0F;
		Lcd_cmd(z);
		Lcd_cmd(y);
	}
}
void Lcd4_Shift_Right()
{
	Lcd_cmd(0x01);
	Lcd_cmd(0x0C);
}

void Lcd4_Shift_Left()
{
	Lcd_cmd(0x01);
	Lcd_cmd(0x08);
}