/*
 * DS1307.c
 *
 * Created: 5/30/2019 9:06:01 AM
 * Author : Admin
 */ 
#define D4 eS_PORTD2
#define D5 eS_PORTD3
#define D6 eS_PORTD4
#define D7 eS_PORTD5
#define RS eS_PORTD0
#define EN eS_PORTD1

#include "main.h"
#include "I2C.h"
#include "lcd.h"

int DECIMALtoBCD(int DEC)
{
	int L, H;
	L=DEC%10; //make digit low
	H=DEC/10<<4; //make digit high
	return (H+L);
}
int BCDtoDECIMAL(int BCD)
{
	int L, H;
	L=BCD & 0x0F; //ones
	H=(BCD>>4) * 10;//tens
	return (H+L);
}
void DS1307_Init(uint8_t hour, uint8_t min, uint8_t date, uint8_t month, uint8_t year);
int main(void)
{
	uint8_t time[7];
	// port
	DDRD = 0xFF;
    // chuong trinh con
	Lcd4_Init();
	I2C_Init();
	// begin
    while (1) 
    {
		I2C_Start_Wait(0xD0);
		I2C_Write(0x00);
		I2C_Repeated_Start(0xD1);
		time[0] = I2C_Read_Ack();
		time[1] = I2C_Read_Ack();
		time[2] = I2C_Read_Ack();
		time[3] = I2C_Read_Ack();
		time[4] = I2C_Read_Ack();
		time[5] = I2C_Read_Ack();
		time[6] = I2C_Read_Nack();
		I2C_Stop();

		time[0] = BCDtoDECIMAL(time[0]);
		time[1] = BCDtoDECIMAL(time[1]);
		time[2] = BCDtoDECIMAL(time[2]);
		time[4] = BCDtoDECIMAL(time[4]);
		time[5] = BCDtoDECIMAL(time[5]);
		time[6] = BCDtoDECIMAL(time[6]);
		
		Lcd4_Set_Cursor(1,4);
		Lcd4_Write_Char(time[2]/10+48);
		Lcd4_Write_Char(time[2]%10+48);
		Lcd4_Write_Char(':');
		Lcd4_Write_Char(time[1]/10+48);
		Lcd4_Write_Char(time[1]%10+48);
		Lcd4_Write_Char(':');
		Lcd4_Write_Char(time[0]/10+48);
		Lcd4_Write_Char(time[0]%10+48);
		
		Lcd4_Set_Cursor(2,3);
		Lcd4_Write_Char(time[4]/10+48);
		Lcd4_Write_Char(time[4]%10+48);
		Lcd4_Write_Char(':');
		Lcd4_Write_Char(time[5]/10+48);
		Lcd4_Write_Char(time[5]%10+48);
		Lcd4_Write_Char(':');
		Lcd4_Write_String("20");
		Lcd4_Write_Char(time[6]/10+48);
		Lcd4_Write_Char(time[6]%10+48);
		_delay_ms(1000);
		Lcd4_Set_Cursor(1,0);
		Lcd4_Write_Char(' ');
		
    }
}
void DS1307_Init(uint8_t hour, uint8_t min, uint8_t date, uint8_t month, uint8_t year)
{
	_delay_ms(100);
	hour = DECIMALtoBCD(hour);
	min = DECIMALtoBCD(min);
	date = DECIMALtoBCD(date);
	month = DECIMALtoBCD(month);
	year = DECIMALtoBCD(year);
	
	I2C_Start_Wait(0xD0);
	I2C_Write(0x01);
	I2C_Write(min);
	I2C_Stop();
	
	I2C_Start_Wait(0xD0);
	I2C_Write(0x02);
	I2C_Write(hour);
	I2C_Stop();
	
	I2C_Start_Wait(0xD0);
	I2C_Write(0x04);
	I2C_Write(date);
	I2C_Stop();
	
	I2C_Start_Wait(0xD0);
	I2C_Write(0x05);
	I2C_Write(month);
	I2C_Stop();
	
	I2C_Start_Wait(0xD0);
	I2C_Write(0x06);
	I2C_Write(year);
	I2C_Stop();
}

