/*
 * TIMMER.c
 *
 * Created: 7/17/2020 12:28:51 PM
 * Author : KhaledMohamedElsayed
 */ 
#include "TIMER.h"
#include "LED.h"
#include <avr/interrupt.h>


extern uint8 Init_Value ;
extern uint32 Num_OVF ;


int main(void)
{
	LED0_Init();
	LED0_ON();
	Timer0_INIT();
	Timer0_SetDelay(1000);
	Timer0_Start();
	
    while (1) 
    {
		
    }
}

ISR(TIMER0_OVF_vect)
{
	static uint32 CT =0; 
	
	CT++;
	
	if (CT==Num_OVF)
	{
		CT = 0 ;
		TCNT0   = Init_Value;
		LED0_toggle();
	}
	
}