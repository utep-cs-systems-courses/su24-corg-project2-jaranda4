#ifndef SWITCHES_H
#define SWITCHES_H

#define SWITCHES (BIT0 | BIT1 | BIT2 | BIT3)  // Define switches on P2.0-3

void switch_init(void);
void switch_interrupt_handler(void);

#endif // SWITCHES_H
