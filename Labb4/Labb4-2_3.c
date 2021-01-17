/*
 * Labb4-2.c
 *
 * Created: 2020-02-29 14:20:13
 * Author : ma8148so-s
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define interrupt PCMSK2
#define S1interrupt PCINT22
#define S2interrupt PCINT23
#define status SREG

volatile uint8_t isrcounter = 0;

int main(void)
{
    interrupt_on();
    while (1) 
    {
    }
}

void interrupt_on()
{
	//status |= (1<<7); //Om pin 7 i denna är set enablar vi interrupts på microkontrollern. Andra pins gör andra saker
	PCICR |= (1<<PCIE2); //För att enabla den grupp pins vilka PCINT22 och PCINT23 är med i enablar vi denna
	interrupt |= (1<<S1interrupt)|(1<<S2interrupt); //enablar de specifika pins vi vill ha
	sei(); // gör samma som det bortkommenterade ovan
}

ISR(PCINT2_vect)
{
	isrcounter++;
}
