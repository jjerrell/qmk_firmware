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

#include "rgb_custom.h"

__attribute__((weak)) bool rgb_indicators_process_keymap(uint8_t led_min, uint8_t led_max) {
    rgb_matrix_set_color_all(RGB_OFF);
    return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t active_mods   = get_mods();
    uint8_t highest_layer = get_highest_layer(layer_state);
    return rgb_indicators_process_keymap(led_min, led_max) && rgb_indicators_process_layer_user(highest_layer, active_mods);
}

__attribute__((weak)) bool rgb_indicators_process_modifiers_keymap(uint8_t active_mods, uint8_t layer) {
    return true;
}

bool rgb_indicators_process_modifiers_user(uint8_t active_mods, uint8_t layer) {
    if (rgb_indicators_process_modifiers_keymap(active_mods, layer)) {
        for (uint8_t i = 0; i < ARRAY_SIZE(RGB_LIST_MODIFIERS); i++) {
            if (i == INDEX_CWORD) {
                continue;
            }
            rgb_matrix_set_color(RGB_LIST_MODIFIERS[i], RGB_GOLD);
        }

        // process modifiers
        if (active_mods & MOD_MASK_CTRL) {
            rgb_matrix_set_color(RGB_LIST_MODIFIERS[INDEX_LCTL], RGB_RED);
            rgb_matrix_set_color(RGB_LIST_MODIFIERS[INDEX_RCTL], RGB_RED);
        }

        if (active_mods & MOD_MASK_SHIFT || is_caps_word_on()) {
            if (is_caps_word_on()) {
                rgb_matrix_set_color(RGB_LIST_MODIFIERS[INDEX_CWORD], RGB_RED);
            }
            rgb_matrix_set_color(RGB_LIST_MODIFIERS[INDEX_LSFT], RGB_RED);
            rgb_matrix_set_color(RGB_LIST_MODIFIERS[INDEX_RSFT], RGB_RED);
        }

        if (active_mods & MOD_MASK_ALT) {
            rgb_matrix_set_color(RGB_LIST_MODIFIERS[INDEX_LOPT], RGB_RED);
            rgb_matrix_set_color(RGB_LIST_MODIFIERS[INDEX_ROPT], RGB_RED);
        }

        if (active_mods & MOD_MASK_GUI) {
            rgb_matrix_set_color(RGB_LIST_MODIFIERS[INDEX_LCMD], RGB_RED);
            rgb_matrix_set_color(RGB_LIST_MODIFIERS[INDEX_RCMD], RGB_RED);
        }
    }
    return true;
}

bool rgb_indicators_process_layer_user(uint8_t layer, uint8_t active_mods) {
    switch (layer) {
        case 0:
            return rgb_indicators_process_modifiers_user(active_mods, layer);
            break;
        case _LOWER:
            // Arrow keys
            for (uint8_t i = 0; i < ARRAY_SIZE(RGB_LIST_ARROWS); i++) {
                if (active_mods & MOD_MASK_SHIFT) {
                    rgb_matrix_set_color(RGB_LIST_ARROWS[i], RGB_RED);
                } else {
                    rgb_matrix_set_color(RGB_LIST_ARROWS[i], RGB_WHITE);
                }
            }
            // Numpad
            for (uint8_t i = 0; i < ARRAY_SIZE(RGB_LIST_NUMPAD); i++) {
                if (active_mods & MOD_MASK_SHIFT) {
                    rgb_matrix_set_color(RGB_LIST_NUMPAD[i], RGB_TEAL);
                } else {
                    rgb_matrix_set_color(RGB_LIST_NUMPAD[i], RGB_GREEN);
                }
            }
            break;
        default:
            break;
    }
    return true;
}
