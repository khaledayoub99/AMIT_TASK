
#include "DcMotor.h"

void DcMotor_INIT(void)
{
	DIO_SetPinDir  (DIO_PORTC , DIO_PIN3 , DIO_PIN_OUTPUT);
	DIO_SetPinDir  (DIO_PORTC , DIO_PIN4 , DIO_PIN_OUTPUT);
	DIO_SetPinDir  (DIO_PORTB , DIO_PIN3 , DIO_PIN_OUTPUT);
	Timer0_INIT();
}


void DcMotor_SetSpeed(uint8 speed)
{
	speed*=10 ;
	Timer0_PWM_GENR(speed);
}

void DcMotor_SetDir(DC_Motor_DIR dir)
{
	switch(dir){
		case CLK_Wise_DIR :
	DIO_WritePin   (DIO_PORTC , DIO_PIN3 , DIO_PIN_HIGH);
	DIO_WritePin   (DIO_PORTC , DIO_PIN4 , DIO_PIN_LOW);
		case ANTI_CLK_Wise_DIR :
		DIO_WritePin   (DIO_PORTC , DIO_PIN4 , DIO_PIN_LOW);
		DIO_WritePin   (DIO_PORTC , DIO_PIN3 , DIO_PIN_HIGH);
	}
}

void DcMotor_Start(void)
{
	Timer0_Start();
}

void DcMotor_Stop(void)
{
	DIO_WritePin   (DIO_PORTC , DIO_PIN3 , DIO_PIN_LOW);
	DIO_WritePin   (DIO_PORTC , DIO_PIN4 , DIO_PIN_LOW);
}