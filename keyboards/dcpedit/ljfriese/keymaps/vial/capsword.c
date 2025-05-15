#include QMK_KEYBOARD_H
#include "keycodes.h"

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_ESC:
            return false; // Deactivate Caps Word.

        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_EQL:
        case KC_DOT:
        case KC_COMMA:
        case KC_LEFT_BRACKET:
        case KC_RIGHT_BRACKET:
        case KC_TAB:
        case KC_RIGHT:
        case KC_LEFT:
        case KC_UP:
        case KC_DOWN:
            return true;

        default:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;
    }
}
