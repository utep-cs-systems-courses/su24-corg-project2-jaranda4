#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "state_machine.h"

void main(void) {
    configureClocks();
    switch_init();
    led_init();
    buzzer_init();
    state_machine_init();
    enableWDTInterrupts(); // Enable watchdog timer interrupts
    __bis_SR_register(GIE | CPUOFF);  // CPU off, GIE on (low-power mode with interrupts enabled)
}

// Interrupt Service Routine for Port 2 (Switches)
void __interrupt_vec(PORT2_VECTOR) Port_2(void) {
    if (P2IFG & SWITCHES) {      // Check if any switch caused the interrupt
        switch_interrupt_handler();  // Handle the interrupt
        P2IFG &= ~SWITCHES;      // Clear the interrupt flags
    }
}

// Watchdog Timer Interrupt Service Routine
void __interrupt_vec(WDT_VECTOR) WDT(void) {
    state_machine_update(); // Call state machine update
    // led_update();           // Call led_update to handle dimming
}
