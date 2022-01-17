Project contains a simple timer and basic 4 digit 7 segment display library (display.c/h).

The right two digits on the display will count seconds, and the left two will count minutes.  Maximum timing capacity of 99:59.

Requires avrdude, avr-gcc and avr-libc.

Pins (7-seg display -> Arduino):
1 -> 32
2 -> 31
3 -> 30
4 -> 33
5 -> 34
6 -> 220 Ohm -> 53
7 -> 36
8 -> 220 Ohm -> 52
9 -> 220 Ohm -> 51
10 -> 35
11 -> 37
12 -> 220 Ohm -> 50

Used this as a little project to get some hands on embedded experience.  
