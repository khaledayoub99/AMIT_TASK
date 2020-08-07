

#ifndef UART_H_
#define UART_H_

#include "DIO.h"

void UART_Init (void) ;

void UART_SendByte (uint8 byte) ;

void UART_SendString (uint8* str) ;

uint8 UART_ReceiveByte (void) ;

void UART_ReceiveString (uint8* str) ;



#endif /* UART_H_ */