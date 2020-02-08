
#include "main.h"
#include "KeyPad4x4.h"

void KeyPad4x4_Init()
{
  key_ddr = 0x0F;
  key_port = 0x0F;
}
unsigned char Key_press()
{
	unsigned char key = 0;
	cbi(key_port, 0);
	if(bit_is_clear(key_pin, 4)) key = 1;
	if(bit_is_clear(key_pin, 5)) key = 2;
	if(bit_is_clear(key_pin, 6)) key = 3;
	if(bit_is_clear(key_pin, 7)) key = 4;
	sbi(key_port, 0);
	cbi(key_port, 1);
	if(bit_is_clear(key_pin, 4)) key = 5;
	if(bit_is_clear(key_pin, 5)) key = 6;
	if(bit_is_clear(key_pin, 6)) key = 7;
	if(bit_is_clear(key_pin, 7)) key = 8;
	sbi(key_port, 1);
	cbi(key_port, 2);
	if(bit_is_clear(key_pin, 4)) key = 9;
	if(bit_is_clear(key_pin, 5)) key = 10;
	if(bit_is_clear(key_pin, 6)) key = 11;
	if(bit_is_clear(key_pin, 7)) key = 12;
	sbi(key_port, 2);
	cbi(key_port, 3);
	if(bit_is_clear(key_pin, 4)) key = 13;
	if(bit_is_clear(key_pin, 5)) key = 14;
	if(bit_is_clear(key_pin, 6)) key = 15;
	if(bit_is_clear(key_pin, 7)) key = 16;
	sbi(key_port, 3);
	return key;
}