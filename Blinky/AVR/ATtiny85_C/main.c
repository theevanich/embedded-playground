/*
 * blinky.c
 *
 * Created: 22-Apr-18 4:59:34 PM
 * Author : Thee
 */ 
//#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB |= 0x02;

    for(; ;)
    {
		PORTB |= 0x02;
		_delay_ms(500);
		PORTB &= ~(0x02);
		_delay_ms(100);
    }
}

