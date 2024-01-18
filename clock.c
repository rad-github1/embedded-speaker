#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>

#define LED_PIN 7

int main(void) {
    // Set D7 (PD7) as an output pin
    DDRD |= (1 << LED_PIN);

    // Enable global interrupts
    sei();

    while (1) {
        // Toggle the LED state by XORing the corresponding bit in PORTD
        PORTD ^= (1 << LED_PIN);

        // Enable the watchdog timer with a 1-second timeout
        wdt_enable(WDTO_1S);

        // Wait for the watchdog timer to expire
        while (1);
    }

    return 0;
}

// Watchdog Timer interrupt service routine
ISR(WDT_vect) {
    // Disable the watchdog timer
    wdt_disable();
}

