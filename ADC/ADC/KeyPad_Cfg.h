#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_


#include "DIO.h"

#define		KeyPad_PORT		DIO_PORTD

#define		KeyPad_COLUM_0	DIO_PIN0
#define		KeyPad_COLUM_1	DIO_PIN1
#define		KeyPad_COLUM_2	DIO_PIN2
#define		KeyPad_COLUM_3	DIO_PIN3

#define		KeyPad_ROW_0	DIO_PIN7
#define		KeyPad_ROW_1	DIO_PIN6
#define		KeyPad_ROW_2	DIO_PIN5
#define		KeyPad_ROW_3	DIO_PIN4



#define		ROW_INIT	4
#define		ROW_FINAL	7

#define		COL_INIT	0
#define		COL_FINAL	3

#define		NOT_PRESSED	O






#endif /* KEYPAD_CFG_H_ */