#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch_state_down, switch_state_changed; /* Effectively boolean */

static char switch_update_interrupt_sense()
{
    char p1val = P1IN;   /* Switch is in P1 */

    /* Update switch interrupt to detect changes from current buttons */
    P1IES |= (p1val & SWITCHES);  /* If switch up, sense down */
    P1IES &= (p1val | ~SWITCHES); /* If switch down, sense up */
    return p1val;
}

void switch_init()     /* Setup switch */
{
    P1REN |= SWITCHES;   /* Enables resistors for switches */
    P1IE |= SWITCHES;    /* Enable interrupts from switches */
    P1OUT |= SWITCHES;   /* Pull-ups for switches */
    P1DIR &= ~SWITCHES;  /* Set switches' bits for input */
    switch_update_interrupt_sense();
    led_update();
}

void switch_interrupt_handler()
{
    char p1val = switch_update_interrupt_sense();
    switch_state_down = (p1val & SW1) ? 0 : 1; /* 0 when SW1 is up */
    switch_state_changed = 1;
    led_update();
}
