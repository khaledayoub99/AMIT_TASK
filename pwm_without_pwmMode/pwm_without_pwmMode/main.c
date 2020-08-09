/*
 * pwm_without_pwmMode.c
 *
 * Created: 8/9/2020 10:30:10 PM
 * Author : KhaledMohamedElsayed
 */ 


#define F_CPU 16000000
#include <util/delay.h>
#include "Pwm_Without_PwmMode.h"

int main(void)
{
	
	Timer_TASK_Init();
	Pwm_TASK_SetDuyt(90);
	Pwm_TASK_Start();
	
	while (1)
	{
		
		
		
		
	}
	
}



