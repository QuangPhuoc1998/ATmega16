#define RS eS_PORTB0
#define EN eS_PORTB1
#define D4 eS_PORTB2
#define D5 eS_PORTB3
#define D6 eS_PORTB4
#define D7 eS_PORTB5

#include "main.h"
#include "lcd.h"
#include "Kalman_filter.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int r;
	char buffer[16];
	int u0 = 50; // Gia tri thuc
	int e; // nhieu
	int u; // gia tr do duoc co them nhieu
	int u_kalman; // gia tri dc loc
	
	/*-----------*/
	DDRB = 0xFF;
	/*-----------*/
    Lcd4_Init();
	SimpleKalmanFilter(10,10,0.001);
	/*-----------*/
    Lcd4_Set_Cursor(1,0);
	sprintf(buffer,"%d  ",r);
    Lcd4_Write_String(buffer);
    while (1) 
    {
		e = 0 + rand()%100;
		u = u0 + e;
		Lcd4_Set_Cursor(1,0);
		sprintf(buffer,"%d  ",u);
		Lcd4_Write_String(buffer);
		
		Lcd4_Set_Cursor(2,0);
		sprintf(buffer,"%d  ",u0);
		Lcd4_Write_String(buffer);
		
		u_kalman = updateEstimate(u);
		u_kalman = updateEstimate(u_kalman);
		u_kalman = updateEstimate(u_kalman); 
		u_kalman = updateEstimate(u_kalman);
		Lcd4_Set_Cursor(2,8);
		sprintf(buffer,"%d  ",u_kalman);
		Lcd4_Write_String(buffer);
		
		_delay_ms(500);
    }
}

