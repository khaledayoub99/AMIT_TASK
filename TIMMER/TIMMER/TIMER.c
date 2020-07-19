
#include "TIMER.h"
#include "BIT_Math.h"

uint32 Num_OVF    = 0 ;
uint8  Init_Value = 0 ;

void Timer0_INIT(void)
{
	 
	TCCR0 |= 0x00;
	
	TIMSK |= 0x01;
	
	SREG  |= 0x80;
	
}


void Timer0_Start(void)
{
	
	TCCR0 |= 0x05;
	
}


void Timer0_Stop(void)
{
	
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
	
}


void Timer0_SetDelay(uint32 delay_Ms)
{
	
	uint8  Tick_Time_us =  (1024 / 16) ;
	uint32 Num_Tick     =  (delay_Ms*1000) / Tick_Time_us  ;
	Num_OVF    = Num_Tick / 256 ;
	Init_Value = 256 - (Num_Tick % 256) ;
	TCNT0      = Init_Value;
	Num_OVF ++ ;
	
}


void Timer0_SetCallBack(void(*ptr)(void))
{
	
}


