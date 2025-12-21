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

#pragma once


/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 16

#define ONESHOT_TIMEOUT 500

#define SPI_MODE 3
#define ST7789

#define SPI_DRIVER SPID1

/* LCD Configuration */
#define SPI_SCK_PIN GP10 // SCK
#define SPI_MOSI_PIN GP11 // Tx
#define LCD_RST_PIN GP12 // Tx
#define LCD_DC_PIN GP27 // Tx
#define LCD_CS_PIN GP9 // Tx
#define LCD_BLK_PIN GP20 // Tx

// #define SPI_DRIVER SPID0
// #define SPI_SCK_PIN GP2 // SCK
// #define SPI_MOSI_PIN GP16 // Tx
// #define SPI_MISO_PIN GP19 // Tx
//
// /* LCD Configuration */
// #define LCD_RST_PIN GP16 // Tx
// #define LCD_DC_PIN GP23 // Tx
// #define LCD_CS_PIN GP21 // Tx
//#define LCD_BLK_PIN GP2// Tx
#define LCD_SPI_DIVISOR 4
#define LCD_WAIT_TIME 150
#define LCD_ROTATION QP_ROTATION_0
#define LCD_OFFSET_X 0
#define LCD_OFFSET_Y 0

#define LCD_WIDTH 240
#define LCD_HEIGHT 280
//#define LCD_INVERT_COLOR
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 0
// #define MATRIX_HAS_GHOST // Not sure how to use this to fix my ghosting...

