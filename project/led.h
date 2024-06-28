#ifndef LED_H
#define LED_H

#define LEDS (BIT0 | BIT6)

void led_init(void);
void led_on(void);
void led_off(void);
void led_dim(void);
void led_update(void);  // Add this line

#endif // LED_H
