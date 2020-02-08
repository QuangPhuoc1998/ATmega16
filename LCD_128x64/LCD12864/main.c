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
};

#define DHT11_PIN 0
#define DHT11_DDR DDRA
#define DHT11_PORT PORTA
#define DHT11_LG PINA

uint8_t I_RH,D_RH,I_Temp,D_Temp,CheckSum;
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
int BCDtoDECIMAL(int BCD)
{
	int L, H;
	L=BCD & 0x0F; //ones
	H=(BCD>>4) * 10;//tens
	return (H+L);
}
int main(void)
{
	uint8_t time[7];
	uint8_t I_RH,D_RH,I_Temp,D_Temp,CheckSum;
    GLCD_Init();
	I2C_Init();
    GLCD_Clr();
	GLCD_PutBMP(anime_v10);
	_delay_ms(2000);
	GLCD_PutBMP(khung);
    while(1)
	{
		Request();		/* send start pulse */
		Response();		/* receive response */
		I_RH=Receive_data();	/* store first eight bit in I_RH */
		D_RH=Receive_data();	/* store next eight bit in D_RH */
		I_Temp=Receive_data();	/* store next eight bit in I_Temp */
		D_Temp=Receive_data();	/* store next eight bit in D_Temp */
		CheckSum=Receive_data();/* store next eight bit in CheckSum */
		//
		
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
		//
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
		//
		time[0] = BCDtoDECIMAL(time[0]);
		time[1] = BCDtoDECIMAL(time[1]);
		time[2] = BCDtoDECIMAL(time[2]);
		time[4] = BCDtoDECIMAL(time[4]);
		time[5] = BCDtoDECIMAL(time[5]);
		time[6] = BCDtoDECIMAL(time[6]);
		//
		Display(1,11,time[2]/10);
		Display(1,17,time[2]%10);
		Display(1,23,':'); //
		Display(1,29,time[1]/10);
		Display(1,35,time[1]%10);
		Display(1,41,':'); //
		Display(1,47,time[0]/10);
		Display(1,53,time[0]%10);
		_delay_ms(1000);
    }
    return 0;
}


