/*
 * HC595_SPI.c
 *
 * Created: 4/2/2021 10:10:28 AM
 * Author : phuoc
 */ 

#include "main.h"
#include "timer_1.h"
#include "sys_task.h"
#include "sys_timer.h"
#include "bsp_spi.h"
#include "lib_74hc595.h"
#include "per_led_matrix.h"

uint16_t my_led[8] = 
{

	0b1111111111100111,   // row 0
	0b1111111111110011,   // row 1
	0b1111111111111001,   // row 2
	0b1111111100000000,   // row 3
	0b1111111100000000,   // row 4
	0b1111111111111001,   // row 5
	0b1111111111110011,   // row 6
	0b1111111111100111,   // row 7
};



void spi_send_data(uint8_t data);
int main(void)
{
	uint8_t cout = 0;
    timer1_init();
	bsp_spi_init();	
	per_led_copy_data(my_led);
	sei();
    while (1) 
    {
		_delay_ms(200);
		cout++;
		if(cout == 16) 
		{
			per_led_copy_data(my_led);
			cout = 0;
		} else per_led_left_shift();
		
    }
}
ISR(TIMER1_OVF_vect)
{
	TCNT1 = 49536;
	//timer_handler(0);
	per_led_seg_task();
}

