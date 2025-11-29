#include "tapping.h"
#include "dynamic_keymap.h"
#include "vial.h"

void initialize_tap_dance(void) {
    vial_tap_dance_entry_t default_td = {
        KC_NO, KC_NO, KC_NO, KC_NO, TAPPING_TERM,
    };

    for (size_t i = 0; i < VIAL_TAP_DANCE_ENTRIES; ++i) {
        dynamic_keymap_set_tap_dance(i, &default_td);
    }

    for (size_t i = 0; i < num_tap_dance_configs; ++i) {
        const tap_dance_config_t *config = &tap_dance_configs[i];

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
