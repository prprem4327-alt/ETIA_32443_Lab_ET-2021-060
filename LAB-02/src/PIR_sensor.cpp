#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // PIR Sensor (Input)
    DDRD &= ~(1 << PD2);

    // Status LED (Output)
    DDRB |= (1 << PB0);

    // Alert LED (Output)
    DDRB |= (1 << PB1);

    // Buzzer (Output)
    DDRB |= (1 << PB2);

    while(1)
    {
        // Blink Status LED
        PORTB |= (1 << PB0);
        _delay_ms(1000);

        PORTB &= ~(1 << PB0);
        _delay_ms(1000);

        // Read PIR Sensor
        if(PIND & (1 << PD2))
        {
            // if Motion Detected Turn ON Alert LED
            PORTB |= (1 << PB1);

            // Turn ON Buzzer
            PORTB |= (1 << PB2);

            // Alarm Delay
            _delay_ms(5000);

            // Turn OFF Alert LED
            PORTB &= ~(1 << PB1);

            // Turn OFF Buzzer
            PORTB &= ~(1 << PB2);
        }
    }
}