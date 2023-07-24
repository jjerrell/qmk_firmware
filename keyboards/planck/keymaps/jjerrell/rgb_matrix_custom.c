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
#include "rgb_matrix.h"

bool rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max) {
    uint8_t active_mods = get_mods();
    switch (get_highest_layer(layer_state)) {
        case 0:
            // Modifier state indication
            if (active_mods & MOD_MASK_CTRL) {
                rgb_matrix_set_color(24, RGB_BLUE);
                rgb_matrix_set_color(35, RGB_BLUE);
            } else {
                rgb_matrix_set_color(24, RGB_CORAL);
                rgb_matrix_set_color(35, RGB_CORAL);
            }

            if (active_mods & MOD_MASK_SHIFT || is_caps_word_on()) {
                if (is_caps_word_on()) {
                    rgb_matrix_set_color(39, RGB_RED);
                }
                rgb_matrix_set_color(13, RGB_RED);
                rgb_matrix_set_color(22, RGB_RED);
            } else {
                rgb_matrix_set_color(13, RGB_AZURE);
                rgb_matrix_set_color(22, RGB_AZURE);
            }

            if (active_mods & MOD_MASK_GUI) {
                rgb_matrix_set_color(14, RGB_MAGENTA);
                rgb_matrix_set_color(21, RGB_MAGENTA);
            } else {
                rgb_matrix_set_color(14, RGB_GOLD);
                rgb_matrix_set_color(21, RGB_GOLD);
            }

            if (active_mods & MOD_MASK_ALT) {
                rgb_matrix_set_color(15, RGB_CHARTREUSE);
                rgb_matrix_set_color(20, RGB_CHARTREUSE);
            } else {
                rgb_matrix_set_color(15, RGB_SPRINGGREEN);
                rgb_matrix_set_color(20, RGB_SPRINGGREEN);
            }

            // Thumb keys
            rgb_matrix_set_color(40, RGB_WHITE);
            rgb_matrix_set_color(42, RGB_WHITE);
            break;
        case _LOWER:
            for (uint16_t i = led_min; i <= led_max; i++) {
                switch (i) {
                    // arrow keys
                    case 2:
                    case 13 ... 15:
                        rgb_matrix_set_color(i, RGB_WHITE);
                        break;
                    // numpad
                    case 8 ... 10:
                    case 20 ... 22:
                    case 32 ... 34:
                    case 43:
                        if (active_mods & MOD_MASK_SHIFT) {
                            rgb_matrix_set_color(i, RGB_TEAL);
                        } else {
                            rgb_matrix_set_color(i, RGB_GREEN);
                        }
                        break;
                    default:
                        rgb_matrix_set_color(i, RGB_OFF);
                        break;
                }
            }
            // Thumb keys
            rgb_matrix_set_color(40, RGB_OFF);
            rgb_matrix_set_color(42, RGB_RED);
            break;
        case _RAISE:
            // light up the alpha key ranges
            for (uint16_t i = 0; i <= 46; i++) {
                switch (i) {
                    case 0 ... 4:
                    case 7 ... 16:
                    case 19 ... 28:
                    case 31 ... 35:
                        rgb_matrix_set_color(i, RGB_MAGENTA);
                        break;
                    default:
                        rgb_matrix_set_color(i, RGB_OFF);
                        break;
                }
            }
            // Thumb keys
            rgb_matrix_set_color(40, RGB_RED);
            rgb_matrix_set_color(42, RGB_OFF);
            break;
        case _ADJUST:
            rgb_matrix_set_color_all(RGB_RED);
            break;
    }
    return true;
}
