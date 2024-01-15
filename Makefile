default:
			avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o speaker.o speaker.c

			avr-gcc -o speaker.bin speaker.o
			avr-objcopy -O ihex -R .eeprom speaker.bin speaker.hex
			sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:speaker.hex
