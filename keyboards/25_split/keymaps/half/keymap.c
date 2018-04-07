#include "25_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _0 0

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* 0
 * ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |
 * |------+------+------+------+------|
 * |   1  |   2  |   3  |   4  |   5  |
 * |------+------+------+------+------|
 * |   Q  |   W  |   E  |   R  |   T  |
 * |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |
 * |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |
 * | LCTL | LALT | Lr 3 | Lr 4 | Lr 2 | (momentary toggle)
 * `----------------------------------'
 *
 * ,----------------------------------.
 * |  F6  |  F7  |  F8  |  F9  |  F10 |
 * +------+------+------+------+------|
 * |   6  |   7  |   8  |   9  |   0  |
 * +------+------+------+------+------|
 * |   Y  |   U  |   I  |   O  |   P  |
 * +-------------+------+------+------|
 * |   H  |   J  |   K  |   L  |  ESC |
 * +------|------+------+------+------|
 * |   N  |   M  |   ,  |   .  | ENTR |
 * | Lr 1 | Lr 5 | RALT | RCTL | RSHFT| (momentary toggle)
 * `----------------------------------'
 */
[_0] = KEYMAP( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  \
  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, \
  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  \
  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20, \
  KC_F21,  KC_F22,  KC_F23,  KC_F24,  RCTL(KC_F10),\
  \
  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, \
  _______,  _______, _______, _______, _______, \
  _______, _______, _______, _______, _______ \
  \
)
};

void matrix_init_user(void) { // Runs boot tasks for keyboard
    rgblight_enable();
    rgblight_sethsv(0,255,255);
    rgblight_mode(10);
};
