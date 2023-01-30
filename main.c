#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(INT0_vect)
{
    // PORTB ^= (1<<PB0);
    PORTB |= (1<<PB4);
    _delay_ms(2000);
}

void init_external_interrupt() {
    sei();
    GIMSK |= (1<<INT0);
    MCUCR &= ~(1<<ISC00);
    MCUCR &= ~(1<<ISC01);
}

int main(){

    init_external_interrupt();

    DDRB |= (1<<PB4);

    while(1) {
        PORTB &= ~(1<<PB4);
    }
    return 0;
}