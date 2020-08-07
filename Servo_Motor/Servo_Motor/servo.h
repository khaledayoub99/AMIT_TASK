

#ifndef SERVO_H_
#define SERVO_H_

#include "TIMER.h"
#include "DIO.h"

void Servo_Init(void);

void Servo_SetDegree(uint8 degree);

void Servo_Strat(void);

#endif /* SERVO_H_ */