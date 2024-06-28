#include <msp430.h>
#include "switches.h"

/* Switch on P1 (S2) */
void __interrupt_vec(PORT1_VECTOR) Port_1()
{
    if (P1IFG & SWITCHES) {   /* Did a button cause this interrupt? */
        P1IFG &= ~SWITCHES;   /* Clear pending SW interrupts */
        switch_interrupt_handler(); /* Single handler for all switches */
    }
}
