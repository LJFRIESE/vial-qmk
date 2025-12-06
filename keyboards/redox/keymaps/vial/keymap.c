#include "config.h"
#include QMK_KEYBOARD_H
#include "quantum.h"
#include "keycodes.h"
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _SYMB 1
#define _NAV 2
#define _ADJUST 3

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    SYMB,
    NAV,
    ADJUST,
};

enum {
    TD_ESC
};

// Shortcut to make keymap more readable
#define MO_NAV   MO(_NAV)

#define LT_SYMB LT(_SYMB, KC_ENT)
#define KC_NAMI LT(_NAV, KC_MINS)

tap_dance_action_t qk_tap_dance_actions[VIAL_TAP_DANCE_ENTRIES] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
            KC_EQL      ,KC_1       ,KC_2       ,KC_3       ,KC_4       ,KC_5                                                       ,KC_6       ,KC_7       ,KC_8       ,KC_9       ,KC_0       ,KC_MINS,
            KC_TAB      ,KC_Q       ,KC_W       ,KC_F       ,KC_P       ,KC_B                                                       ,KC_J       ,KC_L       ,KC_U       ,KC_Y       ,KC_SCLN    ,KC_BSLS,
            TD(TD_ESC)  ,KC_A       ,KC_R       ,KC_S       ,KC_T       ,KC_G                                                       ,KC_M       ,KC_N       ,KC_E       ,KC_I       ,KC_O       ,KC_QUOT,
            KC_LSFT     ,KC_Z       ,KC_X       ,KC_C       ,KC_D       ,KC_V   ,KC_LCTL    ,MO_NAV     ,KC_RALT ,KC_RCTL          ,KC_K       ,KC_H       ,KC_COMM    ,KC_DOT     ,KC_SLSH    ,KC_RSFT,
            KC_HOME     ,KC_PGDN    ,KC_PGUP    ,KC_END                                      ,KC_LGUI     ,KC_RGUI                   ,KC_LEFT    ,KC_DOWN    ,KC_UP      ,KC_RGHT
                                                                            ,KC_BSPC, KC_DEL,KC_MEH      ,KC_MEH  ,LT_SYMB,KC_SPC
            ),
    [1] = LAYOUT(
            _______     ,_______       ,_______       ,_______       ,_______       ,_______                                                       ,_______       ,_______       ,_______       ,_______       ,_______       ,_______,
            _______     ,LSFT(KC_EQL),LSFT(KC_7)      ,LSFT(KC_8)        ,LSFT(KC_GRV)   ,_______                                                       ,_______       ,KC_MINS    ,KC_LBRC        ,KC_RBRC        ,_______         ,_______,
            _______     ,KC_EQL      ,LSFT(KC_4)      ,LSFT(KC_5)        ,LSFT(KC_6)     ,_______                                                       ,_______       ,KC_UNDS    ,KC_LPRN        ,KC_RPRN       ,_______        ,_______         ,
            _______     ,LSFT(KC_GRV),LSFT(KC_1)      ,LSFT(KC_2)        ,LSFT(KC_3)     ,_______   ,_______    ,_______     ,_______ ,_______          ,_______       ,KC_LABK    ,LSFT(KC_LBRC)  ,LSFT(KC_RBRC)  ,KC_RABK     ,_______,
            _______     ,_______       ,_______       ,_______                                 ,_______    ,_______     ,_______ ,_______    ,_______      ,_______
                                                                                     ,_______  ,_______    ,_______     ,_______ ,_______    ,_______
            ),
    [2] = LAYOUT(
            _______     ,_______       ,_______       ,_______       ,_______       ,_______                                                       ,_______       ,_______       ,_______       ,_______       ,_______       ,_______,
            _______     ,_______       ,_______       ,_______       ,_______       ,_______                                                       ,_______       ,_______       ,_______       ,_______       ,_______    ,_______,
            _______     ,_______       ,_______       ,_______       ,_______       ,_______                                                       ,_______       ,_______       ,_______       ,_______       ,_______       ,_______,
            _______     ,_______       ,_______       ,_______       ,_______       ,_______   ,_______    ,_______     ,_______ ,_______          ,_______       ,_______       ,_______    ,_______     ,_______    ,_______,
            _______     ,_______       ,_______       ,_______                                 ,_______    ,_______     ,_______ ,_______    ,_______      ,_______
                                                                                     ,_______  ,_______    ,_______     ,_______ ,_______    ,_______
            ),
};

// uint8_t counter = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    if (record->event.pressed == 1) {
    uprintf("row: %2u, ucol: %2u\n",record->event.key.row, record->event.key.col);
    }
#endif
    return true;
}


// Process the matrix state before it's used
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    // if (record->event.pressed == 1) {
    //     counter = counter + 1;
    //     uprintf("%2u: | kc: 0x%04X, col: %2u, row: %2u, pressed: %u, \n", counter, keycode, record->event.key.col, record->event.key.row, record->event.pressed);
    // };
    uint8_t row = record->event.key.row;
    uint8_t col = record->event.key.col;

    if ((matrix_is_on(row+1,col) && (matrix_is_on(row, col))) && (matrix_is_on(row,col+1) && (matrix_is_on(row, col))) && (matrix_is_on(row,col) && (matrix_is_on(row, col+1)))){
        return false;  // Block this phantom column 0 key press
    }
    if ((matrix_is_on(row,col) && (matrix_is_on(row, col+1))) && (matrix_is_on(row-1,col) && (matrix_is_on(row, col))) && (matrix_is_on(row,col) && (matrix_is_on(row, col+1)))){
        return false;  // Block this phantom column 0 key press
    }
    return process_record_user(keycode, record);
}
