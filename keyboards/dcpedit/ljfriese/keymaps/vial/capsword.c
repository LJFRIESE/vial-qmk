#include "action_util.h"
#include "keycode.h"
#include "keycodes.h"

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_SPACE:
        case KC_ENT:
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
            return false;
    }
}
