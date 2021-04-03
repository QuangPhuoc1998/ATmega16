/*
 * lib_74hc595.h
 *
 * Created: 4/2/2021 12:14:50 PM
 *  Author: phuoc
 */ 


#ifndef LIB_74HC595_H_
#define LIB_74HC595_H_

#include "bsp_spi.h"

void hc595_settup();
void hc595_write(uint8_t* data, uint8_t len);

#endif /* LIB_74HC595_H_ */