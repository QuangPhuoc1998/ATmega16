#include "main.h" 
#include "font.h"
#include "myGLCD.h"
#include "Anim_Images.h"
#include "Image.h"

int main(void){
	// value
	// port
	cbi(DDRA, PA0);
	//
	GLCD_Init();
	//
	while(1)
	{
		GLCD_Clr();	
		GLCD_PutBMP(anime);
		while(1) 
		{
			if(bit_is_clear(PINA, 0)) 
			{
				while(bit_is_clear(PINA, 0));
				break;
			}
			_delay_ms(10);
		}
		GLCD_Clr();
		GLCD_PutBMP(panda);
		while(1)
		{
			if(bit_is_clear(PINA, 0))
			{
				while(bit_is_clear(PINA, 0));
				break;
			}
			_delay_ms(10);
		}
		GLCD_Clr();
		GLCD_PutBMP(cat);
		while(1)
		{
			if(bit_is_clear(PINA, 0))
			{
				while(bit_is_clear(PINA, 0));
				break;
			}
			_delay_ms(10);
		}
		GLCD_Clr();
		GLCD_PutBMP(anime_v5);
		while(1)
		{
			if(bit_is_clear(PINA, 0))
			{
				while(bit_is_clear(PINA, 0));
				break;
			}
			_delay_ms(10);
		}
		GLCD_Clr();
		GLCD_PutBMP(khung_long);
		while(1)
		{
			if(bit_is_clear(PINA, 0))
			{
				while(bit_is_clear(PINA, 0));
				break;
			}
			_delay_ms(10);
		}
	}
	return 0;
}
