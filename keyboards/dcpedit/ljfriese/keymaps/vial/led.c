// Copyright 2024 Ming-Gih Lam (@dcpedit)
// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright 2024 Ming-Gih Lam (@dcpedit)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "quantum.h"

#define LED_NUM_LOCK_PIN A0
#define LED_SCROLL_LOCK_PIN A1
#define LED_LAYER_PIN A2
#define LED_CAPS_LOCK_PIN B9

#define LED_ACTIVE_LOW

#define NUM_LAYER 1

void matrix_init_user(void) {
    gpio_set_pin_output(LED_CAPS_LOCK_PIN);
    gpio_set_pin_output(LED_SCROLL_LOCK_PIN);
    gpio_set_pin_output(LED_NUM_LOCK_PIN);
    gpio_set_pin_output(LED_LAYER_PIN);
}

// Initialize your default layer
layer_state_t layer_state_set_user(layer_state_t state) {
    if (IS_LAYER_ON_STATE(state, NUM_LAYER)) {
        gpio_write_pin_low(LED_LAYER_PIN);
    } else {
        writePinHigh(LED_LAYER_PIN);
    }

    return state;
}

// #include <stdint.h>
// #include QMK_KEYBOARD_H
// #include "timer.h"
// #include "gpio.h"
//
//
// #define LED_WAIT 15
//
//
// enum pins {LED_CAPS_LOCK_PIN, LED_NUM_LOCK_PIN, LED_SCROLL_LOCK_PIN, LED_LAYER_PIN};
//
// void flash_led(int pin) {
//     gpio_write_pin_high(pin);
//     wait_ms(LED_WAIT);
//     gpio_write_pin_low(pin);
//     wait_ms(LED_WAIT);
// }
//
// void flash_leds_all(void) {
//     flash_led(LED_LAYER_PIN);
//     flash_led(LED_NUM_LOCK_PIN);
//     flash_led(LED_LAYER_PIN);
//     flash_led(LED_CAPS_LOCK_PIN);
// }
//
// void flash_leds_fwd(int pins[], int max_pins) {
//     for (uint8_t i = 0; i < max_pins; i++) {
//         flash_led(pins[i]);
//     }
//     wait_ms(LED_WAIT);
// }
