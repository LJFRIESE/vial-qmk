#include QMK_KEYBOARD_H
#include "matrix.h"
#include "quantum.h"
#include "led.c"

#if __has_include("keymap.h")
#    include "keymap.h"
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_CAPS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SCRL, KC_PAUS, TG(1), MO(1), KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSLS, KC_ESC, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_GRAVE, KC_INS, KC_LBRC, KC_RBRC, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, MO(2), MO(3), MO(3), MO(2), KC_HOME, KC_PGUP, KC_BSPC, KC_DEL, MO(1), MO(1), KC_ENTER, KC_SPC, KC_MUTE),
    [1] = LAYOUT(QK_RBT, QK_BOOT, _______, _______, _______, _______, _______, _______, _______, AU_TOGG, HF_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_F10, KC_F11, KC_F12, XXXXXXX, XXXXXXX, KC_NUM, KC_PEQL, KC_PSLS, KC_PAST, XXXXXXX, _______, XXXXXXX, KC_F7, KC_F8, KC_F9, XXXXXXX, XXXXXXX, KC_P7, KC_P8, KC_P9, KC_PMNS, XXXXXXX, _______, XXXXXXX, KC_F4, KC_F5, KC_F6, XXXXXXX, XXXXXXX, KC_P4, KC_P5, KC_P6, KC_PPLS, XXXXXXX, _______, XXXXXXX, KC_F1, KC_F2, KC_F3, XXXXXXX, XXXXXXX, KC_P1, KC_P2, KC_P3, KC_PENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P0, KC_MUTE),
    [2] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LGUI, KC_LALT, KC_LCTL, KC_RSFT, _______, _______, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE),
    [3] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE),
    [4] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE),
    [5] = LAYOUT(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SCRL, KC_PAUS, TG(1), MO(1), KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_GRV, KC_INS, KC_LBRC, KC_RBRC, KC_UP, KC_DOWN, KC_LEFT, KC_RGHT, KC_LCTL, KC_LALT, KC_RGUI, KC_RCTL, KC_HOME, KC_PGUP, KC_BSPC, KC_DEL, KC_END, KC_PGDN, KC_ENTER, KC_SPC, KC_MUTE)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [1] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [2] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [3] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [4] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [5] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)


static bool col2_active = false;

void matrix_init_user(void) {
    for (int i = 0; i < LED_COUNT; i++) {
        gpio_set_pin_output(led_pins[i]);
        gpio_write_pin_high(led_pins[i]);  // all off by default
    }
}


void matrix_scan_user(void) {
    // Check if any key in column 2 is pressed
    col2_active = false;
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        // Check column 2 (index 1 since we're 0-indexed)
        if (matrix_is_on(row, 1)) { // column 2 has index 1
            col2_active = true;
            break;
        }
    }

    process_leds();
}

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return state;  // no flashing logic here anymore
// }


// Process the matrix state before it's used
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    // If column 2 is active and this is a column 1 key, block it
    if (col2_active && record->event.key.col == 0) { // column 1 has index 0
        return false;
    }

    return process_record_user(keycode, record);
}

// void keyboard_post_init_user(void) {
//   // Customise these values to desired behaviour
//   debug_enable=true;
//   debug_matrix=true;
//   debug_keyboard=true;
//   //debug_mouse=true;
// }
//
//
//
//
