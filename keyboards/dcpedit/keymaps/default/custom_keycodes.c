#include <stdint.h>
#include "keycodes.h"
#include "quantum.h"

enum custom_keycodes {
    RESET_LOCKS = QK_KB_0,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    if (record->event.pressed == 1) {
        uprintf("row: %u, col: %u\n", record->event.key.row, record->event.key.col);
    }
#endif
    switch (keycode) {
        case RESET_LOCKS:
            if (record->event.pressed) {
                // Turn off Caps Lock
                if (host_keyboard_led_state().caps_lock) {
                    tap_code(KC_CAPS);
                }
                // Turn off Num Lock
                if (host_keyboard_led_state().num_lock) {
                    tap_code(KC_N);
                }
                // Turn off Scroll Lock
                if (host_keyboard_led_state().scroll_lock) {
                    tap_code(KC_SCROLL_LOCK);
                }
            }
            return false;
        default:
            return true;
    }
}
