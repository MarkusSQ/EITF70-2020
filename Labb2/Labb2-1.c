/*
 * Labb2-1.c
 *
 * Created: 2020-02-09 11:59:19
 * Author : ma8148so-s
 */ 

#include <avr/io.h>

volatile int* pntrDDRB = 0x24;
volatile int* pntrDDRA = 0x21;
volatile int* pntrPORTB = 0x25;
volatile int* pntrPINA = 0x20;

int main(void)
{
	*pntrDDRB = 0x8; //första pin är 0x1=0b0000 0001, andra 0x2 = 0b0000 0010, tredje 0x4 = 0b0000 0100, fjärde (LED 3) 0x8 = 0b0000 1000, för flera pins låter man flera vara ett
	*pntrPORTB = 0x8; //Genom att välja att ha en etta är värdet där den är high. 
	*pntrDDRA = 0b00000000; //alla till input
	
	while (1)
	{
		int a = *pntrPINA;
		//if (a == 4130)
		if(a&0b00100000)
		{
			*pntrPORTB ^= 0x8;
		}
	}
	
}
