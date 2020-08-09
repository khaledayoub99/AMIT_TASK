
#include "Pwm_Without_PwmMode.h"
#include <avr/interrupt.h>
		
void Timer_TASK_Init(void)
{
	//  NORMAL MODE
	TCCR0 |= 0x00 ;
	
	// INT ENANLE
	
	TIMSK |= 0x01 ;
	SREG  |= 0x80 ;
	
	
}

uint8 NUM_ON_INIT = 0 ;
uint8 NUM_OFF_INIT = 0 ;

void Pwm_TASK_SetDuyt(uint8 Duty)
{
	NUM_ON_INIT =256 - (((Duty * 256 ) /100 ) - 1);
	TCNT0 = NUM_ON_INIT ;
	NUM_OFF_INIT = 256 - ((((100-Duty) * 256 ) /100 ) - 1);
	
	
	// DC MOTOR AS OUTPUT
	DIO_SetPinDir(DIO_PORTB , DIO_PIN2 , DIO_PIN_OUTPUT);
	
	DIO_SetPinDir(DIO_PORTC , DIO_PIN3 , DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTC , DIO_PIN4 , DIO_PIN_OUTPUT);
	
	

	
}

void Pwm_TASK_Start(void)
{
	//  CLK / 64
	
	TCCR0 |= 0x03 ;
	
	DIO_WritePin(DIO_PORTB , DIO_PIN2 , DIO_PIN_HIGH);
	
	DIO_WritePin(DIO_PORTC , DIO_PIN3 , DIO_PIN_HIGH);
	DIO_WritePin(DIO_PORTC , DIO_PIN4 , DIO_PIN_LOW) ;
	
}


ISR(TIMER0_OVF_vect)
{
	
	static uint8 COUN = 0 ;
	COUN ++ ;
	if (COUN==1)
	{
		DIO_WritePin(DIO_PORTB , DIO_PIN2 , DIO_PIN_LOW);
		TCNT0 = NUM_OFF_INIT ;
	}
	else if (COUN==2)
	{
		DIO_WritePin(DIO_PORTB , DIO_PIN2 , DIO_PIN_HIGH);
		TCNT0 = NUM_ON_INIT ;
		COUN = 0 ;
	}

}