/* SPDX-License-Identifier: GPL-2.0-or-later */

#define DYNAMIC_KEYMAP_LAYER_COUNT 5
#define NUM_LAYERS 3 //use the correct one
#define LAYER_STATE_8BIT //this makes layering faster o
// if have debounce issues use asym_eager_defer_pk
#define FORCE_NKRO
#define USB_POLLING_INTERVAL_MS 1


// ****** My Configs ***********

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

// Quick Tab will deaktivated for Caps-Lock and Spacebar and Enter
#define QUICK_TAP_TERM 200
#define QUICK_TAP_TERM_PER_KEY

// Permissive Hold for index and middle finger in homerow
#define PERMISSIVE_HOLD_PER_KEY

// Retro tapping for left gui and left shift home row
#define RETRO_TAPPING
#define RETRO_TAPPING_PER_KEY

// This works with combination with retro tapping to suppress left GUI and left ALT
#define DUMMY_MOD_NEUTRALIZER_KEYCODE KC_F18
// Neutralize left alt and left GUI (Default value)
#define MODS_TO_NEUTRALIZE \
    { MOD_BIT(KC_LEFT_ALT), MOD_BIT(KC_LEFT_GUI) }

#define COMBO_TERM 50
#define COMBO_TERM_PER_COMBO

#define CAPS_WORD_INVERT_ON_SHIFT
#define ACHORDION_STREAK
#define LAYER_LOCK_IDLE_TIMEOUT 60000 
#define COMBO_SHOULD_TRIGGER
#define COMBO_MUST_PRESS_IN_ORDER_PER_COMBO