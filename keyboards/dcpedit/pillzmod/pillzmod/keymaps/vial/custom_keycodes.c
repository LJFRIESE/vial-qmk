#include "keycodes.h"
#include "qmk-vim/src/vim.h"
#include "quantum.h"

enum custom_keycodes {
    TOG_VIM = QK_KB_0,
    OS_VIM,
    S_PLAY,
    LED_FLASH,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process case modes
    if (!process_vim_mode(keycode, record)) {
        return false;
    }
    // Regular user keycode case statement
    // if (IS_LAYER_ON(PREFIX_LAYER) && record->event.pressed) {
    //     tap_code16(C(KC_A)); // Tap Ctrl+A.
    // }

    switch (keycode) {
        case TOG_VIM:
            if (record->event.pressed) {
                toggle_vim_mode();
            }
            return false;
        case OS_VIM:
            if (record->event.pressed) {
                start_oneshot_vim();
            }
            return false;
        case S_PLAY:
            // if (record->event.pressed) {
            //     float my_song[][2] = SONG(FANTASIE_IMPROMPTU);
            //         PLAY_SONG(my_song);
            // }
            return false;
        default:
            return true;
    }
}
