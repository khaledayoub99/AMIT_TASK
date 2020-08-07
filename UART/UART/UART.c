
#include "UART.h"
#include <avr/interrupt.h>

void UART_Init (void) 
{
	uint32 BR_Value = 0 ;
	DIO_SetPinDir(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT);
	DIO_SetPinDir(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);
	UCSRB |= 0x18 ;
	UCSRC |= 0x86 ;
	BR_Value = ((160000)/(96 * 16)) -1 ;
	UBRRL = BR_Value ;
	//ENABLE Rx INT
	SET_BIT(UCSRB,7);
	//ENABLE global INT
	SET_BIT(SREG,7);
	
}

void UART_SendByte (uint8 byte) 
{
	while(GET_BIT(UCSRA,5) == 0);
	UDR = byte ;
}

void UART_SendString (uint8* str) 
{
	uint8 coun = 0 ;
	while(str[coun] != '\0')
	{
		UART_SendByte (str[coun]);
		coun ++;
	}
}

static void(*uatr_ptr_func)(uint8 data);

void Set_CallBack(void(*ptr)(uint8))
{
	uatr_ptr_func = ptr ;
}


void UART_ReceiveString (uint8* str)
{
	
}



