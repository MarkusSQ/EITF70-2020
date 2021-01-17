;
; Labb 3.asm
;
; Created: 2020-02-21 11:03:55
; Author : ma8148so-s
;


; Replace with your application code
#define DDRB 0x04
#define PORTB 0x05
#define LED2 0x02

init:
	ldi r21, (1 << LED2)
	out DDRB, r21
	

start:
	ldi r16, 0
	ldi r19, 0
	ldi r20, 0
	ldi r18, (1 << LED2)
	in r17, DDRB

	//256*6*208*5 är ungefär 1.6*10^6 (missat delat med 2?)
	loop1: 
	  clr r19
	  clr r20

	  inc r16
	  cpi r16, 255
	  brne loop2
	  rjmp end

	loop2: 
	  clr r20

      inc r19
	  cpi r19, 255
	  brne loop3
	  rjmp loop1

	loop3: 
	  inc r20
	  cpi r20, 20 //3 för 0.1 sec
	  brne loop3
	  rjmp loop2
end:
	eor r24, r21
	out PORTB, r24
	rjmp start
