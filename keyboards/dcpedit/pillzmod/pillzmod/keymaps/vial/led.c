
#include "config.h"
#include QMK_KEYBOARD_H
#include "timer.h"
#include "gpio.h"

#define LED_ACTIVE_LOW

#define LED_NMLK_PIN A0
#define LED_SCLK_PIN A1
#define LED_LAYER_PIN A2
#define LED_CAPS_PIN B9

#define LED_WAIT 15

int pins[4] = {LED_CAPS_PIN, LED_NMLK_PIN, LED_SCLK_PIN, LED_LAYER_PIN};

void matrix_init_user(void) {
    gpio_set_pin_output(LED_LAYER_PIN);
}

void flash_led(int pin) {
    gpio_write_pin_high(pin);
    wait_ms(LED_WAIT);
    gpio_write_pin_low(pin);
    wait_ms(LED_WAIT);
}


void flash_leds_all(void) {
    flash_led(LED_SCLK_PIN);
    flash_led(LED_NMLK_PIN);
    flash_led(LED_LAYER_PIN);
    flash_led(LED_CAPS_PIN);
}

void flash_leds_fwd(int pins[], int max_pins) {
    for (uint8_t i = 0; i < max_pins; i++) {
        flash_led(pins[i]);
    }
    wait_ms(LED_WAIT);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);
    gpio_write_pin_high(LED_LAYER_PIN);

    if (IS_LAYER_ON(layer)) {
        flash_leds_fwd(pins, layer);
    }

    if (layer == 0) {
        gpio_write_pin_high(LED_LAYER_PIN);
        return state;
    } else {
        gpio_write_pin_low(LED_LAYER_PIN);
        return state;
    }

    return state;
}
