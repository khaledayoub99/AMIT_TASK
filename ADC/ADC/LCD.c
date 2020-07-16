

#include "LCD.h"


void LCD_INIT			(void )
{
	#if LCD_MODE == 8
	
	
	
	DIO_SetPinDir(LCD_8PIT_CMD_PORT,LCD_RS_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_8PIT_CMD_PORT,LCD_RW_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_8PIT_CMD_PORT,LCD_E_PIN,DIO_PIN_OUTPUT );
	
	DIO_SetPortDir(LCD_8PIT_DATA_PORT,DIO_PORT_OUTPUT);
	_delay_ms(100);
	
	LCD_WrtieCommand(0x38);
	LCD_WrtieCommand(0x0C);
	LCD_WrtieCommand(0x01);
	
	_delay_ms(20);
	
	LCD_WrtieCommand(0x06);
	
	_delay_ms(5);

	
	#elif LCD_MODE == 4
	
	
	
	DIO_SetPinDir(LCD_4PIT_CMD_PORT,LCD_RS_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4PIT_CMD_PORT,LCD_RW_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4PIT_CMD_PORT,LCD_E_PIN,DIO_PIN_OUTPUT );
	
	DIO_SetPinDir(LCD_4PIT_DATA_PORT,LCD_D4_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4PIT_DATA_PORT,LCD_D5_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4PIT_DATA_PORT,LCD_D6_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4PIT_DATA_PORT,LCD_D7_PIN,DIO_PIN_OUTPUT);
	_delay_ms(100);
	
	LCD_WrtieCommand(0x33);
	LCD_WrtieCommand(0x32);
	LCD_WrtieCommand(0x28);
	
	LCD_WrtieCommand(0x0C);
	LCD_WrtieCommand(0x01);
	LCD_WrtieCommand(0x06);
    LCD_WrtieCommand(0x02);


	
	
	

	#endif
}
void LCD_WrtieCommand (uint8 cmd )
{
	#if LCD_MODE == 8
	
	DIO_SetPinDir(LCD_8PIT_CMD_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	DIO_SetPinDir(LCD_8PIT_CMD_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	DIO_SetPinDir(LCD_8PIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW );
	
	DIO_WritePort(LCD_8PIT_DATA_PORT,cmd);
	
	DIO_SetPinDir(LCD_8PIT_CMD_PORT,LCD_E_PIN,DIO_PIN_HIGH );
	_delay_ms(1);
	DIO_SetPinDir(LCD_8PIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW );
	
	_delay_ms(5);
	
	
	#elif LCD_MODE == 4
	
	
	DIO_WritePin(LCD_4PIT_CMD_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	DIO_WritePin(LCD_4PIT_CMD_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	DIO_WritePin(LCD_4PIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW );
	
	PORTA = ( cmd & 0xF0 ) |(PORTA & 0x0F ) ;
	
	DIO_WritePin(LCD_4PIT_CMD_PORT,LCD_E_PIN,DIO_PIN_HIGH );
	_delay_ms(1);
	DIO_WritePin(LCD_4PIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW );
	
	PORTA = ( cmd << 4 ) |(PORTA & 0x0F ) ;
	
	DIO_WritePin(LCD_4PIT_CMD_PORT,LCD_E_PIN,DIO_PIN_HIGH );
	_delay_ms(1);
	DIO_WritePin(LCD_4PIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW );
	
	_delay_ms(5);
	
	
	#endif
}

void LCD_WrtieChar  (uint8 chr )
{
	
	#if LCD_MODE == 8
	
	DIO_WritePin(LCD_8PIT_CMD_PORT,LCD_RS_PIN,DIO_PIN_HIGH);
	DIO_WritePin(LCD_8PIT_CMD_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	DIO_WritePin(LCD_8PIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW );
	
	DIO_WritePort(LCD_8PIT_DATA_PORT,chr);
	
	DIO_SetPinDir(LCD_8PIT_CMD_PORT,LCD_E_PIN,DIO_PIN_HIGH );
	_delay_ms(1);
	DIO_SetPinDir(LCD_8PIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW );
	
	_delay_ms(5);
	
	
	#elif LCD_MODE == 4
	
	
	DIO_WritePin(LCD_4PIT_CMD_PORT,LCD_RS_PIN,DIO_PIN_HIGH);
	DIO_WritePin(LCD_4PIT_CMD_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	DIO_WritePin(LCD_4PIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW );
	
	PORTA = ( chr & 0xF0 ) ;
	
	DIO_WritePin(LCD_4PIT_CMD_PORT,LCD_E_PIN,DIO_PIN_HIGH );
	_delay_ms(1);
	DIO_WritePin(LCD_4PIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW );
	
	PORTA = ( chr << 4 ) ;
	
	DIO_WritePin(LCD_4PIT_CMD_PORT,LCD_E_PIN,DIO_PIN_HIGH );
	_delay_ms(1);
	DIO_WritePin(LCD_4PIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW );
	
	_delay_ms(5);
	
	
	#endif
	
}
void LCD_WrtieString (uint8* str ) 
{
	uint8 i=0;
	while( str[i] != '\0')
	{
			LCD_WrtieChar(str[i]);
			i++;
	}
	
}


void LCD_Clear (void)
{
		LCD_WrtieCommand(0x01);


}
void LCD_GoTo 			(uint8 row, uint8 col)
{
	
	uint8 arr[]={0x80,0xc0};
	LCD_WrtieCommand(arr[row]+col);
	
}

void LCD_WrtieNumber(int32 num )
{
	int32 temp = 1;
	
	if(num<0)
	{
		num*=-1;
		LCD_WrtieChar('-');
	}
	
	while (num > 0) {
		temp=((temp*10)+(num % 10));
		num /= 10;
	}
	while(temp > 1 )
	{
		LCD_WrtieChar(((temp%10)+48));
		temp /= 10;
	}
	
}