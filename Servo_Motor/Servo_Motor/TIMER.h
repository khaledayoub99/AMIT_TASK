
#ifndef TIMMER_H_
#define TIMMER_H_

#include "Timer_Cfg.h"
#include "ATMEGA32_Regs.h"


#define Timer_Normal_Mode       0
#define Timer_CTC_Mode		    1
#define Timer_PWM_phase_Mode    2
#define Timer_Fast_PWM_Mode     3

#define Timer_PWM_INVERTED      0
#define Timer_PWM_NON_INVERTED  1


#define Timer_PRESCALER_1			0
#define Timer_PRESCALER_8			1
#define Timer_PRESCALER_64			2
#define Timer_PRESCALER_256			3
#define Timer_PRESCALER_1024		4
#define Timer_PRESCALER_EXT_FAL	    5
#define Timer_PRESCALER_EXT_RIS	    6


/************ TIMER0 ***********/

void Timer0_INIT(void);

void Timer0_Start(void);

void Timer0_Stop(void);

void Timer0_SetDelay(uint32 delay_ms);

void Timer0_SetCallBack(void(*ptr)(void));

void Timer0_PWM_INIT(void);

void Timer0_PWM_GENR(uint16 Duty_Cycle);

void Timer0_PWM_START(void);



 /************ TIMER1 ***********/
 
 void Timer1_INIT(void);

 void Timer1_Start(void);

 void Timer1_Stop(void);

 void Timer1_SetDelay(uint32 delay_ms);

 void Timer1_SetCallBack(void(*ptr)(void));
 
 void PWM1_Init(void);
 
 void PWM1_Gene(uint8 duty_cycle);
 
 void PWM1_Start(void);



#endif /* TIMMER_H_ */