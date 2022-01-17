/*
 * Written By: Ethan Brown
 * 
 * Hardware: Arduino Mega 2560
 *
 */
#ifndef DISPLAY_DOT_H
#define DISPLAY_DOT_H


//define some constants to make code more readable
//must have all digit pins and segment pins in one port
#define DIG1      PORTB0
#define DIG2      PORTB1
#define DIG3      PORTB2
#define DIG4      PORTB3

//Segments
#define TOP       PORTC0
#define TOP_RIGHT PORTC1
#define TOP_LEFT  PORTC2
#define MID       PORTC3
#define BOT_RIGHT PORTC4
#define BOT_LEFT  PORTC5
#define BOT       PORTC6
#define DP        PORTC7

//Truth table definition of each character/number
//Numbers        |   TOP     |     TOP_RIGHT    |     TOP_LEFT    |     MID    |     BOT_RIGHT    |    BOT_LEFT     |   BOT      |    DP    |
#define ZERO      (1 << TOP) | (1 << TOP_RIGHT) | (1 << TOP_LEFT) |              (1 << BOT_RIGHT) | (1 << BOT_LEFT) | (1 << BOT)
#define ONE                    (1 << TOP_RIGHT) |                                (1 << BOT_RIGHT)
#define TWO       (1 << TOP) | (1 << TOP_RIGHT) |                   (1 << MID) |                    (1 << BOT_LEFT) | (1 << BOT)
#define THREE     (1 << TOP) | (1 << TOP_RIGHT) |                   (1 << MID) | (1 << BOT_RIGHT) |                   (1 << BOT)
#define FOUR                   (1 << TOP_RIGHT) | (1 << TOP_LEFT) | (1 << MID) | (1 << BOT_RIGHT)
#define FIVE      (1 << TOP) |                    (1 << TOP_LEFT) | (1 << MID) | (1 << BOT_RIGHT) |                   (1 << BOT)
#define SIX       (1 << TOP) |                    (1 << TOP_LEFT) | (1 << MID) | (1 << BOT_RIGHT) | (1 << BOT_LEFT) | (1 << BOT)
#define SEVEN     (1 << TOP) | (1 << TOP_RIGHT) |                                (1 << BOT_RIGHT)
#define EIGHT     (1 << TOP) | (1 << TOP_RIGHT) | (1 << TOP_LEFT) | (1 << MID) | (1 << BOT_RIGHT) | (1 << BOT_LEFT) | (1 << BOT)
#define NINE      (1 << TOP) | (1 << TOP_RIGHT) | (1 << TOP_LEFT) | (1 << MID) | (1 << BOT_RIGHT) |                   (1 << BOT)

//Chars
#define UPE       (1 << TOP) |                    (1 << TOP_LEFT) | (1 << MID) |                    (1 << BOT_LEFT) |(1 << BOT)

//All
#define ALL       (1 << TOP) | (1 << TOP_RIGHT) | (1 << TOP_LEFT) | (1 << MID) | (1 << BOT_RIGHT) | (1 << BOT_LEFT) | (1 << BOT) | (1 << DP)

void activate(); //Activate driver pins as output

void off_dig(); //Turn off all digit pins
void off_seg(); //Turn off all seg pins 

void display(uint8_t, uint8_t); //Display num at given digit 

void period(); //Display period
void err();  //Error - Displays 'E'

#endif /* DISPLAY_DOT_H */
