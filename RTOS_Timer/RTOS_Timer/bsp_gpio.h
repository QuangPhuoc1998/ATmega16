/*
 * bsp_gpio.h
 *
 * Created: 3/20/2021 9:16:06 AM
 *  Author: phuoc
 */ 


#ifndef BSP_GPIO_H_
#define BSP_GPIO_H_

#include "main.h"

#define offset_reg 0x20

typedef enum
{
	bsp_PINA  = 0x19 + offset_reg,
	bsp_DDRA  = 0x1A + offset_reg,
	bsp_PORTA = 0x1B + offset_reg, 
	
	bsp_PINB  = 0x16 + offset_reg,
	bsp_DDRB  = 0x17 + offset_reg,
	bsp_PORTB = 0x18 + offset_reg,
	
	bsp_PINC  = 0x13 + offset_reg,
	bsp_DDRC  = 0x14 + offset_reg,
	bsp_PORTC = 0x15 + offset_reg,
	
	bsp_PIND  = 0x10 + offset_reg,
	bsp_DDRD  = 0x11 + offset_reg,
	bsp_PORTD = 0x12 + offset_reg
} GPIO_TypeDef;

typedef enum
{
	GPIO_TOUCH_1_Pin,
	GPIO_TOUCH_2_Pin,
	GPIO_TOUCH_3_Pin,
	GPIO_LED_1_Pin,
	GPIO_LED_2_Pin,
	GPIO_LED_3_Pin
} gpio_pin_id_t;

void bsp_gpio_init(void);
void bsp_gpio_set_output_pin(gpio_pin_id_t pin_id);
void bsp_gpio_set_input_pin(gpio_pin_id_t pin_id);
void bsp_gpio_set_pin(gpio_pin_id_t pin_id);
void bsp_gpio_reset_pin(gpio_pin_id_t pin_id);
void bsp_gpio_toggle_pin(gpio_pin_id_t pin_id);
uint8_t bsp_gpio_read_pin(gpio_pin_id_t pin_id);

#endif /* BSP_GPIO_H_ */