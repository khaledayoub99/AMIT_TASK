

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "DIO.h"
#include "TIMER.h"

void DcMotor_INIT(void);

typedef enum {
	CLK_Wise_DIR,
	ANTI_CLK_Wise_DIR
	}DC_Motor_DIR;
	
void DcMotor_SetSpeed(uint8 speed);

void DcMotor_SetDir(DC_Motor_DIR dir);

void DcMotor_Start(void);

void DcMotor_Stop(void);


#endif /* DCMOTOR_H_ */