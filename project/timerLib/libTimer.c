#include <msp430.h>
#include "libTimer.h"

void configureClocks() {
    BCSCTL1 = CALBC1_16MHZ;    // Set DCO
    DCOCTL = CALDCO_16MHZ;
    BCSCTL2 &= ~(DIVS_3);      // SMCLK = DCO = 16MHz
}

void enableWDTInterrupts() {
    WDTCTL = WDTPW | WDTTMSEL | WDTCNTCL | WDT_MRST_0_5;  // Set WDT interval
    IE1 |= WDTIE;             // Enable WDT interrupt
}

void timerAUpmode() {
    TA0CCR0 = 1000;           // PWM Period
    TA0CCR1 = 500;            // CCR1 PWM duty cycle
    TA0CCTL1 = OUTMOD_7;      // CCR1 reset/set
    TA0CTL = TASSEL_2 + MC_1; // SMCLK, up mode
}
