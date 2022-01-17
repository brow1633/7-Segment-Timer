/*
 * Written By: Ethan Brown
 * 
 * Hardware: Arduino Mega 2560
 *
 */
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include <avr/interrupt.h>
#include "display.h"

#define PRESCALER 10 

#define CLOCK_RATE 15998976

//number of timer ticks in a second
#define COUNTER_VALUE (CLOCK_RATE >> PRESCALER) 

volatile uint8_t SECONDS = 0; //seconds variable itterated upon interupt of compa 

uint8_t MINUTES = 0; //minutes variable

// TIMER1 compare interupt service routine
// fires when counter value matches OCR1A
ISR(TIMER1_COMPA_vect) {
	SECONDS++;
}


void print_time() { //function to print current time, stored in SECONDS and MINUTES globals 
	if(SECONDS >= 60) { //reset second counter at 60s
		SECONDS %= 60;
		MINUTES++;
	}

	uint8_t sec = SECONDS;
	uint8_t min = MINUTES;

	for(uint8_t i = 1; i < 3; i++){	//print SECONDS.  loop var represents digit on display
		display(sec % 10, i);
		sec /= 10;
		_delay_ms(1); //allows each digit to get to full brightness
	}

	for(uint8_t i = 3; i < 5; i++){	//print MINUTES
		display(min % 10, i);
		if(i == 3) period();
		min /= 10;
		_delay_ms(1);
	}
}

ISR(TIMER3_COMPA_vect) { //interupt routine to call print_time - frees some processing time
	print_time();
	off_seg();
}

int main () {
	activate();
	off_seg();
	off_dig();
	
	OCR1A = COUNTER_VALUE * 1;
	OCR3A = COUNTER_VALUE * .005;

	TCCR1A = 0x00;
	TCCR1B |= (1 << WGM12); //CTC Mode - Compare OCR1A, clear counter and get interupt
	TCCR1B |= (1 << CS10) | (1 << CS12); //set prescaler to 1024

	TCCR3A = 0x00;
	TCCR3B |= (1 << WGM32); //CTC Mode - Compare OCR1A, clear counter and get interupt
	TCCR3B |= (1 << CS30) | (1 << CS32); //set prescaler to 1024

	//Enable interrupt generation
	TIMSK1 |= (1 << OCIE1A);
	TIMSK3 |= (1 << OCIE3A);
	
	//enable interrupts
	sei();
    while(true){
		//print_time();
    }

}


