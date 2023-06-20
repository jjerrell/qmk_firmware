/**
 * Copyright (C) 2021 Jerrell, Jacob <@jjerrell>
 * 
 * This file is part of qmk_firmware.
 * 
 * qmk_firmware is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * qmk_firmware is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with qmk_firmware.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "jjerrell.h"
#include "layouts.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WORKMAN] = KEYMAP_ergodox_modifiers(
        KC_ESC,  _________________NUMBERS_L_________________, KC_ARROW,    KC_MINS, _________________NUMBERS_R_________________, KC_EQL,
        KC_TAB,  _________________WORKMN_L1_________________, KC_LPRN,     KC_RPRN, _________________WORKMN_R1_________________, KC_BSLS,
        CW_TOGG, _________________WORKMN_L2_________________,                       _________________WORKMN_R2_________________, KC_QUOT,
        KC_LSFT, _________________WORKMN_L3_________________, KC_LBRC,     KC_RBRC, _________________WORKMN_R3_________________, KC_RSFT,
        QK_LEAD, XXXXXXX, XXXXXXX, KC_UP, KC_LEFT,                                          KC_RIGHT, KC_DOWN, XXXXXXX, XXXXXXX, KC_GAME,
                                                     XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,
                                                              XXXXXXX,     XXXXXXX, 
                                             KC_SPC, KC_BSPC, KC_RISE,     KC_LOWR, KC_TAB, KC_ENTER
    ),
    [_QWERTY] = KEYMAP_ergodox_modifiers(
        _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        _______, _________________QWERTY_L1_________________, _______,     _______, _________________QWERTY_R1_________________, _______,
        _______, _________________QWERTY_L2_________________,                       _________________QWERTY_R2_________________, _______,
        _______, _________________QWERTY_L3_________________, _______,     _______, _________________QWERTY_R3_________________, _______,
        _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,
                                                     _______, _______,     _______, _______,
                                                              _______,     _______, 
                                            _______, _______, _______,     _______, _______, _______
    ),
    [_LOWER] = KEYMAP_ergodox_modifiers(
        KC_HYPR, _______________________FROW_L_______________________,     _______________________FROW_R_______________________, KC_MEH,
        _______, _________________LOWER_L1__________________, _______,     _______, _________________LOWER_R1__________________, _______,
        _______, _________________LOWER_L2__________________,                       _________________LOWER_R2__________________, _______,
        _______, _________________LOWER_L3__________________, _______,     _______, _________________LOWER_R3__________________, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                             KC_0, KC_DOT, KC_COMM, KC_PLUS, _______,
                                                     _______, _______,     _______, _______,
                                                              _______,     _______, 
                                            _______, _______, _______,     _______, _______, _______
    ),
    [_RAISE] = KEYMAP_ergodox_modifiers(
        _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        _______, _________________RAISE_L1__________________, _______,     _______, _________________RAISE_R1__________________, _______,
        _______, _________________RAISE_L2__________________,                       _________________RAISE_R2__________________, _______,
        _______, _________________RAISE_L3__________________, _______,     _______, _________________RAISE_R3__________________, _______,
        _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,
                                                     _______, _______,     _______, _______,
                                                              _______,     _______, 
                                            _______, _______, _______,     _______, _______, _______
    ),
    /* Adjust (Lower + Raise) */
    [_ADJUST] = KEYMAP_ergodox_layers(
        _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        _______, _________________ADJUST_L1_________________, _______,     _______, _________________ADJUST_R1_________________, _______,
        _______, _________________ADJUST_L2_________________,                       _________________ADJUST_R2_________________, _______,
        _______, _________________ADJUST_L3_________________, _______,     _______, _________________ADJUST_R3_________________, _______,
        _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,
                                                     _______, _______,     _______, _______,
                                                              _______,     _______, 
                                            _______, _______, _______,     _______, _______, _______
    )
};
// clang-format on

/* Use LEDs for layer indication, potentially overwriting any mods held from the base layer */
layer_state_t layer_state_set_keymap(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);
    ergodox_led_all_set(LED_BRIGHTNESS_DEFAULT);
    switch (layer) {
        case _LOWER:
            ergodox_right_led_1_on();
            break;
        case _RAISE:
            ergodox_right_led_3_on();
            break;
        case _ADJUST:
            ergodox_led_all_on();
            break;
        case _GAME:
            ergodox_blink_all_leds();
            break;
        default:
            ergodox_led_all_off();
            break;
    }
    return state;
};

/* 
    Setup to light up a combination of the 3 leds to indicate which modifiers are active.
    Note that if a layer change occurs, this will not override any changes from the resulting layer.
*/
void matrix_scan_keymap(void) {
    uint8_t modifiers = get_mods();
    uint8_t layer_is_default = layer_state_is(_WORKMAN) || layer_state_is(_QWERTY);

    if (modifiers && layer_is_default) {
        if (modifiers & MOD_MASK_CSAG) {
            // All modifiers are set
            ergodox_led_all_on();
            // Double LED 2's brightness since both control and command/win modifiers are active
            ergodox_right_led_2_set(LED_BRIGHTNESS_DEFAULT * 2);
        } else {
            // Individual if/else blocks so the lights shut off if multiple mods are registered and one is released
            if (modifiers & MOD_MASK_SHIFT) {
                ergodox_right_led_1_on();
            } else {
                ergodox_right_led_1_off();
            }

            if (modifiers & MOD_MASK_ALT) {
                ergodox_right_led_3_on();
            } else {
                ergodox_right_led_3_off();
            }

            if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_GUI)) {
                // Control and CMD share a light. If both are held, the brightness is doubled
                ergodox_right_led_2_set(LED_BRIGHTNESS_DEFAULT * 2);
                ergodox_right_led_2_on();
            } else if ((modifiers & MOD_MASK_CTRL) || (modifiers & MOD_MASK_GUI)) {
                // Only one of Control and CMD are active, use default brightness
                ergodox_right_led_2_set(LED_BRIGHTNESS_DEFAULT);
                ergodox_right_led_2_on();
            } else {
                ergodox_right_led_2_off();
            }
        }
    } else if (layer_is_default) {
        // reset brightness and shutoff LEDs unless we're on an alternate layer
        ergodox_led_all_set(LED_BRIGHTNESS_DEFAULT);
        ergodox_led_all_off();
    }
};
