/*
 * bsp_spi.h
 *
 * Created: 4/2/2021 11:52:47 AM
 *  Author: phuoc
 */ 


#ifndef BSP_SPI_H_
#define BSP_SPI_H_

#include "main.h"

void bsp_spi_init();
void bsp_spi_write(uint8_t *p_src, uint8_t len);



#endif /* BSP_SPI_H_ */