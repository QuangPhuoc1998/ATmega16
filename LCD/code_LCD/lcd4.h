#ifndef _LCD4_H_
#define _LCD4_H_
#include "main.h"

#define RS PORTB.0
#define EN PORTB.1
#define D4 PORTB.2
#define D5 PORTB.3
#define D6 PORTB.4
#define D7 PORTB.5

void Lcd_Port(char a);
void Lcd_Cmd(char a);
void Lcd_Clear();
void Lcd_Set_Cursor(char a, char b);
void Lcd_Init();
void Lcd_Write_Char(char a);
void Lcd_Write_String(char *a);
void Lcd_Shift_Right();
void Lcd_Shift_Left();

#endif