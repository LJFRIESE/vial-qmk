/* Copyright 2017 Mattia Dal Ben
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"
#include "matrix.h"
#include "uart.h"

#define UART_MATRIX_RESPONSE_TIMEOUT 10000

void matrix_init_custom(void) {
    uart_init(1000000);
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    uint32_t timeout = 0;
    bool     changed = false;

    // the s character requests the RF slave to send the matrix
    uart_write('s');
    // trust the external keystates entirely, erase the last data
    uint8_t uart_data[11] = {0};

    // there are 10 bytes corresponding to 10 columns, and then an end byte
    for (uint8_t i = 0; i < 11; i++) {
        // wait for the serial data, timeout if it's been too long
        // this only happened in testing with a loose wire, but does no
        // harm to leave it in here
        while (!uart_available()) {
            timeout++;
            if (timeout > UART_MATRIX_RESPONSE_TIMEOUT) {
                break;
            }
        }

        if (timeout < UART_MATRIX_RESPONSE_TIMEOUT) {
            uart_data[i] = uart_read();
        } else {
            uart_data[i] = 0x00;
        }
    }

    // check for the end packet, the key state bytes use the LSBs, so 0xE0
    // will only show up here if the correct bytes were recieved
    if (uart_data[10] == 0xE0) {
        // shifting and transferring the keystates to the QMK matrix variable
        for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
            matrix_row_t current_row = (uint16_t)uart_data[i * 2] | (uint16_t)uart_data[i * 2 + 1] << 8;
            if (current_matrix[i] != current_row) {
                changed = true;
            }
            current_matrix[i] = current_row;
        }
        // This DOES catch the ghost, but also creates an artefact where the second keypress
        // is not detected until the first is released. Unsure if its better to eliminate the
        // ghost here or just catch it in the keymap.c
        //
        // Check for ghosts in rectangles
        // for (uint8_t row = 0; row < MATRIX_ROWS - 1; row++) {
        //     for (uint8_t col = 0; col < 15; col++) {
        //         bool tl = current_matrix[row] & (1 << col);
        //         bool tr = current_matrix[row] & (1 << (col + 1));
        //         bool bl = current_matrix[row + 1] & (1 << col);
        //         bool br = current_matrix[row + 1] & (1 << (col + 1));
        //
        //         int pressed_count = tl + tr + bl + br;
        //
        //         // If exactly 3 corners: clear the one opposite the empty corner (the ghost)
        //         if (pressed_count == 3) {
        //             if (!tl) {
        //                 current_matrix[row + 1] &= ~(1 << (col + 1)); // Clear BR (opposite TL)
        //             } else if (!tr) {
        //                 current_matrix[row + 1] &= ~(1 << col); // Clear BL (opposite TR)
        //             } else if (!bl) {
        //                 current_matrix[row] &= ~(1 << (col + 1)); // Clear TR (opposite BL)
        //             } else if (!br) {
        //                 current_matrix[row] &= ~(1 << col); // Clear TL (opposite BR)
        //             }
        //         }
        //     }
        // }
    }
    return changed;
};
