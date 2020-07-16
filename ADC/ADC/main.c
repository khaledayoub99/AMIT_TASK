/*
 * ADC.c
 *
 * Created: 7/16/2020 5:50:57 PM
 * Author : KhaledMohamedElsayed
 */ 

#define F_CPU 16000000
#include <util/delay.h>
#include "LCD.h"
#include "KeyPad.h"
#include "Temp_Sensor.h"



int main(void)
{
	uint16 temp = 0 ;
	uint8 pass[4]={1,2,3,4};
	uint8 try[4];
	uint8 value=0;
    LCD_INIT();
	KeyPad_Init();
	TempSensor_Init();
	LCD_WrtieString("Password plz");
	uint8 i=0;
	while(i<4)
	{
		value=0;
		while(!KeyPad_GetValue(&value));
		try[i]=value;
		i++;
	}
	if (pass[0]==try[0]&&pass[1]==try[1]&&pass[2]==try[2]&&pass[3]==try[3])
	{
    while (1) 
    {
		LCD_Clear();
		TempSensor_Read(&temp);
		LCD_WrtieNumber(temp);
    }
	}
	else{
		LCD_Clear();
		LCD_WrtieString("Password is wrong");
	}

}
