/* Copyright 2015-2017 Jack Humbert
 * Copyright 2021 Jacob Jerrell <@jjerrell>
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

#include "jjerrell.h"

#define LAYOUT_planck_plain(...)     WRAPPER_ortho_4x12(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WORKMAN] = LAYOUT_planck_mods(
        __________________WORKMN_L1__________________, __________________WORKMN_R1__________________,
        __________________WORKMN_L2__________________, __________________WORKMN_R2__________________,
        __________________WORKMN_L3__________________, __________________WORKMN_R3__________________,
        KC_LEAD, OSL(_SPECIAL), KC_CCCV, KC_HYPR,                KC_MEH, RGB_TOG, RGB_IDL, LED_LEVEL
    ),

    /* Lower - Nav/Select/Nums
    * ,-----------------------------------------------------------------------------------.
    * | PGUP | BSPC |  UP  | DEL  | PGDN |      |      |      |   7  |   8  |   9  |  *   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | HOME | LEFT | DOWN | RGHT | END  |      |      |      |   4  |   5  |   6  |  /   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | ESC  | TAB  |      | ENTR |      |      |      |      |   1  |   2  |   3  |  -   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      | held |    SPACE    | ENTR |   0  |   .  |   ,  |  +   |
    * `-----------------------------------------------------------------------------------'
    */
    [_LOWER] = LAYOUT_planck_mods(
        __________________LOWER_L1___________________, __________________LOWER_R1___________________,
        __________________LOWER_L2___________________, __________________LOWER_R2___________________,
        __________________LOWER_L3___________________, __________________LOWER_R3___________________,
        KC_LEAD, KC_LSFT, KC_CCCV, KC_HYPR,                           KC_0, KC_DOT, KC_COMM, XXXXXXX
    ),
    /* Raise - Symbols
    * ,-----------------------------------------------------------------------------------.
    * |   %  |   _  |   [  |   ]  |   ^  |      |      |   !  |   <  |   >  |   =  |  :   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |   \  |   /  |   {  |   }  |   *  |      |      |   ?  |   (  |   )  |   -  |  ;   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |   #  |   $  |   |  |   ~  |   `  |      |      |   @  |   "  |   '  |   +  |  &   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      | LEAD |      |      | BSPC |    SPACE    | held |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_RAISE] = LAYOUT_planck_common(
        __________________RAISE_L1___________________, __________________RAISE_R1___________________,
        __________________RAISE_L2___________________, __________________RAISE_R2___________________,
        __________________RAISE_L3___________________, __________________RAISE_R3___________________,
        KC_LEAD, KC_LSFT, KC_CCCV, KC_HYPR,                      KC_MEH, RGB_TOG, RGB_IDL, LED_LEVEL
    ),
    /* Adjust (Lower + Raise)
    * ,-----------------------------------------------------------------------------------.
    * | Make | Debug|Reset |      |      |      |      |MusMod|Mus On|MusOff|MidiOn|MidOff|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Mute | Vol- | Vol+ | Play | Skip |      |      |Voice-| HUE+ | HUE- | SAT+ | SAT- |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Vrsn | AudOn|AudOff|CGswap|CGnorm|      |      |Voice+|RGBTog|RGBMod|BRGHT+|BRGHT-|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      | held |             | held |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_ADJUST] = LAYOUT_planck_common(
         __________________ADJUST_L1__________________, __________________ADJUST_R1__________________,
         __________________ADJUST_L2__________________, __________________ADJUST_R2__________________,
         __________________ADJUST_L3__________________, __________________ADJUST_R3__________________,
        KC_LEAD, KC_LSFT, KC_CCCV, KC_HYPR,                      KC_MEH, RGB_TOG, RGB_IDL, LED_LEVEL
    ),
    [_SPECIAL] = LAYOUT_planck_common(
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, MACRO_7, MACRO_8, MACRO_9, XXXXXXX,
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, MACRO_4, MACRO_5, MACRO_6, XXXXXXX,
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, MACRO_1, MACRO_2, MACRO_3, XXXXXXX,
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     MACRO_0, XXXXXXX, XXXXXXX, XXXXXXX
    )
};
// clang-format on

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

#ifdef KEYBOARD_planck_ez
void planck_ez_teeth_set(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _LOWER:
            planck_ez_left_led_level(40);
            break;
        case _RAISE:
            planck_ez_right_led_level(40);
            break;
        case _ADJUST:
            planck_ez_left_led_level(40);
            planck_ez_right_led_level(40);
            break;
        default:
            planck_ez_left_led_off();
            planck_ez_right_led_off();
            break;
    }
}

layer_state_t layer_state_set_keymap(layer_state_t state) {
    planck_ez_left_led_off();
    planck_ez_right_led_off();
    planck_ez_teeth_set(state);
    return state;
}
#endif

bool encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
#         ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_DOWN);
#         else
            tap_code(KC_PGDN);
#         endif
        } else {
#         ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_UP);
#         else
            tap_code(KC_PGUP);
#         endif
        }
    }
    return true;
}

void dip_switch_update_keymap(uint8_t index, bool active) {
    switch (index) {
        case 0: {
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

#ifdef AUDIO_ENABLE
void matrix_scan_keymap(void) {
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
}
#endif

bool music_mask_keymap(uint16_t keycode) {
  switch (keycode) {
    case _RAISE:
    case _LOWER:
      return false;
    default:
      return true;
  }
}
