// IME:     RADNIK KOMELOM
// DATUM:   14.I.2023
// PORUKA:  ...

#include <avr/io.h>
#include <util/delay.h>

int main() {

  // SETUP FUNCTION
  DDRB = DDRB | (1 << DDB5);

  // LOOP FUNCTION
  while(1)
  {
    PORTB = PORTB | (1 << PORTB5);

    _delay_ms(2000);

    PORTB = PORTB & ~(1 << PORTB5);

    _delay_ms(2000);
  }
  return 0;
}
