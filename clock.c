#include <avr/io.h>

int main()
{
  // MAKE LED OUTPUT
  DDRD = 0b00000100;

  while(1)
  {
    // to set 1, use |=
    // to set 0, use &= !...
    if (PIND & 0b00001000) // Check if D3 high
    {
      PORTD |= 0b00000100;
    }
    else
    {
      PORTD &= !0b00000000;
    }
  }

  return 0;
}


