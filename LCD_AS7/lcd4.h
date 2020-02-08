
#include "main.h"

#define RS PORTC & (1<<0)
#define EN PORTC & (1<<1)
#define D4 PORTC & (1<<2)
#define D5 PORTC & (1<<3)
#define D6 PORTC & (1<<4)
#define D7 PORTC & (1<<5)

void Lcd_Port(char a);
void Lcd_Cmd(char a);
void Lcd_Clear();
void Lcd_Set_Cursor(char a, char b);
void Lcd_Init();
void Lcd_Write_Char(char a);
void Lcd_Write_String(char *a);
void Lcd_Shift_Right();
void Lcd_Shift_Left();