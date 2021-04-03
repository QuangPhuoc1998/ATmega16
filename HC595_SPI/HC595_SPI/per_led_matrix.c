/*
 * per_led_matrix.c
 *
 * Created: 4/2/2021 12:07:14 PM
 *  Author: phuoc
 */ 
#include "per_led_matrix.h"

uint16_t pixel_bits[8] = {   // each bit stand for a led
	0b1111111111111111,   // row 0
	0b1111111111111111,   // row 1
	0b1111111111111111,   // row 2
	0b1111111111111111,   // row 3
	0b1111111111111111,   // row 4
	0b1111111111111111,   // row 5
	0b1111111111111111,   // row 6
	0b1111111111111111,   // row 7
};

bool per_led_read_bit(uint16_t data, uint8_t bit);

void per_led_seg_setup(void)
{
	
}

void per_led_seg_reset_led(uint8_t row, uint8_t col)
{
	pixel_bits[row] |= 0x01 << col;
}

void per_led_seg_set_led(uint8_t row, uint8_t col)
{
	pixel_bits[row] &= ~(0x01 << col);
}

void per_led_seg_reset_all(void)
{
	for (uint8_t i = 0; i < 8; i++)
	{
		pixel_bits[i] = 0x00;
	}
}

void per_led_left_shift(void)
{
	for(int i=0;i<8;i++)
	{
		pixel_bits[i] = (pixel_bits[i] >> 1);
		if(per_led_read_bit(pixel_bits[i], 0) != false)
		{
			pixel_bits[i] |= 0x8000;
		}
	}
}

void per_led_copy_data(uint16_t *data)
{
	for(int i=0;i<8;i++)
	{
		pixel_bits[i] = data[i];
	}
}

void per_led_seg_task(void)
{
	static uint8_t row = 0;
	
	uint8_t led_data[2] = {0, 0};

	led_data[0] = ~(0x01 << (7 - row));   // send row first
	led_data[1] = ~(pixel_bits[row]);     // then send column
	
	hc595_write(led_data, 2);

	if (++row >= 8)
	{
		row = 0;
	}
}


bool per_led_read_bit(uint16_t data, uint8_t bit)
{
	if(bit_is_clear(data, bit)) return 0; else return 1;
}