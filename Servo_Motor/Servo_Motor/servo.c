

#include "servo.h"

void Servo_Init(void)
{
	DIO_SetPinDir(PORTD,DIO_PIN5,DIO_PIN_OUTPUT);
	PWM1_Init();
}

void Servo_SetDegree(uint8 degree)
{
	uint32 duty =0 ;
	duty = 5 + ((degree*5)/180) ;
	PWM1_Gene(duty);
}

void Servo_Strat(void)
{
	PWM1_Start();
}
