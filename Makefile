#Use avr-gcc, set CPU and it's clock speed
CC=avr-gcc
CFLAGS = -O2 -DF_CPU=16000000UL -mmcu=atmega2560
OBJECTS := timer.o display.o

#detect port of arduino *change depending on platform*

USBPORT:= $(shell ls /dev/ttyACM*) 

timer.out: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

timer.o: timer.c display.h 
	$(CC) $(CFLAGS) -c $< -o $@ 

display.o: display.c display.h 
	$(CC) $(CFLAGS) -c $< -o $@ 

#Convert .out to .hex
%.hex: %.out
	avr-objcopy -O ihex -R .eeprom $< $@

#install using avrdude onto arduino
install.%: %.hex
	avrdude -D -F -V -c avrispv2 -p m2560 -P ${USBPORT} -b 115200 -U flash:w:$<:i

clean:
	rm -f *.hex *.out *.o

