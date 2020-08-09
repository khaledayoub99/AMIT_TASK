

#ifndef PWM_WITHOUT_PWMMODE_H_
#define PWM_WITHOUT_PWMMODE_H_


#include "DIO.h"

void Timer_TASK_Init(void);

void Pwm_TASK_SetDuyt(uint8 Duty);

void Pwm_TASK_Start(void);

#endif /* PWM_WITHOUT_PWMMODE_H_ */