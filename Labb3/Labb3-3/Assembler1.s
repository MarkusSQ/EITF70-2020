/*
 * Assembler1.s
 *
 * Created: 2020-02-23 14:50:31
 *  Author: ma8148so-s
 */ 

 #define DDRB 0x04
 #define PORTB 0x05

 #define DDRA 0x01
 #define PINA 0x00

 //#define STACK_H 0x3E
// #define STACK_L 0x3D

 .global led_on
 .global led_off
 .global check_button

 //börjar med 25 sen 24 vilket är ett 16-bits register tillsammans. 24 får lägre byten.

 led_on: //när vi anropar en subroutin pushas returaddressen till stacken. När ret nås poppas det
	ldi r25, 0xff
	out DDRB, r25
	//in r22, PORTB
	//or r22, r24
	out PORTB, r24
	ret

led_off:
	ldi r24, 0x00
	//and r24, r22
	//eor r24, r22
	//ldi r25, 0xff
	//out DDRB, r22
	//in r22, PORTB
	//and r22, r24
	out PORTB, r24
	ret

check_button: //input argument från c lagras i r24 (och r25 men här används inget som kräver två bytes)
	//in r18, PINA
	in r24, PINA
	ret
