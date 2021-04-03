/*
 * lib_74hc595.c
 *
 * Created: 4/2/2021 12:14:38 PM
 *  Author: phuoc
 */ 
#include "lib_74hc595.h"

void hc595_settup()
{
	
}
void hc595_write(uint8_t* data, uint8_t len)
{
	bsp_spi_write(data, len);
}
