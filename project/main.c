#include <msp430.h>
#include "state_machine.h"
#include "led.h"
#include "sound.h"

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;  // Stop watchdog timer
    state_machine_init();
    led_init();
    sound_init();

    __enable_interrupt();  // Enable interrupts

    while (1) {
        state_machine_update();
    }
}

// Interrupt service routines
#pragma vector=PORT2_VECTOR
__interrupt void Port_2(void) {
    if (P2IFG & 0x01) {
        button1_isr();
    } else if (P2IFG & 0x02) {
        button2_isr();
    } else if (P2IFG & 0x04) {
        button3_isr();
    } else if (P2IFG & 0x08) {
        button4_isr();
    }
}
