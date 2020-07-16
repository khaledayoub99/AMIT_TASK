
#include "KeyPad.h"
#define F_CPU 16000000
#include <util/delay.h>


const uint8 KeyPad_Values[4][4] = {{'1','2','3','+'},
								   {'4','5','6','-'},
								   {'7','8','9','c'},
								   {'*','0','/','='}};
void	KeyPad_Init(void)
{
	
	DIO_SetPinDir  (KeyPad_PORT , KeyPad_ROW_0 , DIO_PIN_INPUT);
	DIO_SetPinDir  (KeyPad_PORT , KeyPad_ROW_1 , DIO_PIN_INPUT);
	DIO_SetPinDir  (KeyPad_PORT , KeyPad_ROW_2 , DIO_PIN_INPUT);
	DIO_SetPinDir  (KeyPad_PORT , KeyPad_ROW_3 , DIO_PIN_INPUT);
	
	DIO_SetPinDir  (KeyPad_PORT , KeyPad_COLUM_0 , DIO_PIN_OUTPUT);
	DIO_SetPinDir  (KeyPad_PORT , KeyPad_COLUM_1 , DIO_PIN_OUTPUT);
	DIO_SetPinDir  (KeyPad_PORT , KeyPad_COLUM_2 , DIO_PIN_OUTPUT);
	DIO_SetPinDir  (KeyPad_PORT , KeyPad_COLUM_3 , DIO_PIN_OUTPUT);
	
	DIO_SetPullUp  (KeyPad_PORT , KeyPad_ROW_0);
	DIO_SetPullUp  (KeyPad_PORT , KeyPad_ROW_1);
	DIO_SetPullUp  (KeyPad_PORT , KeyPad_ROW_2);
	DIO_SetPullUp  (KeyPad_PORT , KeyPad_ROW_3);

	
	DIO_WritePin   (KeyPad_PORT , KeyPad_COLUM_0 , DIO_PIN_HIGH);
	DIO_WritePin   (KeyPad_PORT , KeyPad_COLUM_1 , DIO_PIN_HIGH);
	DIO_WritePin   (KeyPad_PORT , KeyPad_COLUM_2 , DIO_PIN_HIGH);
	DIO_WritePin   (KeyPad_PORT , KeyPad_COLUM_3 , DIO_PIN_HIGH);

	
}
uint8	KeyPad_GetValue(uint8 *value)
{
	
	uint8 LOC_Coloum = 0 ;
	uint8 LOC_Row = 0 ;
	//uint8 value = 0 ;
	uint8 temp = 0 ;
	
	for(LOC_Coloum = COL_INIT ; LOC_Coloum <= COL_FINAL ; LOC_Coloum++)
	{
		DIO_WritePin(KeyPad_PORT,LOC_Coloum,DIO_PIN_LOW);
		for(LOC_Row = ROW_INIT ; LOC_Row <= ROW_FINAL ; LOC_Row++)
		{
			DIO_ReadPin(KeyPad_PORT,LOC_Row,&temp);
			if (!temp)
			{
				value = KeyPad_Values[LOC_Coloum - COL_INIT][LOC_Row - ROW_INIT];
				while(!temp)
				{
					DIO_ReadPin(KeyPad_PORT,LOC_Row,&temp);
				}
				_delay_ms(10);
			}
		}
		DIO_WritePin(KeyPad_PORT,LOC_Coloum,DIO_PIN_HIGH);
	}
	return value;
}
