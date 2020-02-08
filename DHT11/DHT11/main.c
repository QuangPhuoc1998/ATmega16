/*
 * DHT11.c
 *
 * Created: 6/17/2019 8:17:00 PM
 * Author : Admin
 */ 
#define D4 eS_PORTD2
#define D5 eS_PORTD3
#define D6 eS_PORTD4
#define D7 eS_PORTD5
#define RS eS_PORTD7
#define EN eS_PORTD6

#include "main.h"
#include "lcd.h"
#include "UART.h"
#include <stdio.h>
#include "avr/interrupt.h"
#define DHT11_PIN 0
#define DHT11_DDR DDRC
#define DHT11_PORT PORTC
#define DHT11_LG PINC

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
int main(void)
{
	char data[5];
	uint8_t I_RH,D_RH,I_Temp,D_Temp,CheckSum;
	//
	DDRD = 0xFF;
	sbi(DDRB, 0);
    Lcd4_Init();
	UART_init(9600);
	Lcd4_Write_String("Nhiet do: ");
	Lcd4_Set_Cursor(2,0);
	Lcd4_Write_String("Do am: ");
	sei();
    while (1) 
    {
		Request();		/* send start pulse */
		Response();		/* receive response */
		I_RH=Receive_data();	/* store first eight bit in I_RH */
		D_RH=Receive_data();	/* store next eight bit in D_RH */
		I_Temp=Receive_data();	/* store next eight bit in I_Temp */
		D_Temp=Receive_data();	/* store next eight bit in D_Temp */
		CheckSum=Receive_data();/* store next eight bit in CheckSum */
		if ((I_RH + D_RH + I_Temp + D_Temp) != CheckSum)
		{
			Lcd4_Set_Cursor(1,0);
			Lcd4_Write_String("Error");
		}
		else
		{
			sprintf(data,"%d.%d", I_Temp, D_Temp);
			UART_SendString(data);
			sprintf(data,"%d.%d", I_RH, D_RH);
			UART_SendString(data);
			//itoa(I_RH,data,10);
			//Lcd4_Set_Cursor(2,7);
			//Lcd4_Write_String(data);
			//Lcd4_Write_String(".");
			//UART_SendString(data);
			//itoa(D_RH,data,10);
			//Lcd4_Write_String(data);
			//Lcd4_Write_String("%");
			//
			//itoa(I_Temp,data,10);
			//Lcd4_Set_Cursor(1,10);
			//Lcd4_Write_String(data);
			//Lcd4_Write_String(".");
			//itoa(D_Temp,data,10);
			//Lcd4_Write_String(data);
			//Lcd4_Write_String("oC");
			_delay_ms(1000);
			
		}
		
    }
}
ISR (USART_RXC_vect)
{
	static unsigned char u;
	u = UART_RxChar();
	if(u == '1')
	{
		sbi(PORTB, 0);
	}
	if(u == '0')
	{
		cbi(PORTB, 0);
	}
}

