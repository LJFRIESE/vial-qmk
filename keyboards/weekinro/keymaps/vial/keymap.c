#include "qp_internal.h"
#include QMK_KEYBOARD_H
#include "quantum.h"
#include "keycodes.h"
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
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

enum { TD_ESC };

// Shortcut to make keymap more readable

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSLS, ESC_CAPS, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_LCTL, NUM_NAV, TD_NUM, KC_LCTL, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_LGUI, KC_LALT, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_BSPC, KC_DEL, KC_MEH, KC_HYPR, LT_SYMB, KC_SPC),
    [_SYMB] = LAYOUT(KC_EQL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_TRNS, LSFT(KC_EQL), LSFT(KC_7), LSFT(KC_8), KC_GRV, KC_TRNS, KC_TRNS, KC_MINS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_EQL, LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), KC_TRNS, KC_TRNS, KC_UNDS, KC_LPRN, KC_RPRN, KC_TRNS, KC_TRNS, KC_TRNS, LSFT(KC_GRV), LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LABK, LSFT(KC_LBRC), LSFT(KC_RBRC), KC_RABK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [_NUM]  = LAYOUT(MEH(KC_EQL), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MEH(KC_TAB), MEH(KC_LEFT), MEH(KC_DOWN), MEH(KC_UP), MEH(KC_RIGHT), KC_F23, KC_TRNS, KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_TRNS, KC_TRNS, KC_6, KC_5, KC_6, KC_TRNS, KC_F24, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_1, KC_2, KC_3, KC_TRNS, MEH(KC_HOME), MEH(KC_PGDN), MEH(KC_PGUP), MEH(KC_END), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT, KC_TRNS, KC_TRNS, KC_0),
};

// uint8_t counter = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    if (record->event.pressed == 1) {
        uprintf("row: %2u, ucol: %2u\n", record->event.key.row, record->event.key.col);
    }
#endif
    return true;
}

// Process the matrix state before it's used
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    uint8_t row = record->event.key.row;
    uint8_t col = record->event.key.col;

    if ((matrix_is_on(row + 1, col) && matrix_is_on(row, col + 1) && matrix_is_on(row, col + 1))) {
        return false; // Block this phantom column 0 key press
    }
    if ((matrix_is_on(row, col + 1) && matrix_is_on(row - 1, col) && matrix_is_on(row, col + 1))) {
        return false; // Block this phantom column 0 key press
    }
    return process_record_user(keycode, record);
}


#include "print.h"
#include "qp.h"
#include "qp_comms.h"
#include "qp_st77xx_opcodes.h"
#include "color.h"
#include "gfx/cat240x240.qgf.h"

painter_device_t lcd;

void keyboard_post_init_kb(void) {
    wait_ms(5000);
#ifdef CONSOLE_ENABLE
    uprintf("%s", "hi\n");
#endif

    lcd =qp_st7789_make_spi_device(LCD_HEIGHT, LCD_WIDTH, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, SPI_MODE);
    qp_init(lcd, 0);
    // Power on display, fill with white

    // Some screens have inverted colors
    qp_comms_start(lcd);
    qp_comms_command(lcd, ST77XX_CMD_INVERT_ON);
    qp_comms_stop(lcd);

    // Display offset
    qp_set_viewport_offsets(lcd, LCD_OFFSET_X, LCD_OFFSET_Y);

    // Power on display, fill with white
    qp_power(lcd, 1);
    qp_rect(lcd, 0, 0, 40, 40, HSV_WHITE, 1);

    // Paint catpaste/Katten Paste
    // painter_image_handle_t logo_image = qp_load_image_mem(gfx_cat);
    // qp_drawimage(lcd, 0, 0, logo_image);

    keyboard_post_init_user();
#ifdef CONSOLE_ENABLE
    uprintf("%s", "bye\n");
#endif
}

