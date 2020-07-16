#ifndef LCD_H
#define LCD_H

#define  F_CPU 16000000
#include <util/delay.h>
#include "LCD_Cfg.h"

void LCD_INIT				(		void		 );
void LCD_WrtieCommand		(	uint8   cmd		 );
void LCD_WrtieChar			(	uint8   chr		 );
void LCD_WrtieString		(	uint8*  str		 );
void LCD_WrtieNumber		(	int32   num		 );
void LCD_Clear				(		void		 );
void LCD_GoTo 				(uint8 row, uint8 col);



#endif // LCD_H