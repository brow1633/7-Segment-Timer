/*
 * Written By: Ethan Brown
 * 
 * Hardware: Arduino Mega 2560
 *
 */
#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>
#include "display.h"

void activate() { //Set digit and segment pins to output mode
	DDRB |= _BV(DIG1); // DIGIT 1 - GREEN - 53
	DDRB |= _BV(DIG2); // DIGIT 2 - BLUE  - 52
	DDRB |= _BV(DIG3); // DIGIT 3 - WHITE - 51
	DDRB |= _BV(DIG4); // DIGIT 4 - RED   - 50

	DDRC |= ALL;
}

void off_dig() { //turn each digit off (write high) 
	PORTB |= _BV(DIG1);
	PORTB |= _BV(DIG2);
	PORTB |= _BV(DIG3);
	PORTB |= _BV(DIG4);
}

void off_seg() { //turn each segmenet off (write low) 
	PORTC &= ~(ALL);
}

void period() { //turn on decimal place/period
	PORTC |= _BV(DP);
}

void err() { //Error function - Display E on 4th dig
	display('E', 4);
	_delay_ms(5000);
}
void display(uint8_t num, uint8_t digit){ //display num at a digit
	//Must turn off dig/segs to prevent ghosting before new segs are fully set
	off_dig();
	off_seg();

	switch(digit) {
		case 1:
			PORTB &= ~_BV(DIG1);
			break;
		case 2:
			PORTB &= ~_BV(DIG2);
			break;
		case 3:
			PORTB &= ~_BV(DIG3);
			break;
		case 4:
			PORTB &= ~_BV(DIG4);
			break;
		default:
			err();
	}

	switch(num) {
		case 0:
			PORTC |= ZERO;
			break;
		case 1:
			PORTC |= ONE;
			break;
		case 2:
			PORTC |= TWO;
			break;
		case 3:
			PORTC |= THREE;
			break;
		case 4:
			PORTC |= FOUR;
			break;
		case 5:
			PORTC |= FIVE;
			break;
		case 6:
			PORTC |= SIX;
			break;
		case 7:
			PORTC |= SEVEN;
			break;
		case 8:
			PORTC |= EIGHT;
			break;
		case 9:
			PORTC |= NINE;
			break;
		case 'E':
			PORTC |= UPE;
			break;
		default:
			err();
	}
}
