/*
 * MPU6050.c
 *
 * Created: 5/29/2019 4:43:39 PM
 * Author : Admin
 */ 
#define D4 eS_PORTD2
#define D5 eS_PORTD3
#define D6 eS_PORTD4
#define D7 eS_PORTD5
#define RS eS_PORTD0
#define EN eS_PORTD1

#include "main.h"
#include "lcd.h"
#include "I2C.h"
#include <stdio.h>
#include "stdlib.h"
#include "MPU6050_res_define.h"

float Acc_x,Acc_y,Acc_z;
void Gyro_Init();
void MPU_Start_Loc();
void Read_RawValue();
long map(long x, long in_min, long in_max, long out_min, long out_max);
int main(void)
{
	// bien 
	int Xa,Ya,Za;
	// int t,Xg=0,Yg=0,Zg=0;
	char buffer[10];
	// port
	DDRD = 0xFF;
    // chuong trinh con
	Lcd4_Init();
	I2C_Init();
	 Gyro_Init();
	// begin
    while (1) 
    {
	    Read_RawValue();
		Xa = map(Acc_x, -16384, 16384, -90, 90);
		Ya = map(Acc_y, -16384, 16384, -90, 90);
		Za = map(Acc_z, -16384, 16384, -90, 90);
		// X
		if(Xa<0) sprintf(buffer,"%d ",Xa);
		else sprintf(buffer," %d ",Xa);
		Lcd4_Set_Cursor(1,0);
		Lcd4_Write_String(buffer);
		// Y
		if(Ya<0) sprintf(buffer,"%d ",Ya);
		else sprintf(buffer," %d ",Ya);
		Lcd4_Set_Cursor(2,0);
		Lcd4_Write_String(buffer);
		// Z
		if(Za<0) sprintf(buffer,"%d ",Za);
		else sprintf(buffer," %d ",Za);
		Lcd4_Set_Cursor(1,7);
		Lcd4_Write_String(buffer);
		//
		_delay_ms(100);
    }
}
void Gyro_Init()		/* Gyro initialization function */
{
	_delay_ms(150);		/* Power up time >100ms */
	I2C_Start_Wait(0xD0);	/* Start with device write address */
	I2C_Write(SMPLRT_DIV);	/* Write to sample rate register */
	I2C_Write(0x07);	/* 1KHz sample rate */
	I2C_Stop();

	I2C_Start_Wait(0xD0);
	I2C_Write(PWR_MGMT_1);	/* Write to power management register */
	I2C_Write(0x01);	/* X axis gyroscope reference frequency */
	I2C_Stop();

	I2C_Start_Wait(0xD0);
	I2C_Write(CONFIG);	/* Write to Configuration register */
	I2C_Write(0x00);	/* Fs = 8KHz */
	I2C_Stop();

	I2C_Start_Wait(0xD0);
	I2C_Write(GYRO_CONFIG);	/* Write to Gyro configuration register */
	I2C_Write(0x18);	/* Full scale range +/- 2000 degree/C */
	I2C_Stop();

	I2C_Start_Wait(0xD0);
	I2C_Write(INT_ENABLE);	/* Write to interrupt enable register */
	I2C_Write(0x01);
	I2C_Stop();
}
void MPU_Start_Loc()
{
	I2C_Start_Wait(0xD0);	/* I2C start with device write address */
	I2C_Write(ACCEL_XOUT_H);/* Write start location address from where to read */
	I2C_Repeated_Start(0xD1);/* I2C start with device read address */
}
void Read_RawValue()
{
	MPU_Start_Loc();									/* Read Gyro values */
	Acc_x = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
	Acc_y = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
	Acc_z = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Nack());
	I2C_Stop();
}
long map(long x, long in_min, long in_max, long out_min, long out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
