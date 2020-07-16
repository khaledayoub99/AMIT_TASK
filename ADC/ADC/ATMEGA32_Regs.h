#ifndef ATMEGA32_REG_H
#define ATMEGA32_REG_H

#include "STD.h"

/************EXTERNAL_REGISTER******************/


#define SREG	(*(volatile uint8*)(0x5F))

#define GICR	(*(volatile uint8*)(0x5B))
 
#define MCUCR	(*(volatile uint8*)(0x55))

#define MCUCSR	(*(volatile uint8*)(0x54))

#define GIFR	(*(volatile uint8*)(0x5A))


/************DIO_REGISTER******************/
#define PORTA (*(volatile uint8*)(0x3B))
#define PINA  (*(volatile uint8*)(0x39))
#define DDRA  (*(volatile uint8*)(0x3A))

#define PORTB (*(volatile uint8*)(0x38))
#define PINB  (*(volatile uint8*)(0x36))
#define DDRB  (*(volatile uint8*)(0x37))

#define PORTC (*((volatile uint8*)(0x35)))
#define PINC  (*((volatile uint8*)(0x33)))
#define DDRC  (*((volatile uint8*)(0x34)))

#define PORTD (*(volatile uint8*)(0x32))
#define PIND  (*(volatile uint8*)(0x30))
#define DDRD  (*(volatile uint8*)(0x31))


/************DIO_REGISTER******************/

#define ADMAX        (*(volatile uint8*) (0x27))
#define ADCSRA       (*(volatile uint8*) (0x26))
#define ADCH         (*(volatile uint8*) (0x25))
#define ADCL         (*(volatile uint8*) (0x24))
#define ADC_RESULT   (*(volatile uint16*)(0x24))
#define SFIOR	     (*(volatile uint8*) (0x50))

#endif // ATMEGA32_REG_H