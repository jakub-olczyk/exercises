MMCU=atmega8
CPU=1000000UL
CC=avr-gcc
CFLAGS=-mmcu=${MMCU} -Os -c -DF_CPU=${CPU}
LD=avr-gcc
LFLAGS=-mmcu=${MMCU}

base:
	${CC} ${CFLAGS} main.c -o main.o
	${LD} ${LFLAGS} main.o -o main.elf
disassembly: base
	avr-objdump -D main.o
program: base
	avr-objcopy -O ihex -R .eeprom main.elf main.hex
	avrdude -p atmega8 -c usbasp -U flash:w:main.hex


