#include <stdint.h>
#include "keycodes.h"
// #include "qmk-vim/src/vim.h"
#include "quantum.h"

enum custom_keycodes {
    RESET_LOCKS= QK_KB_0,
    // TOG_VIM ,
    // OS_VIM,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process case modes
    // if (!process_vim_mode(keycode, record)) {
    //     return false;
    // }

    switch (keycode) {
        // case TOG_VIM:
        //     if (record->event.pressed) {
        //         toggle_vim_mode();
        //     }
        //     return false;
        // case OS_VIM:
        //     if (record->event.pressed) {
        //         start_oneshot_vim();
        //     }
        //     return false;
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

