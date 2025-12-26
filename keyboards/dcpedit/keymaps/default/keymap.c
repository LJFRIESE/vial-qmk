#include "keycodes.h"
#include QMK_KEYBOARD_H
#include "matrix.h"
#include "quantum.h"
#include "led.c"
// #include "tapping.h"

#define _BASE 0
#define _SYMB 1
#define _NUM 2
#define _NAV 3

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    SYMB,
    NAV,
    ADJUST,
};
enum {
    ESC_CAPS = 0,
    NUM_LYR,
};

enum { TD_ESC };

// const tap_dance_config_t tap_dance_configs[] = {
//     // index        tap         hold        double_tap      tap_hold        tapping_term
//     { ESC_CAPS      ,KC_ESC     ,KC_CAPS    ,KC_CAPS        ,KC_NO          ,TAPPING_TERM },
//     { NUM_LYR     ,TG(2)      ,MO(2)      ,TO(0)          ,MO(3)          ,TAPPING_TERM },
// };
//
// const size_t num_tap_dance_configs = sizeof(tap_dance_configs) / sizeof(tap_dance_configs[0]);

#define TAP_TAPPING_TERM 260
void install_tap_dance_entries(void) {
    vial_tap_dance_entry_t td0 = {KC_ESC, KC_NO, KC_CAPS, KC_NO, TAP_TAPPING_TERM};
    vial_tap_dance_entry_t td1 = {KC_NO, TG(2), KC_NO, KC_LCTL, TAP_TAPPING_TERM};
    dynamic_keymap_set_tap_dance(0, &td0); // the first value corresponds to the TD(i) slot
    dynamic_keymap_set_tap_dance(1, &td1);
}

#define NUM_NAV MO(_NUM)

#define LT_SYMB LT(_SYMB, KC_ENT)
#define ESC_CAPS TD(0)
#define TD_NUM TD(_NUM)

void keyboard_post_init_user(void) {
    install_tap_dance_entries();
    debug_enable = true;
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] = { ENCODER_CCW_CW(KC_BRID, KC_BRIU)},
    [2] = { ENCODER_CCW_CW(MS_WHLD, MS_WHLU)},
    [3] = { ENCODER_CCW_CW(MS_WHLL, MS_WHLR)},
    [4] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [5] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
KC_CAPS     ,KC_F1      ,KC_F2      ,KC_F3      ,KC_F4      ,KC_F5      ,KC_F6      ,KC_F7       ,KC_F8     ,KC_F9      ,KC_F10     ,KC_F11     ,KC_F12     ,KC_PSCR    ,KC_SCRL    ,KC_PAUS    ,TG(1)     ,MO(1),
KC_EQL      ,KC_1       ,KC_2       ,KC_3       ,KC_4       ,KC_5                                                       ,KC_6       ,KC_7       ,KC_8       ,KC_9       ,KC_0       ,KC_MINS,
KC_TAB      ,KC_Q       ,KC_W       ,KC_F       ,KC_P       ,KC_B                                                       ,KC_J       ,KC_L       ,KC_U       ,KC_Y       ,KC_SCLN    ,KC_BSLS,
KC_ESC      ,KC_A       ,KC_R       ,KC_S       ,KC_T       ,KC_G                                                       ,KC_M       ,KC_N       ,KC_E       ,KC_I       ,KC_O       ,KC_QUOT,
KC_LSFT     ,KC_Z       ,KC_X       ,KC_C       ,KC_D       ,KC_V                                                       ,KC_K       ,KC_H       ,KC_COMM    ,KC_DOT     ,KC_SLSH    ,KC_RSFT,
             KC_HOME    ,KC_PGDN    ,KC_PGUP    ,KC_END                                                                             ,KC_LEFT    ,KC_DOWN    ,KC_UP      ,KC_RGHT
                                                            ,KC_LCTL   ,NUM_NAV                              ,TD_NUM ,KC_RCTL
                                                                       ,KC_LGUI                            ,KC_LALT
                                                ,KC_BSPC     ,KC_DEL   ,KC_MEH                             ,KC_HYPR    ,LT(1, KC_ENTER)   ,KC_SPC
    ),
    [1] = LAYOUT(
            QK_RBT     ,QK_BOOT    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______,
            _______    ,_______     ,_______         ,_______           ,_______        ,_______                                                    ,_______    ,_______    ,_______        ,_______        ,_______        ,_______  ,
            _______    ,LSFT(KC_EQL),LSFT(KC_7)      ,LSFT(KC_8)        ,LSFT(KC_GRV)   ,_______                                                    ,_______    ,KC_MINS    ,KC_LBRC        ,KC_RBRC        ,_______        ,_______  ,
            _______    ,KC_EQL      ,LSFT(KC_4)      ,LSFT(KC_5)        ,LSFT(KC_6)     ,_______                                                    ,_______    ,LSFT(KC_MINS),LSFT(KC_9)  ,LSFT(KC_0)     ,_______        ,_______  ,
            _______    ,LSFT(KC_GRV),LSFT(KC_1)      ,LSFT(KC_2)        ,LSFT(KC_3)     ,_______                                                    ,_______    ,_______    ,LSFT(KC_LBRC)  ,LSFT(KC_RBRC)  ,_______        ,_______  ,
            _______    ,_______    ,_______    ,_______                                                                            ,_______    ,_______    ,_______    ,_______
                                                                        ,_______   ,_______                 ,_______    ,_______
                                                                                             ,_______       ,_______
                                                                        ,_______    ,_______   ,_______     ,_______    ,_______    ,_______
            ),
    [2] = LAYOUT(
            QK_RBT     ,QK_BOOT    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______
            ,_______    ,_______    ,KC_F10     ,KC_F11     ,KC_F12     ,_______                                                    ,_______    ,_______     ,_______    ,_______    ,_______    ,_______
            ,_______    ,_______    ,KC_F7      ,KC_F8      ,KC_F9      ,_______                                                    ,_______    ,KC_7      ,KC_8      ,KC_9      ,_______    ,_______
            ,_______    ,_______    ,KC_F4      ,KC_F5      ,KC_F6      ,_______                                                    ,_______    ,KC_4      ,KC_5      ,KC_6      ,_______    ,_______
            ,_______    ,_______    ,KC_F1      ,KC_F2      ,KC_F3      ,_______                                                    ,KC_0       ,KC_1      ,KC_2      ,KC_3      ,KC_ENTER    ,_______
                       ,_______     ,_______         ,_______           ,_______                                                                                ,_______        ,_______        ,_______        ,_______
                                                                                        ,_______   ,_______                            ,_______    ,_______
                                                                                                   ,_______                            ,_______
                                                                            ,_______    ,_______   ,_______                            ,_______    ,_______    ,_______
    ),
    [3] = LAYOUT(
      _______     ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______,
      _______    ,_______    ,_______     ,_______     ,_______     ,_______                                                    ,_______    ,_______     ,_______    ,_______    ,_______    ,_______,
      _______    ,_______    ,_______   ,_______      ,_______      ,_______                                                    ,_______    ,_______      ,_______      ,_______      ,_______    ,_______,
      _______    ,_______    ,_______      ,_______      ,_______      ,_______                                                    ,_______    ,_______      ,_______      ,_______      ,_______    ,_______,
      _______    ,_______    ,_______      ,_______      ,_______      ,_______                                                    ,_______      ,_______      ,_______      ,_______      ,_______    ,_______,
                  _______    ,_______    ,_______    ,_______                                                                            ,_______    ,_______    ,_______    ,_______
                                                                 ,_______   ,_______                            ,_______    ,_______
                                                                            ,_______                            ,_______
                                                     ,_______    ,_______   ,_______                            ,_______    ,_______    ,_______
    ),
    [4] = LAYOUT(
KC_ESC     ,KC_F1       ,KC_F2      ,KC_F3      ,KC_F4      ,KC_F5      ,KC_F6      ,KC_F7      ,KC_F8      ,KC_F9      ,KC_F10     ,KC_F11     ,KC_F12     ,KC_PSCR    ,KC_SCRL    ,KC_PAUS    ,TG(1)      ,MO(1),
KC_EQL     ,KC_1        ,KC_2       ,KC_3       ,KC_4       ,KC_5                                                       ,KC_6       ,KC_7       ,KC_8       ,KC_9       ,KC_0       ,KC_MINS,
KC_TAB     ,KC_Q        ,KC_W       ,KC_E       ,KC_R       ,KC_T                                                       ,KC_Y       ,KC_U       ,KC_I       ,KC_O       ,KC_P       ,KC_BSLS,
KC_CAPS    ,KC_A        ,KC_S       ,KC_D       ,KC_F       ,KC_G                                                       ,KC_H       ,KC_J       ,KC_K       ,KC_L       ,KC_SCLN    ,KC_QUOT,
KC_LSFT    ,KC_Z        ,KC_X       ,KC_C       ,KC_V       ,KC_B                                                       ,KC_N       ,KC_M       ,KC_COMM    ,KC_DOT     ,KC_SLSH    ,KC_RSFT,
            KC_GRV      ,KC_INS     ,KC_LBRC    ,KC_RBRC                                                                ,KC_UP      ,KC_DOWN    ,KC_LEFT    ,KC_RGHT
                                                            ,KC_LCTL    ,KC_LALT                            ,KC_RGUI    ,KC_RCTL
                                                                        ,KC_HOME                            ,KC_PGUP
                                                ,KC_BSPC    ,KC_DEL     ,KC_END                             ,KC_PGDN    ,KC_ENTER   ,KC_SPC
   ),
    [5] = LAYOUT(
      _______     ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______    ,_______,
      _______    ,_______    ,_______     ,_______     ,_______     ,_______                                                    ,_______    ,_______     ,_______    ,_______    ,_______    ,_______,
      _______    ,_______    ,_______   ,_______      ,_______      ,_______                                                    ,_______    ,_______      ,_______      ,_______      ,_______    ,_______,
      _______    ,_______    ,_______      ,_______      ,_______      ,_______                                                    ,_______    ,_______      ,_______      ,_______      ,_______    ,_______,
      _______    ,_______    ,_______      ,_______      ,_______      ,_______                                                    ,_______      ,_______      ,_______      ,_______      ,_______    ,_______,
                  _______    ,_______    ,_______    ,_______                                                                            ,_______    ,_______    ,_______    ,_______
                                                                 ,_______   ,_______                            ,_______    ,_______
                                                                            ,_______                            ,_______
                                                     ,_______    ,_______   ,_______                            ,_______    ,_______    ,_______
    )
};

void matrix_init_user(void) {
    for (int i = 0; i < LED_COUNT; i++) {
        gpio_set_pin_output(led_pins[i]);
        gpio_write_pin_high(led_pins[i]);  // all off by default
    }
}

void matrix_scan_user(void) {
    process_leds();
}

// Process the matrix state before it's used
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    // Only block column 0 when it AND columns 1-3 are both detected in the same row
    if (record->event.key.col == 0) {
        uint8_t row = record->event.key.row;
        if (matrix_is_on(row, 0) && (matrix_is_on(row, 1) || matrix_is_on(row, 2) || matrix_is_on(row, 3))) {
            return false;  // Block this phantom column 0 key press
        }
    }
    return process_record_user(keycode, record);
}

// // void keyboard_post_init_kb(void) {
// //     initialize_tap_dance();
// // };
// // // layer_state_t layer_state_set_user(layer_state_t state) {
// // //     return state;  // no flashing logic here anymore
// // // }
// //
// void keyboard_post_init_user(void) {
// //   // Customise these values to desired behaviour
//   // debug_enable=true;
//   // debug_matrix=true;
//   // debug_keyboard=true;
// }
//
