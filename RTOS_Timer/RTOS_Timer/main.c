/*
 * RTOS_Timer.c
 *
 * Created: 3/20/2021 8:21:45 AM
 * Author : phuoc
 */ 

#include "main.h"
#include "timer_1.h"
#include "sys_timer.h"
#include "sys_task.h"
#include "bsp_gpio.h"
#include "per_key.h"
#include "ftr_touch.h"

void task1(void *pv_params);

typedef struct
{
	uint8_t My_PIN;  
	uint8_t My_DDRA;
	uint8_t My_PORTA;   
} GPIO_t;
volatile GPIO_t*   const portd       = (GPIO_t*)(0x19+0x20);
int main(void)
{
	DDRB = 0xFF;
	timer1_init();
	bsp_gpio_init();
	sei();
	task_add(TASK_REPEATED, 10, task1);
	per_key_setup();
	ftr_touch_setup();
    while (1) 
    {
		task_loop();
    }
}
void task1(void *pv_params)
{
	(void)pv_params;
	
	if(ftr_touch_is_touched(TOUCH_1))
	{
		bsp_gpio_toggle_pin(GPIO_LED_1_Pin);
		ftr_touch_clear(TOUCH_1);
	}
	
	
	if(ftr_touch_is_touched(TOUCH_2))
	{
		bsp_gpio_toggle_pin(GPIO_LED_2_Pin);
		ftr_touch_clear(TOUCH_2);
	}
	
	if(ftr_touch_is_touched(TOUCH_3))
	{
		bsp_gpio_toggle_pin(GPIO_LED_3_Pin);
		ftr_touch_clear(TOUCH_3);
	}
	
}
ISR(TIMER1_OVF_vect)
{
	TCNT1 = 49536;
	timer_handler(0);
}

