#include "main.h"
#include "I2C.h"
#include "LCD_I2C.h"

void Lcd_Write_Char(unsigned char data)
{
	unsigned char data_l, data_u;
	data_l = (data<<4)&0xf0;  //select lower nibble by moving it to the upper nibble position
	data_u = data&0xf0;  //select upper nibble
	
	I2C_Start(Address_PCF8574);
	I2C_Write(data_u|0x0D);  //enable=1 and rs =1
	_delay_ms(2);
	I2C_Write(data_u|0x09);  //enable=0 and rs =1
	_delay_ms(2);
	I2C_Write(data_l|0x0D);  //enable =1 and rs =1
	_delay_ms(2);
	I2C_Write(data_l|0x09);  //enable=0 and rs =1
	I2C_Stop();
}
void lcd_send_cmd(unsigned char data)
{
	unsigned char data_l, data_u;
	data_l = (data<<4)&0xf0;  //select lower nibble by moving it to the upper nibble position
	data_u = data&0xf0;  //select upper nibble

	I2C_Start(Address_PCF8574);
	I2C_Write(data_u|0x0C);  //enable=1 and rs =0
	_delay_ms(2);
	I2C_Write(data_u|0x08);  //enable=0 and rs =0
	_delay_ms(2);
	I2C_Write(data_l|0x0C);  //enable =1 and rs =0
	_delay_ms(2);
	I2C_Write(data_l|0x08);  //enable=0 and rs =0
	I2C_Stop();
}
void Lcd_Clear()
{
	lcd_send_cmd(0);
	_delay_ms(2);
	lcd_send_cmd(1);
	_delay_ms(2);
}
void Lcd_Init()
{
	lcd_send_cmd(0x02);
	_delay_ms(2);
	lcd_send_cmd(0x28);
	_delay_ms(1);
	lcd_send_cmd(0x0c);
	_delay_ms(1);
	lcd_send_cmd(0x80);
	_delay_ms(1);
	lcd_send_cmd(0x01);
	_delay_ms(2);
}
void Lcd_Write_String(char *str)
{
	int i;
	for(i=0;str[i]!='\0';i++)
	Lcd_Write_Char(str[i]);
}
void Lcd_Set_Cursor(unsigned char row, unsigned char col)
{
	unsigned char cmd;
	cmd = (row==1?0x80:0xC0) + col - 1;
	lcd_send_cmd(cmd);
	_delay_ms(2);
}