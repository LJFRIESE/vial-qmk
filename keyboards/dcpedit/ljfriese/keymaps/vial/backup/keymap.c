#include "matrix.h"
#include "quantum.h"
#include "led.c"

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
#if defined(ENCODER_MAP_ENABLE)
#define NUM_LAYERS 6
#define ENCODER_DEFAULT ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)

const uint16_t PROGMEM encoder_map[NUM_LAYERS][NUM_ENCODERS][2] = {
    [0 ... (NUM_LAYERS - 1)] = { ENCODER_DEFAULT },
};
#endif
