#include <msp430.h>
#include "switches.h"
#include "state_machine.h"

void switch_init(void) {
    P2DIR &= ~SWITCHES;   // Set switch pins as inputs
    P2REN |= SWITCHES;    // Enable pull-up resistors
    P2OUT |= SWITCHES;
    P2IE |= SWITCHES;     // Enable interrupts for switches
    P2IES |= SWITCHES;    // Set interrupt edge to high-to-low
    P2IFG &= ~SWITCHES;   // Clear interrupt flags
}

void switch_interrupt_handler(void) {
    unsigned char button = P2IFG & SWITCHES;
    if (button) {
        P2IFG &= ~SWITCHES;  // Clear interrupt flag
        state_transition(button);  // Transition state based on the button pressed
    }
}
