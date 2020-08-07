/*
 * DCMotor.c
 *
 * Created: 7/24/2020 10:33:59 AM
 * Author : KhaledMohamedElsayed
 */ 

#include "DcMotor.h"

int main(void)
{
    DcMotor_INIT();
	DcMotor_SetDir(CLK_Wise_DIR);
	DcMotor_SetSpeed(10);
	DcMotor_Start();
    while (1) 
    {
    }
}

