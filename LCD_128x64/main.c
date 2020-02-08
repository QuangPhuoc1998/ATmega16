#define F_CPU 16000000ul

#include <avr/io.h>
#include <util/delay.h>
#include "stdio.h"
#include "myGLCD.h"

int main(void){
	uint8_t start=33, Line=0, Col=0,i;	
	char dis[5];
	GLCD_Init();
	GLCD_Clr();	
	//Ghi truc tiep len GLCD------------
	GLCD_GotoXY(4,0);
	for(i=0; i<64; i++) 
		GLCD_WriteDATA(i);		
	GLCD_GotoXY(4,64);
	for(i=64; i<128; i++) 
		GLCD_WriteDATA(i);	
	_delay_ms(1000);
	
	//In cac ky tu trong bang font7x8----
	GLCD_Clr();	
	for (i=start;i<start+97;i++){		
		GLCD_PutChar78(Line, Col, i);
		Col+=8;
		if (Col>127){Col=0; Line++;}
		_delay_ms(20);
	}
	_delay_ms(1000);
	
	//In chuoi ky tu bang hamg print_GLCD78---------
	GLCD_Clr();	
	GLCD_Print78(4,20,"code:");
	sprintf(dis,"%i", 8205);
	GLCD_Print78(4,60,dis);		
	_delay_ms(1500);
	
	//in hinh anh len GLCD--------------------------
	GLCD_PutBMP(hiGLCD);
	_delay_ms(1000);
	for(char i=1;i<64; i++){
		GLCD_StartLine(i);
		_delay_ms(10);
	}
	GLCD_StartLine(0);	
	
	//------V2-------------------------------	
	_delay_ms(1000);
	GLCD_PutLine(0,0, 0, 63);
	GLCD_PutLine(127,63, 0, 63);
	GLCD_PutLine(127,63, 127, 0);
	GLCD_PutLine(0,0, 127, 0);
	_delay_ms(1000);	
	
	GLCD_Clr();		
	int  ty;
	//Ve duong thang bang phuong phap cham diem truc tiep
	for (ty=0; ty<64; ty++)
		GLCD_PutPixel(2*ty,ty);
	_delay_ms(500);	
	//Dung ham ve duong thang (so sanh voi phuong phap cham diem o tren)
	GLCD_PutLine(0,63, 127, 0);
	
	
	while(1){
		
	};
	return 0;
}
