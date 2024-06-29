/*
Copyright 2022 qwertykeys
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
#include "features/achordion.h"
#include "features/custom_shift_keys.h"
#include "features/layer_lock.h"

enum custom_keycodes {
  LLOCK = SAFE_RANGE,
  F_LOOP,
};
enum layers{
    BASE,
    SYMB,
    MOVEMENT,
    NUMS,
};

#define HOME_A LT(NUMS, KC_A)
#define HOME_S LT(SYMB,KC_S)
#define HOME_Z LGUI_T(KC_Z)
#define HOME_SL LGUI_T(KC_SLASH)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)
#define HOME_Q MT(MOD_LSFT | MOD_LALT ,KC_Q)
#define HOME_J LSFT_T(KC_J)
#define HOME_K LCTL_T(KC_K)
#define HOME_L LT(SYMB, KC_L)
#define HOME_SPC LT(MOVEMENT, KC_SPC)
#define HOME_SC RALT_T(KC_COLON)
#define HOME_V LALT_T(KC_V)
// #define HOME_SHFT LSFT_T(KC_CAPS) // TODO: remove if the caps worked.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,    QK_REP, KC_BSPC,      KC_0,     QK_AREP,   KC_EQL, KC_MINUS, QK_BOOT,
        KC_TAB,  HOME_Q,   KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,      KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS, AC_TOGG,
        KC_CAPS, HOME_A,   HOME_S,   HOME_D,   HOME_F,     KC_G,     KC_H,     HOME_J,  HOME_K,   HOME_L,  HOME_SC,   KC_QUOTE,  LT(NUMS, KC_ENT), KC_PGDN,
        KC_LSFT, HOME_Z,   KC_X,     KC_C,   HOME_V,     KC_B,     KC_N,     KC_M,  KC_COMMA,   KC_DOT,    HOME_SL,   KC_RSFT,  KC_UP,   MO(1),
        _______, KC_LALT, KC_LGUI,                           HOME_SPC,                        KC_LGUI, KC_RCTL,          KC_LEFT,  KC_DOWN, KC_RGHT
    ),

    [MOVEMENT] = LAYOUT_65_ansi_blocker(
      _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
      _______, _______, _______, _______,  _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______,  _______, _______, KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT,  _______, _______, _______, _______,
      _______,          _______, _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
      _______, _______, _______,                    _______,                                      _______, _______, _______,  _______, _______
    ),
    [NUMS] = LAYOUT_65_ansi_blocker(
        _______, _______,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
        _______, _______,_______, _______, _______, _______, _______,    KC_6,    KC_5,    KC_4, KC_PLUS, KC_SLSH, _______, _______,  _______,
        _______, _______,_______,   LLOCK, _______, _______, _______,    KC_1,    KC_2,    KC_3, KC_MINS, KC_ASTR, _______, _______, 
        _______,         _______, _______, _______, _______, _______,  KC_DOT,    KC_7,    KC_8,    KC_9, KC_BSLS, _______, _______, _______, 
        _______, _______,_______,                   _______,                                     _______, _______,  _______,_______, _______
    ),


    [SYMB] = LAYOUT_65_ansi_blocker(
        _______, C(KC_Z), C(KC_V), C(KC_A), C(KC_C), C(KC_X), _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_LABK, KC_RABK, KC_BSLS, KC_GRV , KC_AMPR, _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______,
        _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_HASH, KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_PERC, _______, _______, _______, 
        _______,          KC_PIPE, KC_BSLS, KC_EXLM, _______, KC_TILD, KC_DLR , _______, KC_LCBR, KC_RCBR, _______, _______, _______, _______,
        _______, _______, _______,                    KC_0,                                       _______, _______,_______, _______, _______
     ),


};

///////////////////////////////////////////////////////////////////////////////
// Autocorrect (https://docs.qmk.fm/features/autocorrect)
///////////////////////////////////////////////////////////////////////////////
#ifdef AUTOCORRECT_ENABLE
bool apply_autocorrect(uint8_t backspaces, const char* str,
                       char* typo, char* correct) {
  for (uint8_t i = 0; i < backspaces; ++i) {
    tap_code(KC_BSPC);
  }
  send_string_with_delay_P(str, TAP_CODE_DELAY);
  return false;
}
#endif  // AUTOCORRECT_ENABLE

///////////////////////////////////////////////////////////////////////////////
// Custom shift keys (https://getreuer.info/posts/keyboards/custom-shift-keys)
///////////////////////////////////////////////////////////////////////////////
const custom_shift_key_t custom_shift_keys[] = {
  {HOME_SPC, KC_UNDS}, // Shift space is _
};

uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

///////////////////////////////////////////////////////////////////////////////
// Tap-hold configuration (https://docs.qmk.fm/tap_hold)
///////////////////////////////////////////////////////////////////////////////
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_SPC:
        case HOME_SL:
        case HOME_Z:
            return TAPPING_TERM - 30;
        case HOME_V:
            return TAPPING_TERM - 100;
        case HOME_D:
        case HOME_K:
        case HOME_L:
        case HOME_S:
            return TAPPING_TERM - 100;
        case HOME_F:
            return TAPPING_TERM - 105;
        case HOME_J:
            return TAPPING_TERM - 90;
        case HOME_A:
        case HOME_SC:
            return TAPPING_TERM - 70;
        case HOME_Q:
            return TAPPING_TERM - 65;
        default:
            return TAPPING_TERM;
    }
}

// Disable quick term for backspace, spacebar, Control and Shift
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_SPC:
        case HOME_D:
        case HOME_J:
        case HOME_K:
        case HOME_L:
        case HOME_F:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

// Retro tapping for spacebar
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_SPC:
        case HOME_A:
            return true;
        default:
            return false;
    }
}


///////////////////////////////////////////////////////////////////////////////
// Key Overrides (https://docs.qmk.fm/features/key_overrides)
///////////////////////////////////////////////////////////////////////////////
const key_override_t moveL_key_override = ko_make_basic(MOD_MASK_CTRL, KC_H, KC_UNDERSCORE);
const key_override_t moveH_key_override = ko_make_basic(MOD_MASK_CTRL, HOME_L,KC_DOLLAR);
const key_override_t moveR_key_override = ko_make_basic(MOD_MASK_CTRL, KC_R,LCTL(KC_D));

const key_override_t **key_overrides = (const key_override_t *[]){
    &moveL_key_override, &moveH_key_override, &moveR_key_override, 
    NULL // Null terminate the array of overrides!
};

///////////////////////////////////////////////////////////////////////////////
// Combos (https://docs.qmk.fm/features/combo)
///////////////////////////////////////////////////////////////////////////////
enum combos {
    K_ESC,
    MCOM_LEADER,
    COMDOT_CW,
};

const uint16_t PROGMEM K_combo[] = {HOME_K, KC_C, COMBO_END};
const uint16_t PROGMEM COMDOT_combo[] = {KC_DOT, KC_COMM, COMBO_END};
const uint16_t PROGMEM MCOM_combo[] = {KC_M, KC_COMM, COMBO_END};
// const uint16_t PROGMEM comdot_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
combo_t key_combos[] = {
  [K_ESC] = COMBO(K_combo,  KC_ESC),
  [COMDOT_CW] = COMBO(COMDOT_combo, CW_TOGG),
  [MCOM_LEADER] = COMBO(MCOM_combo, QK_LEAD),
    // [ComDot_DEL] = COMBO(comdot_combo, KC_DEL),
};

// Increase the time for Escape and Tab
int16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case K_ESC:
            return 100;
    }

    return COMBO_TERM;
}

bool get_combo_must_press_in_order(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        case K_ESC:
            return true;
        default:
            return false;
    }
}


// *** achordion ***
uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  return 230;
}

bool achordion_eager_mod(uint8_t mod) {
    return false;
}

uint16_t achordion_streak_chord_timeout(
    uint16_t tap_hold_keycode, uint16_t next_keycode) {
    switch (tap_hold_keycode) {
    case HOME_D:
    case HOME_K:
    case HOME_J:
    case HOME_F:
    case HOME_SPC:
    case HOME_A:
    case HOME_SC:
        return 0;
    }

  return 100;
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
    switch (tap_hold_keycode) {
    case HOME_D:
        switch (other_keycode) {
            case HOME_A:
            case HOME_S:
            case HOME_F:
            case HOME_SPC:
            case KC_W:
            case KC_C:
            case KC_E:
            case KC_B:
            case KC_R:
            case KC_T:
            case KC_G:
                return false;
        }
        break;
    case HOME_F:
        switch (other_keycode) {
            case HOME_A:
            case KC_A:
            case HOME_S:
            case HOME_D:
            case HOME_SPC:
            case KC_W:
            case KC_E:
            case KC_R:
            case KC_T:
                return false;
        }
        break;
    case HOME_S:
        switch (other_keycode) {
            case HOME_A:
            case HOME_D:
            case HOME_F:
            case HOME_Q:
            case KC_W:
            case KC_V:
            case KC_X:
            case KC_E:
            case KC_R:
            case KC_T:
            case KC_C:
                return false;
        }
        break;
case HOME_SPC:
        switch (other_keycode) {
            case HOME_J:
            case HOME_K:
            case HOME_L:
            case KC_U:
            case KC_H:
                return true;
                default: 
                return false;
        }
        break;
    case HOME_Z:
        switch (other_keycode) {
            case HOME_S:
            case HOME_D:
            case HOME_F:
            case HOME_SPC:
            case KC_W:
            case KC_E:
            case KC_R:
            case KC_T:
                return false;
        }
        break;
    case HOME_A:
        switch (other_keycode) {
            case HOME_S:
            case HOME_D:
            case HOME_F:
            case HOME_SPC:
            case KC_W:
            case KC_E:
            case KC_R:
            case KC_T:
            case KC_C:
            case KC_V:
                return false;
        }
        break;
    case HOME_V:
        switch (other_keycode) {
            case HOME_S:
            case HOME_A:
            case HOME_D:
            case HOME_F:
            case HOME_SPC:
            case KC_A:
            case KC_W:
            case KC_E:
            case KC_R:
            case KC_T:
            case KC_C:
                return false;
        }
        break;
    case HOME_K:
        switch (other_keycode) {
            case HOME_J:
            case HOME_L:
            case HOME_SC:
            case HOME_SPC:
            case KC_U:
            case KC_E:
            case KC_I:
            case KC_O:
            case KC_P:
            case KC_M:
            case KC_N:
                return false;
        }
        break;
    case HOME_J:
        switch (other_keycode) {
            case HOME_K:
            case HOME_L:
            case HOME_SC:
            case KC_U:
            case KC_I:
            case KC_O:
            case KC_P:
                return false;
        }
        break;
    case HOME_L:
        switch (other_keycode) {
            case HOME_J:
            case HOME_K:
            case HOME_SC:
            case KC_U:
            case KC_I:
            case KC_O:
            case KC_P:
            case KC_M:
            case KC_N:
                return false;
        }
        break;
    case HOME_SL:
        switch (other_keycode) {
            case HOME_J:
            case HOME_K:
            case HOME_L:
            case HOME_SPC:
            case KC_U:
            case KC_I:
            case KC_O:
            case KC_P:
            case KC_M:
            case KC_N:
                return false;
        }
        break;
    case HOME_SC:
        switch (other_keycode) {
            case HOME_J:
            case HOME_K:
            case HOME_L:
            case HOME_SPC:
            case KC_U:
            case KC_I:
            case KC_O:
            case KC_P:
            case KC_M:
            case KC_N:
                return false;
        }
        break;
    }

    return true;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_F:
            return false;
        default:
            return true;
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) { return false; }
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    if (!process_layer_lock(keycode, record, LLOCK)) { return false; }

if (record->event.pressed) {
switch (keycode) {
    case F_LOOP: SEND_STRING(/*k*/"or(int i = 0; i < .size; ++i){}"); break;
  }
}
    return true;

};


void matrix_scan_user(void) {
  achordion_task();
  layer_lock_task();
}