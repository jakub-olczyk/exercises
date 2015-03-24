#include <avr/io.h>
#include <util/delay.h>

int main()
{
DDRB |= _BV(PB0) | _BV(PB3);
for(;;){
	PORTB ^= _BV(PB0) | _BV(PB3);
	_delay_ms(500);
}
}
