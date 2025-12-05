/*
Copyright 2018 Mattia Dal Ben <matthewdibi@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers {
   _QWERTY,
   _SYMB,
   _NAV,
   _ADJUST
};

// Shortcut to make keymap more readable
#define SYM_L   MO(_SYMB)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_BSLS)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAMI LT(_NAV, KC_MINS)

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
KC_EQL      ,KC_1       ,KC_2       ,KC_3       ,KC_4       ,KC_5                                                       ,KC_6       ,KC_7       ,KC_8       ,KC_9       ,KC_0       ,KC_MINS,
KC_TAB      ,KC_Q       ,KC_W       ,KC_F       ,KC_P       ,KC_B                                                       ,KC_J       ,KC_L       ,KC_U       ,KC_Y       ,KC_SCLN    ,KC_BSLS,
KC_CAPS     ,KC_A       ,KC_R       ,KC_S       ,KC_T       ,KC_G                                                       ,KC_M       ,KC_N       ,KC_E       ,KC_I       ,KC_O       ,KC_QUOT,
KC_LSFT     ,KC_Z       ,KC_X       ,KC_C       ,KC_D       ,KC_V                                                       ,KC_K       ,KC_H       ,KC_COMM    ,KC_DOT     ,KC_SLSH    ,KC_RSFT,
             KC_HOME    ,KC_PGDN    ,KC_PGUP    ,KC_END                                                                             ,KC_LEFT    ,KC_DOWN    ,KC_UP      ,KC_RGHT
                                                            ,KC_LCTL   ,KC_LALT                            ,KC_LALT      ,KC_RCTL
                                                                       ,KC_LGUI                            ,KC_RGUI
                                                ,KC_BSPC     ,KC_DEL   ,KC_MEH                             ,KC_MEH      ,KC_ENTER   ,KC_SPC
  )
};
