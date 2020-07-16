#ifndef LCD_CFG_H
#define LCD_CFG_H

#include "DIO.h"

#define LCD_MODE   4

#define LCD_8PIT_DATA_PORT   DIO_PORTA
#define LCD_8PIT_CMD_PORT    DIO_PORTB

#define LCD_4PIT_DATA_PORT   DIO_PORTA
#define LCD_4PIT_CMD_PORT    DIO_PORTB

#define LCD_RS_PIN          DIO_PIN1
#define LCD_RW_PIN          DIO_PIN2
#define LCD_E_PIN           DIO_PIN3

#define LCD_D0_PIN              DIO_PIN0
#define LCD_D1_PIN              DIO_PIN1
#define LCD_D2_PIN	    	    DIO_PIN2
#define LCD_D3_PIN              DIO_PIN3
#define LCD_D4_PIN              DIO_PIN4
#define LCD_D5_PIN              DIO_PIN5
#define LCD_D6_PIN              DIO_PIN6
#define LCD_D7_PIN              DIO_PIN7




#endif // LCD_CFG_H