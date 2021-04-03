/*
 * bsp_spi.c
 *
 * Created: 4/2/2021 11:53:20 AM
 *  Author: phuoc
 */ 
#include "bsp_spi.h"

/***************************/
/*     STATIC FUNCTION     */
/***************************/
void Spi_Init_Master();
void Spi_Init_Slave();
unsigned char Spi_Read();
void Spi_Read_Text(char *Output, unsigned int length);
void Spi_Write(char data);
void SPI_Write_Text(uint8_t *text, uint8_t len);
/***************************/
/*    BSP SPI FUNCTION     */
/***************************/
void bsp_spi_init()
{
	Spi_Init_Master();
	sbi(PORTB, 4);
}
void bsp_spi_write(uint8_t *p_src, uint8_t len)
{
	cbi(PORTB, 4);
	SPI_Write_Text(p_src, len);
	sbi(PORTB, 4);
}

/***************************/
/*       SPI LIBRARY       */
/***************************/
void Spi_Init_Master()
{
	DDRB |= (1<<4)|(1<<5)|(1<<7);    // SCK, MOSI and SS as outputs
	DDRB &= ~(1<<6);                 // MISO as input
	
	SPCR |= (1<<MSTR);               // Set as Master
	SPCR |= (1<<SPR0)|(1<<SPR1);     // divided clock by 128
	SPCR |= (1<<SPE);                // Enable SPI
}
void Spi_Init_Slave()
{
	DDRB &= ~((1<<4)|(1<<5)|(1<<7));   // SCK, MOSI and SS as inputs
	DDRB |= (1<<6);                    // MISO as output

	SPCR &= ~(1<<MSTR);                // Set as slave
	SPCR |= (1<<SPR0)|(1<<SPR1);       // divide clock by 128
	SPCR |= (1<<SPE);
}
unsigned char Spi_Read()
{
	while(!(SPSR & (1<<SPIF)));    // wait until all data is received
	return SPDR;
}
void Spi_Read_Text(char *Output, unsigned int length)
{
	int i;
	for(i=0;i<length;i++)
	Output[i] = Spi_Read();
}
void Spi_Write(char data)
{
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
}
void SPI_Write_Text(uint8_t *text, uint8_t len)
{
	int i;
	for(i=0;i<len;i++)
	Spi_Write(text[i]);
}