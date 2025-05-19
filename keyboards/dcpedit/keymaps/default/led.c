// Copyright 2024 Ming-Gih Lam (@dcpedit)
// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright 2024 Ming-Gih Lam (@dcpedit)
// SPDX-License-Identifier: GPL-2.0-or-later
#include <stdint.h>
#include "action_layer.h"
#include "host.h"
#include "gpio.h"
#include "config.h"
#include "timer.h"
#include "config.h"

const int led_pins[] = {
    LED_CAPS_LOCK_PIN,
    LED_NUM_LOCK_PIN,
    LED_SCROLL_LOCK_PIN,
    LED_LAYER_PIN
};
#define LED_COUNT (sizeof(led_pins) / sizeof(led_pins[0]))

#define LED_CAPS_LOCK   (1<<0)
#define LED_SCROLL_LOCK (1<<1)
#define LED_NUM_LOCK    (1<<2)

void flash_led_once(int pin);
void restore_lock_leds(void);

// ---- animation state ----


typedef enum {
    ANIM_ON_FWD,
    ANIM_OFF_REV
} anim_phase_t;

static uint32_t flash_timer = 0;
static uint8_t flash_index = 0;
static anim_phase_t anim_phase = ANIM_ON_FWD;
static bool flashing = false;

void restore_lock_leds(void) {
    led_t led_state = host_keyboard_led_state();

    gpio_write_pin(LED_CAPS_LOCK_PIN, !led_state.caps_lock);
    gpio_write_pin(LED_NUM_LOCK_PIN, !led_state.num_lock);
    gpio_write_pin(LED_SCROLL_LOCK_PIN, !led_state.scroll_lock);
}

void process_leds(void) {
    static bool last_flashing = false;
    const int layer_leds = LED_COUNT - (LED_COUNT - get_highest_layer(layer_state));

    bool current_flashing = get_highest_layer(layer_state) != BASE_LAYER;

    if (current_flashing != last_flashing) {
        flashing = current_flashing;
        flash_index = 0;
        anim_phase = ANIM_ON_FWD;
        flash_timer = timer_read();

        if (!flashing) {
            for (int i = 0; i < layer_leds; i++) {
                gpio_write_pin_high(led_pins[i]);
            }
            restore_lock_leds();
        }

        last_flashing = current_flashing;
    }

    if (!flashing) return;

    if (timer_elapsed(flash_timer) >= LED_WAIT) {
        if (anim_phase == ANIM_ON_FWD) {
            gpio_write_pin_low(led_pins[flash_index]);
        } else {  // ANIM_OFF_REV
            gpio_write_pin_high(led_pins[layer_leds - 1 - flash_index]);
        }

        flash_index++;
        if (flash_index >= layer_leds) {
            flash_index = 0;
            anim_phase = (anim_phase == ANIM_ON_FWD) ? ANIM_OFF_REV : ANIM_ON_FWD;
        }

        flash_timer = timer_read();
    }
}
