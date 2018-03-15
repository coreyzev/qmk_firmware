#include "25_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _0 0
#define _1 1
#define _2 2
#define _3 3
#define _4 4
#define _5 5
#define _QWERTY 6
#define _LOWER 7
#define _RAISE 8
#define _ADJUST 9

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |
 * |------+------+------+------+------|
 * |   Q  |   W  |   E  |   R  |   T  |
 * |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |
 * |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |
 * |------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |Lower |Space |
 * `----------------------------------'
 *
 * ,----------------------------------.
 * |   6  |   7  |   8  |   9  |   0  |
 * +------+------+------+------+------|
 * |   Y  |   U  |   I  |   O  |   P  |
 * +-------------+------+------+------|
 * |   H  |   J  |   K  |   L  |   ;  |
 * +------|------+------+------+------|
 * |   N  |   M  |   ,  |   .  |   /  |
 * +------+------+------+------+------|
 * |Space |Raise | Left | Down |  Up  |
 * `----------------------------------'
 */
[_0] = KEYMAP( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    \
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     \
  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  \
  \
  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   \
  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   \
  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,\
  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,\
  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP   \
)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
