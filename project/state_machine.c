#include <msp430.h>
#include "state_machine.h"
#include "led.h"
#include "buzzer.h"

enum { STATE_OFF, STATE_ON, STATE_DIM, STATE_SOUND, STATE_ALTERNATE } state;
unsigned char alternate = 0;

void state_machine_init(void) {
    state = STATE_OFF;
    led_off();
    buzzer_set_period(0); // Turn off buzzer
}

void state_machine_update(void) {
    switch (state) {
        case STATE_OFF:
            led_off();
            buzzer_set_period(0); // Turn off buzzer
            break;
        case STATE_ON:
            led_on();
            break;
        case STATE_DIM:
            led_dim();
            break;
        case STATE_SOUND:
            buzzer_set_period(1000); // Example frequency, 2kHz tone
            break;
        case STATE_ALTERNATE:
            // Alternate LEDs
            if (alternate) {
                P1OUT |= BIT0;  // Turn on LED1
                P1OUT &= ~BIT6; // Turn off LED2
            } else {
                P1OUT |= BIT6;  // Turn on LED2
                P1OUT &= ~BIT0; // Turn off LED1
            }
            alternate = !alternate; // Toggle the alternate variable
            break;
    }
}

void state_transition(unsigned char button) {
    switch (button) {
        case BIT0:
            state = STATE_OFF;
            break;
        case BIT1:
            state = STATE_ON;
            break;
        case BIT2:
            state = STATE_DIM;
            break;
        case BIT3:
            state = STATE_SOUND;
            break;
        case BIT4:
            state = STATE_ALTERNATE;
            break;
    }
    state_machine_update();
}
