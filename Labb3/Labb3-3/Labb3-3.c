/*
 * Labb3-3.c
 *
 * Created: 2020-02-23 12:48:19
 * Author : ma8148so-s
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

extern void led_on(char);
extern void led_off(char);
extern char check_button(char);

int main(void) {
	while (1) {
		char c = check_button(0);
		led_on(c);
		//_delay_ms(500);
		led_off(c);
		}
}
