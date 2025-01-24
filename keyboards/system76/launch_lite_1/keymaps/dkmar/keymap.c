#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Layer 0, default layer
____________________________________________________________________________________________________________________________________________
|        |        |        |        |        |        |        |        |        |        |        |        |        |             |        |
|  ESC   |   1    |   2    |   3    |   4    |   5    |   6    |   7    |   8    |   9    |   0    |  _ -   | =  +   | BACKSPACE   |  HOME  |
|________|________|________|________|________|________|________|________|________|________|________|________|________|_____________|________|
|            |        |        |        |        |        |        |        |        |        |        |  [     |   ]    |         |        |
|     TAB    |   Q    |   W    |   E    |   R    |   T    |   Y    |   U    |   I    |   O    |   P    |  {     |   }    |  |   \  |  PGUP  |
|____________|________|________|________|________|________|________|________|________|________|________|________|________|_________|________|
  |            |        |        |        |        |        |        |        |        |        |   ;    |   '    |            |   |        |
  |    HYPR    |   A    |   S    |   D    |   F    |   G    |   H    |   J    |   K    |   L    |   :    |   "    |   ENTER    |   |  PGDN  |
  |____________|________|________|________|________|________|________|________|________|________|________|________|____________|___|________|
  |                |        |        |        |        |        |        |        |   ,    |    .   |   /    |            |        |        |
  |     SHIFT      |   Z    |   X    |   C    |   V    |   B    |   N    |   M    |   <    |    >   |   ?    |   SHIFT    |   UP   |  END   |
  |________________|________|________|________|________|________|________|________|________|________|________|____________|________|________|
  |            |        |       |        |                 |                 |        |        |             |   |        |        |        |
  |    LGUI    |  CTRL  | LALT  | LGUI   |    SPACE        |   BACKSPACE     |  ESC   |  RALT  |     FN      |   |  LEFT  |  DOWN  | RIGHT  |
  |____________|________|_______|________|_________________|_________________|________|________|_____________|   |________|________|________|
*/

  [0] = LAYOUT(
    KC_GRAVE,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,      KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,  KC_PGUP,
          LCAG_T(KC_ESC),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,    KC_ENT,       KC_PGDN,
          OSM(MOD_LSFT),     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_RSFT,    KC_UP, KC_END,
          OSM(MOD_LGUI), KC_LCTL,   KC_LALT, KC_LGUI,     KC_SPC,           LT(1, KC_SPC),    KC_RGUI,    KC_RALT,   KC_RCTL,         KC_LEFT, KC_DOWN, KC_RGHT
  ),

    /* Layer 1, function layer
____________________________________________________________________________________________________________________________________________
|        |        |        |        |        |        |        |        |        |        |        |        |        |             | PLAY/  |
|   ~    |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |   F7   |   F8   |   F9   |  F10   |  F11   |  F12   |  DELETE     | PAUSE  |
|________|________|________|________|________|________|________|________|________|________|________|________|________|_____________|________|
|            |        |        |        |        |        |        |        |        |        |        |  LED   |  LED   |  LED    | VOLUME |
|PRINT SCREEN|        |        |        |        |        |        |  PGUP  |  HOME  |  PGDN  |        |  DOWN  |  UP    | TOGGLE  |   UP   |
|____________|________|________|________|________|________|________|________|________|________|________|________|________|_________|________|
  |            |        |  VOL   |  VOL   |        |        |        |        |        |        |        |        |            |   | VOLUME |
  |            |        |  DOWN  |  UP    |  MUTE  |        |  LEFT  |  DOWN  |   UP   | RIGHT  |        |        |            |   |  DOWN  |
  |____________|________|________|________|________|________|________|________|________|________|________|________|____________|___|________|
  |                |        |        |        |        |        |        |        |        |        |        |            |        |        |
  |                |        |        |        |        |        |  END   |        |        |        |        |            |  PGUP  |  MUTE  |
  |________________|________|________|________|________|________|________|________|________|________|________|____________|________|________|
  |            |        |       |        |                 |                 |        |        |             |   |        |        |        |
  |            |        |       |        |    ENTER        |   DELETE        |        |        |             |   |  HOME  |  PGDN  |  END   |
  |____________|________|_______|________|_________________|_________________|________|________|_____________|   |________|________|________|

* 'RESET' resets the controller and puts the board into firmware flashing mode. If this key is hit accidentally, just unplug the board
*        and plug it back in.
*/

  [1] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,      QK_BOOT,
        KC_PSCR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_HOME, KC_PGDN, KC_TRNS, RGB_VAD, RGB_VAI, RGB_TOG, KC_VOLU,
          KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,    KC_TRNS,     KC_VOLD,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_END,  KC_TRNS, KC_TRNS, KC_TRNS, KC_GRAVE,   KC_TRNS,  KC_PGUP, KC_MUTE,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_ENT,           KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,       KC_HOME,  KC_PGDN, KC_END
  ),

  [2] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,          KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS
  ),

  [3] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,          KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

// tapping term timeout
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case LCAG_T(KC_ESC):
        case LT(1, KC_SPC):
            return 0;
        default:
            return TAPPING_TERM;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCAG_T(KC_ESC):
        case LT(1, KC_SPC):
            return true;
        default:
            return false;
    }
}
