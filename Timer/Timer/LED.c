
#include "LED.h"

          /*********************************LED0 IN AMIT KIT**************************************/
		  
void LED0_Init(void)
{
	
	DIO_SetPinDir  (DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	
}

void LED0_ON(void)
{
	DIO_WritePin(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);	
}

void LED0_OFF(void)
{
	DIO_WritePin   (DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
}

void LED0_toggle(void)
{
	DIO_ToqqlePin  (DIO_PORTC,DIO_PIN2);
	
}

          /*********************************LED1 IN AMIT KIT**************************************/
		  
void LED1_Init(void)
{
	
	DIO_SetPinDir  (DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
	
}

void LED1_ON(void)
{
	DIO_WritePin(DIO_PORTC,DIO_PIN7,DIO_PIN_HIGH);
}

void LED1_OFF(void)
{
	DIO_WritePin   (DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
}

void LED1_toggle(void)
{
	DIO_ToqqlePin  (DIO_PORTC,DIO_PIN7);
	
}
		  
		  /*********************************LED2 IN AMIT KIT**************************************/
		  
void LED2_Init(void)
{
	DIO_SetPinDir  (DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);
}

void LED2_ON(void)
{
	DIO_WritePin(DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);
}

void LED2_OFF(void)
{
	DIO_WritePin   (DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);
}

void LED2_toggle(void)
{
	DIO_ToqqlePin  (DIO_PORTD,DIO_PIN3);
	
}