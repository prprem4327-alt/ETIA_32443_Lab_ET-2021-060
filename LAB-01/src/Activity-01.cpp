#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // Configure PB0 as output
    DDRB = DDRB | (1 << PB0);

    while (1)
    {
        // Turn LED ON
        PORTB = PORTB | (1 << PB0);

        _delay_ms(1000);

        // Turn LED OFF
        PORTB = PORTB & ~(1 << PB0);

        _delay_ms(1000);
    }

    return 0;
}