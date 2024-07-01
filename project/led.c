#include <msp430.h>
#include "led.h"

static unsigned int dimCounter = 0;  // Counter for software PWM
static unsigned int dimThreshold = 50; // Threshold for dimming (higher value = dimmer)

void led_init(void) {
    P1DIR |= LEDS;   // Set LED pins as outputs
    P1OUT &= ~LEDS;  // Turn off LEDs
}

void led_on(void) {
    P1OUT |= LEDS;   // Turn on LEDs
}

void led_off(void) {
    P1OUT &= ~LEDS;  // Turn off LEDs
}

void led_dim(void) {
    dimThreshold = 40;  // Adjust this value to change dimming level (higher = dimmer)
}

//void led_update(void) {
  //dimCounter++;
    // if (dimCounter >= 500) {
       //dimCounter = 0;
	//}

    // if (dimCounter < dimThreshold) {
//P1OUT |= LEDS;  // Turn on LEDs
	// } else {
      // P1OUT &= ~LEDS;  // Turn off LEDs
	// }
//}
