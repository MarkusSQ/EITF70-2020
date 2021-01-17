/*
 * Labb4-1_2.c
 *
 * Created: 2020-02-28 16:29:29
 * Author : ma8148so-s
 */ 



#define F_CPU 16000000UL
#include <avr/io.h>
//#include <tested_and_boring/true_den.h>

#define S1 PORTC6
#define S2 PORTC7

uint8_t lions = 4;
int toDen = 0;
int toWild = 0;
int mid = 0;
int begin = 1;

int main(void)
{
    sensor_init();
	led_init();
	led_toggle(lions);
	
	security_system_init();
    while (1) 
    {
		if(read_s1() && (!toWild))
		{
			toDen = 1;
		}
		
		if(read_s2() && (!toDen))
		{
			toWild = 1;
		}
		
		if(toDen)
		{
			//led_toggle(lions);
			if((read_s1() && read_s2()) || mid)
			{
				//led_toggle(1);
				mid = 1;
				
			}
		}
		if (!read_s2() && toDen && mid)
		{
			led_toggle(lions);
			lions--;
			led_toggle(lions);
			mid = 0;
			toDen = 0;
		}
		if (toWild)
		{
			//led_toggle(3);
			if ((read_s1() && read_s2()) || mid)
			{
				//led_toggle(4);
				mid = 1;
			}
		}
		
		if (!read_s1() && toWild && mid)
		{
			led_toggle(lions);
			lions++;
			led_toggle(lions);
			mid = 0;
			toWild = 0;
		}
		if (begin && (lions !=4))
		{
			PORTB ^= (0<<4);
			begin = 0;
		}
		send_lions(lions);
		security_system_run();
    }
}

void sensor_init () 
	{
		DDRC = 0x00;
	}
	
void led_init ()
	{
		DDRB = 0xff;
	}

void led_toggle (uint8_t nbr)
{
	PORTB ^= (1<<nbr);
}

int read_s1()
	{
		return PINC & (1<<S1);
	}

int read_s2()
	{
		return PINC & (1<<S2);
	}
