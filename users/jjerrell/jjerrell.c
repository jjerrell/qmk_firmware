// Copyright (C) 2023 Jerrell, Jacob <@jjerrell>
//
// This file is part of qmk_firmware.
//
// qmk_firmware is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// qmk_firmware is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with qmk_firmware.  If not, see <http://www.gnu.org/licenses/>.

#include "jjerrell.h"

uint16_t copy_paste_timer = 0;

// Matrix scan
__attribute__((weak)) void matrix_scan_keymap(void) {}
__attribute__((weak)) void matrix_scan_secret(void) {}

void matrix_scan_user(void) {
#ifndef NO_SECRETS
    matrix_scan_secret();
#endif
    matrix_scan_keymap();
}

// Leader start
__attribute__((weak)) void leader_start_keymap(void) {}
__attribute__((weak)) void leader_start_secret(void) {}

void leader_start_user(void) {
#ifndef NO_SECRETS
    leader_start_secret();
#endif
    leader_start_keymap();
}

// Leader end
__attribute__((weak)) bool leader_end_keymap(void) {
    return false;
}
__attribute__((weak)) bool leader_end_secret(void) {
    return false;
}

void leader_end_user(void) {
    // only run the process if the keymap or secret implementation did not find a match
    if (!(leader_end_keymap() || leader_end_secret())) {
        if (leader_sequence_one_key(KC_R)) {
            // Rebuild / Run
            SEND_STRING(SS_LGUI("r"));
        } else if (leader_sequence_two_keys(KC_B, KC_D)) {
            // Build info
            send_string_with_delay_P(PSTR(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION " Built at: " QMK_BUILDDATE), TAP_CODE_DELAY);
        }
    }
}

// Process record
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
    return true;
}

/* 
    Fixes an issue with shifted keycodes being wrapped with MOD_T functions on the _RAISE layers.
    See https://docs.qmk.fm/#/mod_tap?id=intercepting-mod-taps for more info
*/
bool process_record_mod_intercept(uint16_t keycode, keyrecord_t *record) {
    // this could be a switch by getting highest layer if this becomes problematic on other layers
    if (IS_LAYER_ON(_RAISE)) {
        switch (keycode) {
            case CTL_T(KC_HASH):
            case GUI_T(KC_LPRN):
            case ALT_T(KC_RPRN):
            case ALT_T(KC_LCBR):
            case GUI_T(KC_RCBR):
            case CTL_T(KC_CIRC):
                // Check tap.count to make sure we aren't processing a modifier
                if (record->tap.count && record->event.pressed) {
                    // Apply shift
                    register_code(KC_LSFT);
                    // Using tap_code16 we can send the uint16_t keycode parameter
                    tap_code16(keycode);
                    // Release shift
                    unregister_code(KC_LSFT);
                    // stop processing this keycode or the firmware will send the unshifted keycode also
                    return false;
                }
                // Modifier processing or not enough time elapsed to determine if it's a tap
                break;
        }
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (process_record_keymap(keycode, record) && process_record_secrets(keycode, record) && process_record_mod_intercept(keycode, record)) {
        switch (keycode) {
            case KC_ARROW:
                if (record->event.pressed) {
                    SEND_STRING("->");
                }
                return false;
            case KC_MAKE:
                if (record->event.pressed) {
                    send_string_with_delay_P(PSTR("qmk compile -kb " QMK_KEYBOARD " -km " QMK_KEYMAP), TAP_CODE_DELAY);
                    send_string_with_delay_P(PSTR(SS_TAP(X_ENTER)), TAP_CODE_DELAY);
                }
                return false;
            case KC_VRSN:
                if (record->event.pressed) {
                    send_string_with_delay_P(PSTR(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION " Built at: " QMK_BUILDDATE), TAP_CODE_DELAY);
                }
                return false;
            case KC_CCCV: // One key copy/paste
                if (record->event.pressed) {
                    copy_paste_timer = timer_read();
                } else if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {
                    // Hold, copy
                    SEND_STRING(SS_LGUI("c"));
                } else {
                    // Tap, paste
                    SEND_STRING(SS_LGUI("v"));
                }
                return false;
            default:
                return true;
        }
    } else {
        return false;
    }
}

// RGB states
__attribute__((weak)) bool rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max) {
    return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    return rgb_matrix_indicators_advanced_keymap(led_min, led_max);
}

// layer states
__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) {
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    return layer_state_set_keymap(state);
}

__attribute__((weak)) void housekeeping_task_keymap(void) {}

void housekeeping_task_user(void) {
    housekeeping_task_keymap();
}
