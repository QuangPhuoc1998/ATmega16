/*
 * Test_AS7.c
 *
 * Created: 22/04/2019 21:47:31
 * Author : ADMIN
 */ 




#include "main.h"
#include <avr/sfr_defs.h>

int main(void)
{
  cbi(DDRC, PC0);
  sbi(DDRD, PD0);
  while(1)
  {
    if(bit_is_clear(PINC, PC0))
	{
	  while(bit_is_clear(PINC, PC0));
	  tbi(PORTD, PD0);
	}
  }    
}

