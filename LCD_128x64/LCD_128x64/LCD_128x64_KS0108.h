#include <avr/pgmspace.h>

#ifndef _LCD_128x64_
#define _LCD_128x64_

void GLCD_Command(char Command);
void GLCD_Data(char Data);
void GLCD_Init();
void GLCD_ClearAll();
void GLCD_String(char page_no, char *str);
void GLCD_Image(const char* image);

#endif