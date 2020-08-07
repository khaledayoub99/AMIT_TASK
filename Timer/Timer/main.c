/*
 * TIMMER.c
 *
 * Created: 7/17/2020 12:28:51 PM
 * Author : KhaledMohamedElsayed
 */ 
#include "TIMER.h"
#include "LED.h"



int main(void)
{
	LED0_Init();
	Timer0_SetCallBack(LED0_toggle);
	Timer0_INIT();
	Timer0_SetDelay(1000);
	Timer0_Start();
	
    while (1) 
    {
		
    }
}

