
#include "TIMER.h"
#include "BIT_Math.h"
#include <avr/interrupt.h>



/************ TIMER0 ***********/

static uint32 Num_OVF    = 0 ;
static uint8  Init_Value = 0 ;
static void (*ptr_Timer0)(void);


void Timer0_INIT(void)
{
	#if TIMER0_MODE==Timer_Normal_Mode
	
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	
	SET_BIT(TIMSK,0);
	SET_BIT(SREG, 7);
	
	#elif TIMER0_MODE==Timer_CTC_Mode
	
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	
	SET_BIT(TIMSK,1);
	SET_BIT(SREG, 7);
	
	
	#elif TIMER0_MODE==Timer_PWM_phase_Mode
	
	CLR_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	
		#if   TIMER0_PWM==Timer_PWM_NON_INVERTED
		
		CLR_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
		
		#elif TIMER0_PWM==Timer_PWM_INVERTED
		
		SET_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
		
		#endif
	
	#elif TIMER0_MODE==Timer_Fast_PWM_Mode
	
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	
		#if   TIMER0_PWM==Timer_PWM_NON_INVERTED
	
		CLR_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
	
		#elif TIMER0_PWM==Timer_PWM_INVERTED
	
		SET_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
	
		#endif
	
	#endif
}


void Timer0_Start(void)
{
	#if TIMER0_PRESCALER==Timer_PRESCALER_1
	
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
	
	#elif TIMER0_PRESCALER==Timer_PRESCALER_8
	
	CLR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
	
	#elif TIMER0_PRESCALER==Timer_PRESCALER_64
	
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
	
	#elif TIMER0_PRESCALER==Timer_PRESCALER_256
	
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
	
	#elif TIMER0_PRESCALER==Timer_PRESCALER_1024
	
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
	
	
	#elif TIMER0_PRESCALER==Timer_PRESCALER_EXT_FAL
	
	CLR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
	
	#elif TIMER0_PRESCALER==Timer_PRESCALER_EXT_RIS
	
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);

    #endif
	
}


void Timer0_Stop(void)
{
	
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
	
}


void Timer0_SetDelay(uint32 delay_Ms)
{
	#if TIMER0_MODE==Timer_Normal_Mode


	#if		 TIMER0_PRESCALER==Timer_PRESCALER_1
	
	uint8  Tick_Time_us =  (1 / 16) ;
	uint32 Num_Tick     =  (delay_Ms*1000) / Tick_Time_us  ;
	Num_OVF    = Num_Tick / 256 ;
	Init_Value = 256 - (Num_Tick % 256) ;
	TCNT0      = Init_Value;
	Num_OVF ++ ;
	
	#elif	 TIMER0_PRESCALER==Timer_PRESCALER_8
	
	uint8  Tick_Time_us =  (8 / 16) ;
	uint32 Num_Tick     =  (delay_Ms*1000) / Tick_Time_us  ;
	Num_OVF    = Num_Tick / 256 ;
	Init_Value = 256 - (Num_Tick % 256) ;
	TCNT0      = Init_Value;
	Num_OVF ++ ;
	
	#elif	 TIMER0_PRESCALER==Timer_PRESCALER_64
	
	uint8  Tick_Time_us =  (64 / 16) ;
	uint32 Num_Tick     =  (delay_Ms*1000) / Tick_Time_us  ;
	Num_OVF    = Num_Tick / 256 ;
	Init_Value = 256 - (Num_Tick % 256) ;
	TCNT0      = Init_Value;
	Num_OVF ++ ;
	
	#elif	 TIMER0_PRESCALER==Timer_PRESCALER_256
	
	uint8  Tick_Time_us =  (256 / 16) ;
	uint32 Num_Tick     =  (delay_Ms*1000) / Tick_Time_us  ;
	Num_OVF    = Num_Tick / 256 ;
	Init_Value = 256 - (Num_Tick % 256) ;
	TCNT0      = Init_Value;
	Num_OVF ++ ;
	
	#elif	 TIMER0_PRESCALER==Timer_PRESCALER_1024
	
	uint8  Tick_Time_us =  (1024 / 16) ;
	uint32 Num_Tick     =  (delay_Ms*1000) / Tick_Time_us  ;
	Num_OVF    = Num_Tick / 256 ;
	Init_Value = 256 - (Num_Tick % 256) ;
	TCNT0      = Init_Value;
	Num_OVF ++ ;
	
	
	
	#elif	 TIMER0_PRESCALER==Timer_PRESCALER_EXT_FAL
	
	#elif	 TIMER0_PRESCALER==Timer_PRESCALER_EXT_RIS

    #endif
	
	
	#elif TIMER0_MODE==Tmeir_CTC_Mode
	
	#if	TIMER0_PRESCALER==Timer_PRESCALER_1
	
	#elif	 TIMER0_PRESCALER==Timer_PRESCALER_8
	
	#elif	 TIMER0_PRESCALER==Timer_PRESCALER_64
	
	#elif	 TIMER0_PRESCALER==Timer_PRESCALER_256
	
	#elif	 TIMER0_PRESCALER==Timer_PRESCALER_1024
	
	#elif	 TIMER0_PRESCALER==Timer_PRESCALER_EXT_FAL
	
	#elif	 TIMER0_PRESCALER==Timer_PRESCALER_EXT_RIS

	
	#endif
	#endif
	
	
}

void Timer0_PWM_GENR(uint16 Duty_Cycle)
{
	OCR0 = ((Duty_Cycle*256)/100)-1 ;
	
}


void Timer0_SetCallBack(void (*ptr)(void))
{
	ptr_Timer0 = ptr;
}

ISR(TIMER0_OVF_vect)
{
	static uint32 CT =0;
	
	CT++;
	
	if (CT==Num_OVF)
	{
		CT = 0 ;
		TCNT0   = Init_Value;
		(*ptr_Timer0)();
	}
	
}

/*
ISR(TIMER0_COMP_vect)
{
	static uint32 COUNT = 0 ;
	COUNT ++;
	if(COUNT == Num_CompMatch){
		COUNT=0;
		(*ptr_Timer0)();
	}
}
*/


/************ TIMER1 ***********/

static uint32 Num1_OVF    = 0 ;
static uint8  Init1_Value = 0 ;
uint32 Num_CompMatch = 0 ;
static void (*ptr_Timer1)(void);


void Timer1_INIT(void)
{
	#if TIMER0_MODE==Timer_Normal_Mode
	
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);
	
	SET_BIT(TIMSK,2);
	SET_BIT(SREG, 7);
	
	#elif TIMER0_MODE==Timer_CTC_Mode
	
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);
	
	SET_BIT(TIMSK,3);
	SET_BIT(SREG, 7);
	
	
	#elif TIMER0_MODE==Timer_PWM_phase_Mode
	
	SET_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	
	#if   TIMER0_PWM==Timer_PWM_NON_INVERTED
	
	CLR_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,5);
	
	#elif TIMER0_PWM==Timer_PWM_INVERTED
	
	SET_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,5);
	
	#endif
	
	#elif TIMER0_MODE==Timer_Fast_PWM_Mode
	
	SET_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	
	#if   TIMER0_PWM==Timer_PWM_NON_INVERTED
	
	CLR_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,5);
	
	#elif TIMER0_PWM==Timer_PWM_INVERTED
	
	SET_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,5);
	
	#endif
	#endif
	
	
}

void Timer1_Start(void)
{
	#if TIMER0_PRESCALER==Timer_PRESCALER_0
	
	SET_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
	
	#elif TIMER0_PRESCALER==Timer_PRESCALER_8
	
	CLR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
	
	#elif TIMER0_PRESCALER==Timer_PRESCALER_64
	
	SET_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
	
	#elif TIMER0_PRESCALER==Timer_PRESCALER_256
	
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);
	
	#elif TIMER0_PRESCALER==Timer_PRESCALER_1024
	
	SET_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);
	
	
	#elif TIMER0_PRESCALER==Timer_PRESCALER_EXT_FAL
	
	CLR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);
	
	#elif TIMER0_PRESCALER==Timer_PRESCALER_EXT_RIS
	
	SET_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);

	#endif
}


void Timer1_Stop(void)
{
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
}

void Timer1_SetDelay(uint32 delay_ms)
{
	#if TIMER1_MODE==Timer_CTC_Mode
	
	#if		 TIMER0_PRESCALER==Timer_PRESCALER_1
	
	if (delay_ms<4000)
	{
		uint8  Tick_Time  = 1/16 ;
		uint32 Num_ticks  = (delay_ms*1000) / Tick_Time ;
		OCR1A = Num_ticks - 1 ;
		Num_CompMatch = 1 ;
	}
	
	#elif	 TIMER0_PRESCALER==Timer_PRESCALER_8
	
	if (delay_ms<4000)
	{
		uint8  Tick_Time  = 8/16 ;
		uint32 Num_ticks  = (delay_ms*1000) / Tick_Time ;
		OCR1A = Num_ticks - 1 ;
		Num_CompMatch = 1 ;
	}
	
	#elif	 TIMER0_PRESCALER==Timer_PRESCALER_64
	
	if (delay_ms<4000)
	{
		uint8  Tick_Time  = 64/16 ;
		uint32 Num_ticks  = (delay_ms*1000) / Tick_Time ;
		OCR1A = Num_ticks - 1 ;
		Num_CompMatch = 1 ;
	}
	
	#elif	 TIMER0_PRESCALER==Timer_PRESCALER_256
	
	if (delay_ms<4000)
	{
		uint8  Tick_Time  = 256/16 ;
		uint32 Num_ticks  = (delay_ms*1000) / Tick_Time ;
		OCR1A = Num_ticks - 1 ;
		Num_CompMatch = 1 ;
	}
	
	#elif	 TIMER0_PRESCALER==Timer_PRESCALER_1024
	
	if (delay_ms<4000)
	{
		uint8  Tick_Time  = 1024/16 ;
		uint32 Num_ticks  = (delay_ms*1000) / Tick_Time ;
		OCR1A = Num_ticks - 1 ;
		Num_CompMatch = 1 ;
	}
	
	#elif	 TIMER0_PRESCALER==Timer_PRESCALER_EXT_FAL
	
	#elif	 TIMER0_PRESCALER==Timer_PRESCALER_EXT_RIS

	#endif
	
	#elif TIMER1_MODE==Timer_Normal_Mode
	
	#if		 TIMER0_PRESCALER==Timer_PRESCALER_1
	
	
	
	#elif	 TIMER0_PRESCALER==Timer_PRESCALER_8
	
	
	
	#elif	 TIMER0_PRESCALER==Timer_PRESCALER_64
	
	
	
	#elif	 TIMER0_PRESCALER==Timer_PRESCALER_256
	
	
	
	#elif	 TIMER0_PRESCALER==Timer_PRESCALER_1024
	
	
	#elif	 TIMER0_PRESCALER==Timer_PRESCALER_EXT_FAL
	
	#elif	 TIMER0_PRESCALER==Timer_PRESCALER_EXT_RIS

	#endif
	
	#endif
	
}

void Timer1_SetCallBack(void(*ptr)(void))
{
	ptr_Timer1 =ptr ;
}

ISR(TIMER1_OVF_vect)
{
	static uint32 CT =0;
	
	CT++;
	
	if (CT==Num1_OVF)
	{
		CT = 0 ;
		TCNT0   = Init1_Value;
		(*ptr_Timer1)();
	}
	
}

ISR(TIMER1_COMPA_vect)
{
	static uint32 COUNT = 0 ;
	COUNT ++;
	if(COUNT == Num_CompMatch){
		COUNT=0;
		(*ptr_Timer1)();
	}
}



void PWM1_Init(void)
{
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	
	ICR1= 1250;
}


void PWM1_Gene(uint8 duty_cycle)
{
	OCR1A =((duty_cycle*1250)/100)-1 ;
}


void PWM1_Start(void)
 {
	 CLR_BIT(TCCR1B,0);
	 CLR_BIT(TCCR1B,1);
	 SET_BIT(TCCR1B,2);
 }