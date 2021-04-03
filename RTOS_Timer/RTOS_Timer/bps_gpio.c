/*
 * CFile1.c
 *
 * Created: 3/20/2021 9:15:44 AM
 *  Author: phuoc
 */ 
#include "bsp_gpio.h"

struct gpio_pin_struct
{
	uint32_t pin;
	GPIO_TypeDef Pin;
	GPIO_TypeDef Ddr;
	GPIO_TypeDef Port;
} gpio_pin_table[6];

void bsp_gpio_init(void)
{
	gpio_pin_table[GPIO_TOUCH_1_Pin].pin   = 0;
	gpio_pin_table[GPIO_TOUCH_1_Pin].Pin   = bsp_PINA;
	gpio_pin_table[GPIO_TOUCH_1_Pin].Ddr   = bsp_DDRA;
	gpio_pin_table[GPIO_TOUCH_1_Pin].Port  = bsp_PORTA;
	
	gpio_pin_table[GPIO_TOUCH_2_Pin].pin   = 1;
	gpio_pin_table[GPIO_TOUCH_2_Pin].Pin   = bsp_PINA;
	gpio_pin_table[GPIO_TOUCH_2_Pin].Ddr   = bsp_DDRA;
	gpio_pin_table[GPIO_TOUCH_2_Pin].Port  = bsp_PORTA;
	
	gpio_pin_table[GPIO_TOUCH_3_Pin].pin   = 2;
	gpio_pin_table[GPIO_TOUCH_3_Pin].Pin   = bsp_PINA;
	gpio_pin_table[GPIO_TOUCH_3_Pin].Ddr   = bsp_DDRA;
	gpio_pin_table[GPIO_TOUCH_3_Pin].Port  = bsp_PORTA;
	
	gpio_pin_table[GPIO_LED_1_Pin].pin	   = 0;
	gpio_pin_table[GPIO_LED_1_Pin].Pin     = bsp_PINC;
	gpio_pin_table[GPIO_LED_1_Pin].Ddr     = bsp_DDRC;
	gpio_pin_table[GPIO_LED_1_Pin].Port    = bsp_PORTC;
	
	gpio_pin_table[GPIO_LED_2_Pin].pin	   = 1;
	gpio_pin_table[GPIO_LED_2_Pin].Pin     = bsp_PINC;
	gpio_pin_table[GPIO_LED_2_Pin].Ddr     = bsp_DDRC;
	gpio_pin_table[GPIO_LED_2_Pin].Port    = bsp_PORTC;
	
	gpio_pin_table[GPIO_LED_3_Pin].pin	   = 2;
	gpio_pin_table[GPIO_LED_3_Pin].Pin     = bsp_PINC;
	gpio_pin_table[GPIO_LED_3_Pin].Ddr     = bsp_DDRC;
	gpio_pin_table[GPIO_LED_3_Pin].Port    = bsp_PORTC;
	
	bsp_gpio_set_input_pin(GPIO_TOUCH_1_Pin);
	bsp_gpio_set_input_pin(GPIO_TOUCH_2_Pin);
	bsp_gpio_set_input_pin(GPIO_TOUCH_3_Pin);
	bsp_gpio_set_output_pin(GPIO_LED_1_Pin);
	bsp_gpio_set_output_pin(GPIO_LED_2_Pin);
	bsp_gpio_set_output_pin(GPIO_LED_3_Pin);
}
void bsp_gpio_set_output_pin(gpio_pin_id_t pin_id)
{
	sbi(*(volatile uint8_t *)gpio_pin_table[pin_id].Ddr, gpio_pin_table[pin_id].pin);
}
void bsp_gpio_set_input_pin(gpio_pin_id_t pin_id)
{
	cbi(*(volatile uint8_t *)gpio_pin_table[pin_id].Ddr, gpio_pin_table[pin_id].pin);
}
void bsp_gpio_set_pin(gpio_pin_id_t pin_id)
{
	sbi(*(volatile uint8_t *)gpio_pin_table[pin_id].Port, gpio_pin_table[pin_id].pin);
}
void bsp_gpio_reset_pin(gpio_pin_id_t pin_id)
{
	cbi(*(volatile uint8_t *)gpio_pin_table[pin_id].Port, gpio_pin_table[pin_id].pin);
}
void bsp_gpio_toggle_pin(gpio_pin_id_t pin_id)
{
	tbi(*(volatile uint8_t *)gpio_pin_table[pin_id].Port, gpio_pin_table[pin_id].pin);
}
uint8_t bsp_gpio_read_pin(gpio_pin_id_t pin_id)
{
	return bit_is_clear(*(volatile uint8_t *)gpio_pin_table[pin_id].Pin, gpio_pin_table[pin_id].pin);
}
