/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
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

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"


/* USB Device descriptor parameter */

#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0A0C
#define DEVICE_VER      0x0F25
#define MANUFACTURER    di0ib
#define PRODUCT         The 5x5 Keyboard
#define DESCRIPTION     A split 50 key keyboard

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 5

#define MATRIX_COL_PINS { F4, F5, F6, F7, B1 }
#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4 }


/* use i2c instead of serial */
//#define USE_I2C

//#define I2C_WRITE_TEST_CODE

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LGUI)) \
)

/* ws2812 RGB LED */
#define RGB_DI_PIN B6
#define RGBLIGHT_TIMER
#define RGBLED_NUM 2    // Number of LEDs
#define ws2812_PORTREG  PORTD
#define ws2812_DDRREG   DDRD


/* Action tapping settings */
#define TAPPING_TERM    200 // default 200
/* #define TAPPING_TOGGLE  2   // default 5 */
/* #define ONESHOT_TIMEOUT 5000 // default undefined */
#define ONESHOT_TAP_TOGGLE 2

#endif  // CONFIG_H
