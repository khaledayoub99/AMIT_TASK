

#include "servo.h"

void Servo_Init(void)
{
	DIO_SetPinDir(PORTD,DIO_PIN5,DIO_PIN_OUTPUT);
	PWM1_Init();
	PWM1_Start();
}

void Servo_SetDegree(uint8 degree)
{
	
}

void Servo_Strat(void);
