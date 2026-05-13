#include <Arduino.h>
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // PB5 = OUTPUT (LED)
    DDRB |= (1 << PB5);

    // PD2 = INPUT (PIR)
    DDRD &= ~(1 << PD2);

    while (1)
    {
        if (PIND & (1 << PD2))
        {
            PORTB |= (1 << PB5);
        }
        else
        {
            PORTB &= ~(1 << PB5);
        }

        _delay_ms(100);
    }
}