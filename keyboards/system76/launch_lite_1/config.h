/*
 *  Copyright (C) 2021  System76
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

// can we sleep the kb lights?
#define RGBLIGHT_SLEEP

/* mod tap speedups
Ok so we can do a few things:
- tapping term config per key and go low
- tap_delay to work with rcmd? no cause rcmd depends on press not release

we need to send hyper as fast as possible so rcmd can listen for key press.
i dont think it's right for us to try and delay the key press here. just message alin about QoS or something.
Or echo the presses in userspaces to add delay. Our only goal in qmk is to minimize the hyper holding action latency.

We could use one shot to allow releasing caps before the key, but we should just get better at typing firmly. */
// tapping term timeout. on timeout the Hold action is ultimately chosen
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
// early Hold from mod tap if another key is pressed. permissive for fallback cause i swear this one doesnt work
// #define HOLD_ON_OTHER_KEY_PRESS
// #define PERMISSIVE_HOLD
// Retro tap experiment to see if we can lower the hyper tap term any further
#define RETRO_TAPPING_PER_KEY
// -----------------------------------------------
// disable oneshot_tap_toggle. all the internal uses of this check for > 1 before entering.
#define ONESHOT_TAP_TOGGLE 0
#define ONESHOT_TIMEOUT 2500
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

/*
 * Key matrix pins
 * ROWS: AVR pins used for rows, top to bottom
 * COLS: AVR pins used for columns, left to right
 */
#define MATRIX_ROW_PINS { F1, F2, F3, F4, F5 }
#define MATRIX_COL_PINS { C6, C5, C4, C3, C2, C1, C7, A7, A6, A5, A4, E6, C0, E7 }

/*
 * Diode Direction
 * COL2ROW = COL => Anode (+), ROW => Cathode (-)
 * ROW2COL = ROW => Anode (+), COL => Cathode (-)
 */
#define DIODE_DIRECTION COL2ROW

#ifdef RGB_MATRIX_ENABLE
#    define WS2812_DI_PIN F7
#    define RGB_MATRIX_LED_COUNT 70
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 176              // Limit max brightness (keep for safety)
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR // Start with solid color mode
#    define RGB_MATRIX_DEFAULT_HUE 212                     // Set your preferred color (142 is greenish)
#    define RGB_MATRIX_DEFAULT_SAT 30
#    define RGB_MATRIX_DEFAULT_VAL 100
#    define RGB_MATRIX_DEFAULT_SPD 127
#    define RGB_MATRIX_DISABLE_ALL_EFFECTS                 // Disable ALL built-in RGB animations
#    define DISABLE_RGB_MATRIX_ANIMATIONS
#    define RGB_MATRIX_DISABLE_KEYCODES                    // Disables keycodes for changing matrix (only allow via code)
#endif  // RGB_MATRIX_ENABLE

// Mechanical locking support; use KC_LCAP, KC_LNUM, or KC_LSCR instead in keymap
#define LOCKING_SUPPORT_ENABLE

// Locking resynchronize hack
#define LOCKING_RESYNC_ENABLE

// I2C {
#define F_SCL 100000UL // Run I2C bus at 100 kHz
#define I2C_START_RETRY_COUNT 20
#define I2C_TIMEOUT 100 // milliseconds
// } I2C

// EEPROM {
#define EEPROM_SIZE 1024
// TODO: Refactor with new user EEPROM code (coming soon)
#define EEPROM_MAGIC 0x76EC
#define EEPROM_MAGIC_ADDR 64
// Bump this every time we change what we store
// This will automatically reset the EEPROM with defaults
// and avoid loading invalid data from the EEPROM
#define EEPROM_VERSION 0x02
#define EEPROM_VERSION_ADDR (EEPROM_MAGIC_ADDR + 2)
// } EEPROM

// Dynamic keymap {
#define DYNAMIC_KEYMAP_LAYER_COUNT 4
#define DYNAMIC_KEYMAP_MACRO_COUNT 0
// Dynamic keymap starts after EEPROM version
#define DYNAMIC_KEYMAP_EEPROM_ADDR (EEPROM_VERSION_ADDR + 1)
// Dynamic macro starts after dynamic keymaps, it is disabled
#define DYNAMIC_KEYMAP_MACRO_EEPROM_ADDR (DYNAMIC_KEYMAP_EEPROM_ADDR + (DYNAMIC_KEYMAP_LAYER_COUNT * MATRIX_ROWS * MATRIX_COLS * 2))
#define DYNAMIC_KEYMAP_MACRO_EEPROM_SIZE 0
// } Dynamic keymap

// System76 EC {
#define SYSTEM76_EC_EEPROM_ADDR (DYNAMIC_KEYMAP_MACRO_EEPROM_ADDR + DYNAMIC_KEYMAP_MACRO_EEPROM_SIZE)
#define SYSTEM76_EC_EEPROM_SIZE (EEPROM_SIZE - SYSTEM76_EC_EEPROM_ADDR)
// } System76 EC
