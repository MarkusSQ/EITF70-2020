/*
 * Labb2-3.c
 *
 * Created: 2020-02-09 16:48:02
 * Author : ma8148so-s
 */ 

#include <avr/io.h>
#include <util/delay.h>


void usart0_init() {
	UCSR0B |=(1<<3); //initialiserar transmitter och reciever
	UCSR0B |=(1<<4);
	
	UBRR0 = 103; //sätt till 9600 bps
}

uint8_t usart0_receive()
{
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) ); //Väntar tills RXC0 blir 1: då så får vi (!1) i uttrycket vilket innebär att UDR0 är full (all data har recievats) och därför returnerar den då
	
	/* Get and return received data from buffer */
	return UDR0;
}

void usart0_transmit(uint8_t data)
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) ) //Samma som ovan, fast väntar tills uttömd
	;
	/* Put data into buffer, sends the data */
	UDR0 = data;
}



int main(void)
{
    /* Replace with your application code */
	DDRB = 0x8;
	usart0_init();
    while (1) 
    {
		uint8_t data = usart0_receive();
		usart0_transmit(data);
		if (data==51) //51 är 3 av någon anledning
		{
			PORTB ^= 0x8;
			usart0_transmit('t');
		}
		
    }
}
