/*
 * TEST_MACRO.c
 *
 * Created: 9/30/2020 7:22:19 PM
 * Author : phuoc
 */ 

#include "main.h"

#define offset_reg 0x20
#define My_DDRB (*(volatile uint8_t *)(0x17 + offset_reg))
#define My_PORTB (*(volatile uint8_t *)(0x18 + offset_reg))

int main(void)
{
    My_DDRB = 0xFF;
	My_PORTB = 0x02;
    while (1) 
    {
    }
}

