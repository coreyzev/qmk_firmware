/* Copyright 2017 Wunder
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
#include "../../xd75.h"

#define XXXXXXX KC_NO
#define _______ KC_TRNS

// Layer shorthand
#define _SW 0
#define _FN 1
#define _G1 2
#define _G2 3

//Tap Dance Declarations
enum {
  TD_CLN = 0,
  TD_QMRK = 1,
  TD_MINS = 2,
  TD_EQL = 3
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_CLN]    = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_BSLASH),
  [TD_QMRK]   = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_QUES),
  [TD_MINS]   = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_MINS),
  [TD_EQL]    = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_EQL),
  // [TD_TAB_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* SPACEWOLF
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | TD(9,-)| TD(0,=)| BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | 7      | 8      | 9      | Y      | U      | I      | O      | P      | TD(;,|)|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | LCTRL  | A      | S      | D      | F      | G      | 4      | 5      | 6      | H      | J      | K      | L      | '      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | 1      | 2      | 3      | N      | M      | ,      | .      | TD(/,?)| UP     |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | FN     | LGUI   | LALT   | PG UP  | SPACE  | SPACE  | 0      | .      |        | SPACE  |SPACE   | PG DN  | LEFT   | RIGHT  | DOWN   |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_SW] = { /* QWERTY */
  { KC_GESC,          KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_MINS, KC_GRV,  KC_EQL,  KC_6,   KC_7,   KC_8,    TD(TD_MINS), TD(TD_EQL), KC_BSPC },
  { LT(_FN, KC_TAB),  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_P7,   KC_P8,   KC_P9,   KC_Y,   KC_U,   KC_I,    KC_O,        KC_P,       TD(TD_CLN)},
  { KC_LCTL,          KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_P4,   KC_P5,   KC_P6,   KC_H,   KC_J,   KC_K,    KC_L,        KC_QUOT,    KC_ENT  },
  { KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_P1,   KC_P2,   KC_P3,   KC_N,   KC_M,   KC_COMM, KC_DOT,      TD(TD_QMRK),KC_UP },
  { MO(_FN),          KC_LGUI, KC_LALT, KC_PGUP, KC_SPC, KC_SPC, KC_P0,   KC_PDOT, _______, KC_SPC, KC_SPC, KC_PGDN, KC_LEFT,     KC_RGHT,    KC_DOWN},
 },

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | F1     | F2     | F3     | F4     | F5     | F6     | GAMING | PR SCR |        |        |        | [      | ]      | DEL    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | CALC   | RGB TG | RGB HU+| RGB SA+| RGB VA+| F7     |        |        | KP -   |        |        |        |        | GAMING |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | NEXT   | RGB MO | RGB HU-| RGB SA-| RGB VA-| F8     |        |        | KP +   |        |        |        |        |CTL(ENT)|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        | F9     | F11    |        | PENT   |        |        | PLAY   | MUTE   | VOL+   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        | HOME   |        |        | F10    | F12    | NUM    | PENT   |        | END    | PREV   | NEXT   | VOL-   |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_FN] = { /* FUNCTION */
  { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   TO(_G1), KC_PSCR, _______, _______, _______, KC_LBRC, KC_RBRC, KC_DEL },
  { _______, KC_CALC, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_F7,   _______, _______, KC_PMNS, _______, _______, _______, _______, TO(_G1) },
  { KC_MPRV, KC_MNXT, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_F8,   RESET,   _______, KC_PPLS, _______, _______, _______, _______, LCTL(KC_ENT) },
  { _______, _______, RGB_M_X, RGB_M_B, RGB_M_G, RGB_M_R, KC_F9,   KC_F11,  _______, KC_PENT, _______, _______, KC_MPLY, KC_MUTE, KC_VOLU },
  { _______, _______, _______, KC_HOME, KC_SPC,  KC_SPC,  KC_F10,  KC_F12,  KC_NLCK, KC_PENT, KC_SPC,  KC_END,  KC_MPRV, KC_MNXT, KC_VOLD },
 },

/* GAMING
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | F13    | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | LALT   | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | 7      | 8      | 9      | PR SCR |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | 4      | 5      | 6      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | LCTRL  | A      | S      | D      | F      | G      | H      | J      | K      | L      | UP     | 1      | 2      | 3      | SHFTF12|
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LSHIFT | Z      | X      | C      | SPACE  | SPACE  | SPACE  | GAME # |        | LEFT   | DOWN   | RIGHT  | SHFTF10| SHFTF11| QWERTY |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_G1] = { /* GAMING */
  { KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,  KC_BSPC },
  { KC_LALT, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_P7,   KC_P8,   KC_P9,   KC_PSCR },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_P4,   KC_P5,   KC_P6,   KC_ENT  },
  { KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_UP,   KC_P1,   KC_P2,   KC_P3,   LSFT(KC_F12) },
  { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_SPC,  KC_SPC,  KC_SPC,  MO(_G2), _______, KC_LEFT, KC_DOWN, KC_RIGHT,LSFT(KC_F10),  LSFT(KC_F11),  TO(_SW) },
 },

/* GAMING NUM
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        | SLEEP  |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | 7      | 8      | 9      |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        | 4      | 5      | 6      |        |        |        | RESET  |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        | 1      | 2      | 3      |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_G2] = { /* GAMING NUM */
  { _______, _______, _______, _______, _______, _______, _______, _______, KC_SLEP, _______, _______, _______, _______, _______, _______},
  { _______, KC_P7,   KC_P8,   KC_P9,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  { _______, KC_P4,   KC_P5,   KC_P6,   _______, _______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______},
  { _______, KC_P1,   KC_P2,   KC_P3,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
 }
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
