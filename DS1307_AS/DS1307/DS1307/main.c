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

/*---*/
uint8_t i;
/*---*/
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
typedef struct
{
	uint8_t sec;
	uint8_t min;
	uint8_t hour;
	uint8_t weekDay;
	uint8_t date;
	uint8_t month;
	uint8_t year;
}rtc_t;
void DS1307_Init(rtc_t *rtc);
void DS1307_Get_time(rtc_t *rtc);
void blink();
uint8_t Edit_time(uint8_t row, uint8_t column, int8_t parameter);
void Display(rtc_t *rtc);
int main(void)
{
	rtc_t rtc;
	rtc.hour = 0x12; //  10:40:20 am
	rtc.min =  0x00;
	rtc.sec =  0x00;
	rtc.date = 0x01; //1st Jan 2016
	rtc.month = 0x01;
	rtc.year = 0x09;
	rtc.weekDay = 4;
	/*---port---*/
	DDRD = 0xFF;
	DDRA = 0x00;
    // chuong trinh con
	Lcd4_Init();
	I2C_Init();
	// begin
    while (1) 
    {
		if(bit_is_clear(PINA,0))
		{
			while(bit_is_clear(PINA,0));
			_delay_ms(10);
			i = 0;
			rtc.hour = Edit_time(1,4,rtc.hour);
			rtc.min = Edit_time(1,7,rtc.min);
			rtc.date = Edit_time(2,3,rtc.date);
			rtc.month = Edit_time(2,6,rtc.month);
			rtc.year = Edit_time(2,11,rtc.year);
			rtc.sec = 0;
			DS1307_Init(&rtc);
		}
		DS1307_Get_time(&rtc);
		Display(&rtc);
		_delay_ms(1000);
    }
}
void DS1307_Init(rtc_t *rtc)
{
	rtc->hour = DECIMALtoBCD(rtc->hour);
	rtc->min = DECIMALtoBCD(rtc->min);
	rtc->date = DECIMALtoBCD(rtc->date);
	rtc->month = DECIMALtoBCD(rtc->month);
	rtc->year = DECIMALtoBCD(rtc->year);
	/*--------*/
	I2C_Start_Wait(0xD0);     // connect to DS1307 by sending its ID on I2c Bus
	I2C_Write(0x00); // Request sec RAM address at 00H
	
	I2C_Write(rtc->sec);                    // Write sec from RAM address 00H
	I2C_Write(rtc->min);                    // Write min from RAM address 01H
	I2C_Write(rtc->hour);                    // Write hour from RAM address 02H
	I2C_Write(rtc->weekDay);                // Write weekDay on RAM address 03H
	I2C_Write(rtc->date);                    // Write date on RAM address 04H
	I2C_Write(rtc->month);                    // Write month on RAM address 05H
	I2C_Write(rtc->year);                    // Write year on RAM address 06h
	
	I2C_Stop();                              // Stop I2C communication after Setting the Date
}
void DS1307_Get_time(rtc_t *rtc)
{
	I2C_Start_Wait(0xD0);
	I2C_Write(0x00);
	I2C_Repeated_Start(0xD1);
	rtc->sec = I2C_Read_Ack();
	rtc->min = I2C_Read_Ack();
	rtc->hour= I2C_Read_Ack();
	rtc->weekDay = I2C_Read_Ack();
	rtc->date = I2C_Read_Ack();
	rtc->month =I2C_Read_Ack();
	rtc->year = I2C_Read_Nack();
	I2C_Stop();
	
	rtc->sec = BCDtoDECIMAL(rtc->sec);
	rtc->min = BCDtoDECIMAL(rtc->min);
	rtc->hour = BCDtoDECIMAL(rtc->hour);
	rtc->weekDay = BCDtoDECIMAL(rtc->weekDay);
	rtc->date = BCDtoDECIMAL(rtc->date);
	rtc->month = BCDtoDECIMAL(rtc->month);
	rtc->year = BCDtoDECIMAL(rtc->year);
}
void blink()
{
	uint8_t j = 0;
	while(j < 75 && bit_is_set(PINA,0) && bit_is_set(PINA,1) && bit_is_set(PINA,2)) {
		j++;
		_delay_ms(5);
	}
}
uint8_t Edit_time(uint8_t row, uint8_t column, int8_t parameter)
{
	while(1)
	{
		/*--- up ---*/
		while(bit_is_clear(PINA,1))
		{
			parameter++;
			if(i == 0 && parameter > 23)   // if hours > 23 ==> hours = 0
			parameter = 0;
			if(i == 1 && parameter > 59)   // if minutes > 59 ==> minutes = 0
			parameter = 0;
			if(i == 2 && parameter > 31)   // if date > 31 ==> date = 1
			parameter = 1;
			if(i == 3 && parameter > 12)   // if month > 12 ==> month = 1
			parameter = 1;
			if(i == 4 && parameter > 99)   // if year > 99 ==> year = 0
			parameter = 0;
			
			Lcd4_Set_Cursor(row,column);
			Lcd4_Write_Char(parameter/10+48);
			Lcd4_Write_Char(parameter%10+48);
			_delay_ms(500);
		}
		/*--- down ---*/
		while(bit_is_clear(PINA,2))
		{
			parameter--;
			if(i == 0 && parameter < 0)   // if hours > 23 ==> hours = 0
			parameter = 23;
			if(i == 1 && parameter < 0)   // if minutes > 59 ==> minutes = 0
			parameter = 59;
			if(i == 2 && parameter < 1)   // if date > 31 ==> date = 1
			parameter = 31;
			if(i == 3 && parameter < 1)   // if month > 12 ==> month = 1
			parameter = 12;
			if(i == 4 && parameter < 1)   // if year > 99 ==> year = 0
			parameter = 99;
			
			Lcd4_Set_Cursor(row,column);
			Lcd4_Write_Char(parameter/10+48);
			Lcd4_Write_Char(parameter%10+48);
			_delay_ms(200);
		}
		/*--- blink ---*/
		Lcd4_Set_Cursor(row,column);
		Lcd4_Write_String("  ");
		blink();
		
		Lcd4_Set_Cursor(row,column);
		Lcd4_Write_Char(parameter/10+48);
		Lcd4_Write_Char(parameter%10+48);
		blink();
		/*--- break ---*/
		if(bit_is_clear(PINA,0))
		{
			while(bit_is_clear(PINA,0));
			i++;
			return parameter;
		}
	}
}
void Display(rtc_t *rtc)
{
	Lcd4_Set_Cursor(1,4);
	Lcd4_Write_Char(rtc->hour/10+48);
	Lcd4_Write_Char(rtc->hour%10+48);
	Lcd4_Write_Char(':');
	Lcd4_Write_Char(rtc->min/10+48);
	Lcd4_Write_Char(rtc->min%10+48);
	Lcd4_Write_Char(':');
	Lcd4_Write_Char(rtc->sec/10+48);
	Lcd4_Write_Char(rtc->sec%10+48);
	
	Lcd4_Set_Cursor(2,3);
	Lcd4_Write_Char(rtc->date/10+48);
	Lcd4_Write_Char(rtc->date%10+48);
	Lcd4_Write_Char(':');
	Lcd4_Write_Char(rtc->month/10+48);
	Lcd4_Write_Char(rtc->month%10+48);
	Lcd4_Write_Char(':');
	Lcd4_Write_String("20");
	Lcd4_Write_Char(rtc->year/10+48);
	Lcd4_Write_Char(rtc->year%10+48);
	
	Lcd4_Set_Cursor(1,0);
	Lcd4_Write_Char(' ');
}

