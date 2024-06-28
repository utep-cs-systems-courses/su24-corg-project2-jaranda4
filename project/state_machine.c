#include "state_machine.h"
#include "led.h"
#include "sound.h"

typedef enum {
    STATE_OFF,
    STATE_PLAYING,
    STATE_PAUSED,
    STATE_STOPPED
} toy_state_t;

static toy_state_t current_state;

void state_machine_init(void) {
    current_state = STATE_OFF;
    led_off();
    sound_off();
}

void state_machine_update(void) {
    switch (current_state) {
        case STATE_OFF:
            led_off();
            sound_off();
            break;
        case STATE_PLAYING:
            led_on();
            play_tone(1000); // Example tone
            break;
        case STATE_PAUSED:
            led_dim();
            sound_off();
            break;
        case STATE_STOPPED:
            led_off();
            sound_off();
            break;
    }
}

void state_transition(toy_state_t new_state) {
    current_state = new_state;
    state_machine_update();
}

void button1_pressed(void) {
    if (current_state == STATE_OFF) {
        state_transition(STATE_PLAYING);
    }
}

void button2_pressed(void) {
    if (current_state == STATE_PLAYING) {
        state_transition(STATE_PAUSED);
    }
}

void button3_pressed(void) {
    if (current_state == STATE_PAUSED) {
        state_transition(STATE_STOPPED);
    }
}

void button4_pressed(void) {
    if (current_state == STATE_STOPPED) {
        state_transition(STATE_OFF);
    }
}
