
#include "keycodes.h"
#include QMK_KEYBOARD_H
// Structure to hold tap dance configurations
#include "dynamic_keymap.h"
#include "vial.h"
typedef struct {
    uint8_t index;         // The index in the tap_dance array
    uint16_t tap;          // Single tap keycode
    uint16_t hold;         // Hold keycode
    uint16_t double_tap;   // Double tap keycode
    uint16_t tap_hold;     // Tap-then-hold keycode
    uint16_t tapping_term; // Custom tapping term (0 for default)
} tap_dance_config_t;

// Tap Dance declarations
enum {
    TD_ESC_CAPS = 0,
};

void initialize_tap_dance(void) {
    // Default entry for all positions
    vial_tap_dance_entry_t default_td = {
        KC_NO, KC_NO, KC_NO, KC_NO, TAPPING_TERM,
    };

    // Set all entries to default first
    for (size_t i = 0; i < VIAL_TAP_DANCE_ENTRIES; ++i) {
        dynamic_keymap_set_tap_dance(i, &default_td);
    }

    // Define custom configurations in a centralized table
    const tap_dance_config_t tap_dance_configs[] = {
        // index           tap     hold      double_tap  tap_hold  tapping_term
        { TD_ESC_CAPS,     KC_ESC,  KC_NO,    KC_CAPS,    KC_NO,    TAPPING_TERM },
    };

    // Apply all configurations
    const size_t num_configs = sizeof(tap_dance_configs) / sizeof(tap_dance_configs[0]);
    for (size_t i = 0; i < num_configs; ++i) {
        const tap_dance_config_t *config = &tap_dance_configs[i];

        // Only apply if the index is within bounds
        if (config->index < VIAL_TAP_DANCE_ENTRIES) {
            vial_tap_dance_entry_t entry = {
                config->tap,
                config->hold,
                config->double_tap,
                config->tap_hold,
                config->tapping_term == 0 ? TAPPING_TERM : config->tapping_term
            };
            dynamic_keymap_set_tap_dance(config->index, &entry);
        }
    }
}
