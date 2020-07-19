
#ifndef TIMMER_H_
#define TIMMER_H_

#include "ATMEGA32_Regs.h"


void Timer0_INIT(void);


void Timer0_Start(void);


void Timer0_Stop(void);


void Timer0_SetDelay(uint32 delay_ms);


void Timer0_SetCallBack(void(*ptr)(void));



#endif /* TIMMER_H_ */