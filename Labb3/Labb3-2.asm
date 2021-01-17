;
; Labb3-2.asm
;
; Created: 2020-02-23 11:21:22
; Author : ma8148so-s
;


; Replace with your application code
#define STACK_H 0x3E
#define STACK_L 0x3D
#define N_ALLOC 5
#define PINA 0x00
#define DDRA 0x01

start:
	call init
//	call read_buttons
	loop:
	call bigloop
	rjmp loop
//	call stack_buttons
//	call epilogue
//    rjmp start

init:
	ldi r18, 0x00
	out DDRA, r18
	ret

bigloop:
	push r28 //Man pushar och poppar utöver sbiw och adiw ifall r28 och r29 lagrat något annat tidigare - de får tillbaka de gamla värdena efter pop!
	push r29
	in r28, STACK_L
	in r29, STACK_H
	sbiw Y, N_ALLOC
	out STACK_L, r28
	out STACK_H, r29
	//ret //skickar till första label oavsett namn

//read_buttons:
	in r16, PINA
	in r17, PINA
	in r18, PINA
	in r19, PINA
	in r20, PINA
	//ret

//stack_buttons:
	std Y+1, r16
	std Y+2, r17
	std Y+3, r18
	std Y+4, r19
	std Y+5, r20
	//ret

//epilogue:
	in r28, STACK_L
	in r29, STACK_H
	adiw Y, N_ALLOC
	out STACK_L, r28
	out STACK_H, r29
	pop r29
	pop r28
	//rjmp init
	ret
