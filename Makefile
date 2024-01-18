CC   = avr-gcc
MMCU = atmega328p
SRC  = clock

default:
	$(CC) -Os -DF_CPU=16000000UL -mmcu=$(MMCU) -c -o $(SRC).o $(SRC).c
	$(CC) -o $(SRC).bin $(SRC).o

	avr-objcopy -O ihex -R .eeprom $(SRC).bin $(SRC).hex
	sudo avrdude -F -V -c arduino -p $(MMCU) -P /dev/ttyACM0 -b 115200 -U flash:w:$(SRC).hex

clean:
	rm -f $(SRC).o $(SRC).hex $(SRC).bin
