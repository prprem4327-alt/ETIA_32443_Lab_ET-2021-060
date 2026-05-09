#define F_CPU 16000000UL
#include <avr/io.h>

int main(void)
{
    DDRD &= ~(1 << PD2);  
    DDRD |= (1 << PD3);   

    while(1)
    {
        if(PIND & (1 << PD2))  
        {
            PORTD |= (1 << PD3); 
        }
        else
        {
            PORTD &= ~(1 << PD3); 
        }
    }
}