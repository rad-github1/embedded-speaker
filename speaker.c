// IME:     RADNIK KOMELOM
// DATUM:   14.I.2023
// PORUKA:  ...

#include <avr/io.h>
#include <util/delay.h>

int main() {

  // SETUP FUNCTION
  // DDRB = DDRB | (1 << DDB5);
  // DDRB = 0b00100000;
  DDRD = 0b10000000;

  // LOOP FUNCTION
  while(1)
  {
    // PORTB = PORTB | (1 << PORTB5);
    // PORTB = 0b00100000;
    PORTD = 0b10000000;

    _delay_ms(1000);

    // PORTB = PORTB & ~(1 << PORTB5);
    // PORTB = 0b00000000;
    PORTD = 0b00000000;

    _delay_ms(1000);
  }
  return 0;
}
