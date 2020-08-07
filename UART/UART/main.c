/*
 * UART.c
 *
 * Created: 8/6/2020 5:38:52 PM
 * Author : KhaledMohamedElsayed
 */ 

#include "UART.h"
#include "LCD.h"
#include <avr/interrupt.h>
#define F_CPU 16000000
#include <util/delay.h>

int main(void)
{
	
    UART_Init();
	LCD_Init();
    while (1) 
    {
    }
}

ISR(USART_RXC_vect)
{
	uint8 data = 0 ;
	data = UDR ;
	LCD_WriteChar(data);
	_delay_ms(100);
}