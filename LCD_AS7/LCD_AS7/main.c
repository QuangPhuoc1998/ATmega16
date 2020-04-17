/*
 * LCD_AS7.c
 *
 * Created: 22/04/2019 21:32:49
 * Author : ADMIN
 */ 
#define RS eS_PORTB0
#define EN eS_PORTB1
#define D4 eS_PORTB2
#define D5 eS_PORTB3
#define D6 eS_PORTB4
#define D7 eS_PORTB5

#include "main.h"
#include "lcd.h"
#include <stdio.h>


int main(void)
{ 
	char i = 4;
    DDRB = 0xFF;
	float value = 123.456;
	char buffer[10];
	sprintf(buffer,"%d",123);
    Lcd4_Init();
    while (1) 
    {
		Lcd4_Set_Cursor(1,0);
		(i==5) ? Lcd4_Write_String("123") : Lcd4_Write_String("456");
		  
		  


		
    }
}

