#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // Password sequence
    uint8_t password[4] = {1,2,3,4};
    uint8_t entered[4];
    uint8_t i;

    // Set PB0 and PB1 as outputs
    DDRB |= (1 << PB0) | (1 << PB1);

    // Set PD2-PD5 as inputs
    DDRD &= ~((1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5));

    // Enable pull-up resistors
    PORTD |= (1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5);

    while(1)
    {
        // Read 4 button presses
        for(i = 0; i < 4; i++)
        {
            while(1)
            {
                if(!(PIND & (1 << PD2)))
                {
                    entered[i] = 1;
                    _delay_ms(300);
                    break;
                }

                if(!(PIND & (1 << PD3)))
                {
                    entered[i] = 2;
                    _delay_ms(300);
                    break;
                }

                if(!(PIND & (1 << PD4)))
                {
                    entered[i] = 3;
                    _delay_ms(300);
                    break;
                }

                if(!(PIND & (1 << PD5)))
                {
                    entered[i] = 4;
                    _delay_ms(300);
                    break;
                }
            }
        }

        // Compare password
        uint8_t correct = 1;

        for(i = 0; i < 4; i++)
        {
            if(entered[i] != password[i])
            {
                correct = 0;
                break;
            }
        }

        // Display result
        if(correct)
        {
            PORTB |= (1 << PB0);   // Green LED ON
            PORTB &= ~(1 << PB1);  // Red LED OFF
        }
        else
        {
            PORTB |= (1 << PB1);   // Red LED ON
            PORTB &= ~(1 << PB0);  // Green LED OFF
        }

        _delay_ms(2000);

        // Turn OFF LEDs
        PORTB &= ~((1 << PB0) | (1 << PB1));
    }
}