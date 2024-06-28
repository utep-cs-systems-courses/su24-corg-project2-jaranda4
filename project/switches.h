#ifndef switches_included
#define switches_included

#define SW1 BIT3      /* Switch1 is p1.3 */
#define SWITCHES SW1  /* Only 1 switch on this board */

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down, switch_state_changed; /* Effectively boolean */

#endif // Included
