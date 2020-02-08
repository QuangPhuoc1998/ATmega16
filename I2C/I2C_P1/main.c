/*
 * I2C_P1.c
 *
 * Created: 02/05/2019 00:07:10
 * Author : ADMIN
 */ 

#include "main.h"
#include "I2C.h"

int main(void)
{
  DDRB = 0xFF;
  DDRD = 0xFF;
  // chuong trinh con
  I2C_Init();
  while(1)
  {
    I2C_Start(0x41);	
	PORTB = I2C_Read_Nack();
	I2C_Stop();
	_delay_ms(500);
  }
}

