/*
 * Servo_Motor.c
 *
 * Created: 7/24/2020 12:29:42 PM
 * Author : KhaledMohamedElsayed
 */ 

#include "servo.h"


int main(void)
{
    Servo_Init();
	PWM1_Gene(9);
	PWM1_Start();
    while (1) 
    {
    }
}

