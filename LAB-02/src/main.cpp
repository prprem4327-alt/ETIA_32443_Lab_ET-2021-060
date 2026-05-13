#include <Arduino.h>
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB |= (1 << PB5);     // LED output
    DDRD &= ~(1 << PD2);    // PIR input

    while (1)
    {
        if (PIND & (1 << PD2))
        {
            PORTB |= (1 << PB5);   // LED ON
        }
        else
        {
            PORTB &= ~(1 << PB5);  // LED OFF
        }

        _delay_ms(100);
    }
}