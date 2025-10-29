#include QMK_KEYBOARD_H

// tap dance
enum { TD_LSFT };
typedef enum {
    TD_NONE,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP
} td_state_t;
td_state_t cur_dance(tap_dance_state_t *state);
void       lsft_each(tap_dance_state_t *state, void *user_data);
void       lsft_finished(tap_dance_state_t *state, void *user_data);
void       lsft_reset(tap_dance_state_t *state, void *user_data);

// sticky HJKL arrow keys
// If we are on layer 2 and hit HJKL then we persist their arrow key behavior until other key is used
enum custom_keycodes {
    NAV_H = SAFE_RANGE,
    NAV_J,
    NAV_K,
    NAV_L
};

// layers
enum {
    _BASE = 0,
    _FN = 2,
    _NAV = 3
};
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

  [_BASE] = LAYOUT(
    KC_GRAVE,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,      KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,  KC_PGUP,
          LCAG_T(KC_ESC),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,  KC_ENT,       KC_PGDN,
          TD(TD_LSFT),     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_RSFT,    KC_UP, KC_END,
          OSM(MOD_LCTL), KC_LCTL,   KC_LALT, KC_LGUI,    KC_SPC,  OSL(2),    OSM(MOD_RGUI),    KC_RALT,   KC_RCTL,  KC_LEFT, KC_DOWN, KC_RGHT
  ),


  [1] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,          OSL(2),      KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS
  ),

  [_FN] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,      QK_BOOT,
        KC_PSCR, S(KC_1),    S(KC_2),    S(KC_3),    S(KC_4),    S(KC_5),    S(KC_6),    S(KC_7),    S(KC_8),    S(KC_9),    S(KC_0),    S(KC_MINS), S(KC_EQL), RGB_TOG, KC_VOLU,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_DOLLAR, KC_LEFT_PAREN, KC_TRNS, NAV_H, NAV_J, NAV_K, NAV_L, KC_TRNS, KC_GRAVE,    KC_TRNS,     KC_VOLD,
          SC_LSPO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_DOLLAR,  KC_PGUP, KC_MUTE,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_MEDIA_PLAY_PAUSE, KC_BSPC,       KC_TRNS, KC_TRNS, TG(1),       KC_HOME,  KC_PGDN, KC_END
  ),

  // NAV layer
  [_NAV] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,   KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,   KC_MEDIA_PLAY_PAUSE,      KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS
  ),
};

static inline bool is_NAV_key(uint16_t kc) {
    switch (kc) {
        // Arrow keys
        case KC_LEFT: case KC_DOWN: case KC_UP: case KC_RGHT:
        // Spacebar play/pausing key
        case KC_MEDIA_PLAY_PAUSE:
        // Basic modifiers
        case KC_LCTL: case KC_RCTL:
        case KC_LSFT: case KC_RSFT: case TD(TD_LSFT):
        case KC_LALT: case KC_RALT:
        case KC_LGUI: case KC_RGUI:
            return true;
        default:
            return false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;

    // special handle NAV layer
    if (IS_LAYER_ON(_NAV)) {
        // disable layer if key isn't an arrow (/hjkl) or modifier
        if (!is_NAV_key(keycode)) {
            layer_off(_NAV);
        }
        return true;
    }
    // activate NAV?
    switch (keycode) {
        case NAV_H: layer_on(_NAV); tap_code(KC_LEFT); return false;
        case NAV_J: layer_on(_NAV); tap_code(KC_DOWN); return false;
        case NAV_K: layer_on(_NAV); tap_code(KC_UP); return false;
        case NAV_L: layer_on(_NAV); tap_code(KC_RGHT); return false;
    }

    return true;
}

// tapping term timeout
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCAG_T(KC_ESC):
        case OSL(2):
            return 0;
        default:
            return TAPPING_TERM;
    }
}

// cant remember why we did this. does it really make recognition faster? yeah it means that u can do tap term as 0 and still get a tap if you dont press anything else.
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCAG_T(KC_ESC):
        case OSL(2):
            return true;
        default:
            return false;
    }
}

// tap dance
static td_state_t td_state;

// Determine the tap dance
td_state_t cur_dance(tap_dance_state_t *state) {
    switch (state->count) {
        case 1:
            if (!state->pressed)
                return TD_SINGLE_TAP;
            else
                return TD_SINGLE_HOLD;
        case 2:
            return TD_DOUBLE_TAP;
        default:
            return TD_NONE;
    }
}

// Function to handle initial tap
// we send shift immediately so that things like shift+mouse select work without holding for tapping_term
void lsft_each(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            register_code(KC_LSFT);
            break;
        case 2:
            // idk why but unregistering here instead of in TD_DOUBLE_TAP's finish
            // is necessary for double taps to send correctly idk.
            // do the cmd+shift+space here and exit early to eliminate latency
            tap_code16(LGUI(KC_SPC));
            unregister_code(KC_LSFT);
            // skip the finished handler
            // reset_tap_dance(state);
            break;
    }
}

// Function to handle finished taps
void lsft_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            // Send one-shot Shift on single tap
            // first unregister the shift from the initial tap
            unregister_code(KC_LSFT);
            // separate the ensuing osm shift from the one we just unregistered so it's not shift-shift
            tap_code(KC_NO);
            add_oneshot_mods(MOD_BIT(KC_LSFT));
            break;
        case TD_SINGLE_HOLD:
            // Hold to shift
            // we keep the registered shift
            break;
        case TD_DOUBLE_TAP:
            // Double tap: send shift twice
            // we closed the initial shift in lsft_each and now we just send a second
            // tap_code(KC_LSFT);
            // ok actually we're gonna hardcode map this to cmd+shift+space for the ghostty quick terminal
            //// tap_code16(LSFT(LGUI(KC_SPC))); nvm lets do this in lsft_each
            break;
        default:
            // insurance. just reset everything if tapped more than twice
            clear_oneshot_mods();
            caps_word_off();
            break;
    }
}

// Reset function to unregister on release
void lsft_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_HOLD:
            // Release shift on key up
            unregister_code(KC_LSFT);
            break;
        default:
            break;
    }
    td_state = TD_NONE;
}

// Define tap dance actions
tap_dance_action_t tap_dance_actions[] = {[TD_LSFT] = ACTION_TAP_DANCE_FN_ADVANCED(lsft_each, lsft_finished, lsft_reset)};
