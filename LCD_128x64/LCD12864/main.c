/*
 * LCD12864.c
 *
 * Created: 8/6/2019 10:52:45 AM
 * Author : Admin
 */ 

#include "main.h"
#include "font.h"
#include "myGLCD.h"
#include "Image.h"
#include "I2C.h"

char number_1[] = {
0x00,0xFE,0xFF,0x03,0xFF,0xFE,0x00,  0x00,0x7F,0xFF,0xC0,0xFF,0x7F,0x00, // 0
0x00,0x00,0x03,0xFF,0xFF,0x00,0x00,  0x00,0x00,0xC0,0xFF,0xFF,0xC0,0x00, // 1
0x00,0x83,0x83,0x83,0xFF,0xFF,0x00,  0x00,0xFF,0xFF,0xC1,0xC1,0xC1,0x00, // 2
0x00,0x83,0x83,0x83,0xFF,0xFF,0x00,  0x00,0xC1,0xC1,0xC1,0xFF,0xFF,0x00, // 3
0x00,0xFF,0xFF,0x80,0xFF,0xFF,0x00,  0x00,0x01,0x01,0x01,0xFF,0xFF,0x00, // 4
0x00,0xFF,0xFF,0x83,0x83,0x83,0x00,  0x00,0xC1,0xC1,0xC1,0xFF,0xFF,0x00, // 5
0x00,0xFF,0xFF,0x83,0x83,0x83,0x00,  0x00,0xFF,0xFF,0xC1,0xFF,0xFF,0x00, // 6
0x00,0x03,0x03,0x03,0xFF,0xFF,0x00,  0x00,0x00,0x00,0x00,0xFF,0xFF,0x00, // 7
0x00,0xFE,0xFF,0x83,0xFF,0xFE,0x00,  0x00,0x7F,0xFF,0xC1,0xFF,0x7F,0x00, // 8
0x00,0xFF,0xFF,0x83,0xFF,0xFF,0x00,  0x00,0xC1,0xC1,0xC1,0xFF,0xFF,0x00,  // 9
0x00,0x00,0x38,0x38,0x38,0x00,0x00,  0x00,0x00,0x1C,0x1C,0x1C,0x00,0x00,  // :
0x00,0x00,0x00,0x00,0x00,0x00,0x00,  0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

#define DHT11_PIN 0
#define DHT11_DDR DDRA
#define DHT11_PORT PORTA
#define DHT11_LG PINA

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
/*---global variable--*/
uint8_t i;
uint8_t I_RH,D_RH,I_Temp,D_Temp,CheckSum;
/*-----*/
uint8_t I_RH,D_RH,I_Temp,D_Temp,CheckSum;
void DS1307_Init(rtc_t *rtc);
void DS1307_Get_time(rtc_t *rtc);
void blink();
uint8_t Edit_time(uint8_t row, uint8_t column_1, uint8_t column_2, int8_t parameter);
void Request();				
void Response();
uint8_t Receive_data();
uint8_t Edit_time(uint8_t row, uint8_t column_1, uint8_t column_2, int8_t parameter);
void Display(unsigned char line, unsigned char col, unsigned char number);
void Display_Time(rtc_t *rtc);
int DECIMALtoBCD(int DEC);
int BCDtoDECIMAL(int BCD);


int main(void)
{
	/*------*/
	rtc_t rtc;
	rtc.hour = 0x12; //  10:40:20 am
	rtc.min =  0x00;
	rtc.sec =  0x00;

	rtc.date = 0x01; //1st Jan 2016
	rtc.month = 0x01;
	rtc.year = 0x09;
	rtc.weekDay = 4;
	/*---port---*/
	cbi(DDRA,1);
	cbi(DDRA,2);
	cbi(DDRA,3);
	/*------*/
    GLCD_Init();
	I2C_Init();
    GLCD_Clr();
	GLCD_PutBMP(khung);
    while(1)
	{
		/*------ Set time ------*/
		if(bit_is_clear(PINA,1))
		{
			while(bit_is_clear(PINA,1));
			_delay_ms(10);
			i = 0;
			rtc.hour = Edit_time(1,11,17,rtc.hour);
			rtc.min = Edit_time(1,29,35,rtc.min);
			//rtc.date = Edit_time(2,3,rtc.date);
			//rtc.month = Edit_time(2,6,rtc.month);
			//rtc.year = Edit_time(2,11,rtc.year);
			rtc.sec = 0;
			DS1307_Init(&rtc);
		}
		/*------ DHT11------*/
		Request();		/* send start pulse */
		Response();		/* receive response */
		I_RH=Receive_data();	/* store first eight bit in I_RH */
		D_RH=Receive_data();	/* store next eight bit in D_RH */
		I_Temp=Receive_data();	/* store next eight bit in I_Temp */
		D_Temp=Receive_data();	/* store next eight bit in D_Temp */
		CheckSum=Receive_data();/* store next eight bit in CheckSum */
		
		if ((I_RH + D_RH + I_Temp + D_Temp) != CheckSum);
		else
		{
			GLCD_PutChar78(2,92,I_Temp/10+48);
			GLCD_PutChar78(2,99,I_Temp%10+48);
			GLCD_Print78(2,106,"oC");
			//
			GLCD_PutChar78(6,94,I_RH/10+48);
			GLCD_PutChar78(6,101,I_RH%10+48);
			GLCD_PutChar78(6,110,'%');
		}
		/*------DS1307------*/
		DS1307_Get_time(&rtc);
		Display_Time(&rtc);
		_delay_ms(1000);
    }
    return 0;
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
	while(j < 75 && bit_is_set(PINA,1) && bit_is_set(PINA,2) && bit_is_set(PINA,3)) {
		j++;
		_delay_ms(5);
	}
}
uint8_t Edit_time(uint8_t row, uint8_t column_1, uint8_t column_2, int8_t parameter)
{
	while(1)
	{
		/*--- up ---*/
		while(bit_is_clear(PINA,2))
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
			
			Display(row,column_1,parameter/10);
			Display(row,column_2,parameter%10);
			_delay_ms(500);
			
		}
		/*--- down ---*/
		while(bit_is_clear(PINA,3))
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
			
			Display(row,column_1,parameter/10);
			Display(row,column_2,parameter%10);
			_delay_ms(500);
			
			_delay_ms(200);
		}
		
		Display(row,column_1,' ');
		Display(row,column_2,' ');
		blink();
		
		Display(row,column_1,parameter/10);
		Display(row,column_2,parameter%10);
		blink();
		
		if(bit_is_clear(PINA,1))
		{
			while(bit_is_clear(PINA,1));
			i++;
			return parameter;
		}
	}
}
void Request()				/* Microcontroller send start pulse/request */
{
	sbi(DHT11_DDR,DHT11_PIN);
	cbi(DHT11_PORT,DHT11_PIN);	/* set to low pin */
	_delay_ms(20);			/* wait for 20ms */
	sbi(DHT11_PORT,DHT11_PIN);	/* set to high pin */
}
void Response()				/* receive response from DHT11 */
{
	cbi(DHT11_DDR,DHT11_PIN);
	while(bit_is_set(DHT11_LG, DHT11_PIN));
	while(bit_is_clear(DHT11_LG, DHT11_PIN));
	while(bit_is_set(DHT11_LG, DHT11_PIN));
}
uint8_t Receive_data()			/* receive data */
{
	uint8_t c=0;
	for (int q=0; q<8; q++)
	{
		while(bit_is_clear(DHT11_LG, DHT11_PIN));  /* check received bit 0 or 1 */
		_delay_us(30);
		if(bit_is_set(DHT11_LG, DHT11_PIN))/* if high pulse is greater than 30ms */
		c = (c<<1)|(0x01);	/* then its logic HIGH */
		else			/* otherwise its logic LOW */
		c = (c<<1);
		while(bit_is_set(DHT11_LG, DHT11_PIN));
	}
	return c;
}
void Display(unsigned char line, unsigned char col, unsigned char number)
{
	uint8_t i = 0;
	switch(number)
	{
		case 0:
		i = 0;
		break;
		case 1:
		i = 14;
		break;
		case 2:
		i = 28;
		break;
		case 3:
		i = 42;
		break;
		case 4:
		i = 56;
		break;
		case 5:
		i = 70;
		break;
		case 6:
		i = 84;
		break;
		case 7:
		i = 98;
		break;
		case 8:
		i = 112;
		break;
		case 9:
		i = 126;
		break;
		case ':':
		i = 140;
		break;
		case ' ':
		i = 154;
		break;
		default: break;
	}
	for(uint8_t cot = col;cot<col+7;cot++)
	{
		GLCD_GotoXY(line,cot);
		GLCD_WriteDATA(number_1[i]);
		i++;
	}
	i-=7;
	for(uint8_t cot = col;cot<col+7;cot++)
	{
		GLCD_GotoXY(line+1,cot);
		GLCD_WriteDATA(number_1[i+7]);
		i++;
	}
}
void Display_Time(rtc_t *rtc)
{
	Display(1,11,rtc->hour/10);
	Display(1,17,rtc->hour%10);
	Display(1,23,':'); //
	Display(1,29,rtc->min/10);
	Display(1,35,rtc->min%10);
	Display(1,41,':'); //
	Display(1,47,rtc->sec/10);
	Display(1,53,rtc->sec%10);
}
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