/*
 * Labb2-2.c
 *
 * Created: 2020-02-09 15:18:45
 * Author : ma8148so-s
 */ 

#include <avr/io.h>
#include<util/delay.h>

uint8_t button_read_reliably(int a) 
{
		if (PIND&(1<<PORTD7))
		{
			
			while (PIND & (1<<PORTD7))
			{
				_delay_ms(50);
			}
			return 1;
		}
		return 0;
		
}

int main(void)
{
	DDRB = 0x8; //första pin är 0x1=0b0000 0001, andra 0x2 = 0b0000 0010, tredje 0x4 = 0b0000 0100, fjärde (LED 3) 0x8 = 0b0000 1000, för flera pins låter man flera vara ett
	PORTB = 0x8; //Genom att välja att ha en etta är värdet där den är high.
	//DDRA = 0x16; //Knapp 4
	DDRD = 1<<PIND7; //enskilda knappen
	while (1)
	{
		//int a = PINA;
		int a = PIND;
		if (button_read_reliably(a) ==1)
		{
			PORTB ^= 0x8;
		}
	}
	
}
