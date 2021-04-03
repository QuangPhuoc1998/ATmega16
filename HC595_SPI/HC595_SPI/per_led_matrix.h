/*
 * per_led_matrix.h
 *
 * Created: 4/2/2021 12:09:53 PM
 *  Author: phuoc
 */ 


#ifndef PER_LED_MATRIX_H_
#define PER_LED_MATRIX_H_

#include "lib_74hc595.h"

void per_led_seg_setup(void);
void per_led_seg_set_led(uint8_t row, uint8_t col);
void per_led_seg_reset_led(uint8_t row, uint8_t col);
void per_led_seg_reset_all(void);
void per_led_left_shift(void);
void per_led_copy_data(uint16_t *data);
void per_led_seg_task(void);

#endif /* PER_LED_MATRIX_H_ */