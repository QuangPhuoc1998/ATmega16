/*
 * I2C_P2.c
 *
 * Created: 02/05/2019 00:34:23
 * Author : ADMIN
 */ 

#include "main.h"
#include "I2C.h"
#include <avr/interrupt.h>


int main(void)
{
  DDRB = 0xFF;
  
  // chuong trinh con
  I2C_Slave_Init(0x40);
  sei();
  while(1)
  {
  }
}
ISR(TWI_vect)
{
  if(I2C_Slave_Listen() == 0)
  {
    unsigned char i = I2C_Slave_Receive(); 
	if(i == 'A') PORTB = ~PORTB;
  } 
}

