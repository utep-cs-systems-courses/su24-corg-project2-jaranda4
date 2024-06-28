.cdecls C,LIST,"msp430.h"
	.text
	.global button1_isr
	.global button2_isr
	.global button3_isr
	.global button4_isr

button1_isr:
	bic.b #0x01, &P2IFG
	call #button1_pressed
	reti

button2_isr:
	bic.b #0x02, &P2IFG
	call #button2_pressed
	reti

button3_isr:
	bic.b #0x04, &P2IFG
	call #button3_pressed
	reti

button4_isr:
	bic.b #0x08, &P2IFG
	call #button4_pressed
	reti
