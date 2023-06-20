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

#define KEYMAP_ortho_4x12(...) LAYOUT_ortho_4x12(__VA_ARGS__)

// clang-format off
#define WRAPPER_planck_layers(                                          \
    K01, K02, K03, K04, K05,   K06,     K07,   K08, K09, K0A, K0B, K0C, \
    K11, K12, K13, K14, K15,   K16,     K17,   K18, K19, K1A, K1B, K1C, \
    K21, K22, K23, K24, K25,   K26,     K27,   K28, K29, K2A, K2B, K2C, \
    K31, K32, K33, K34, K35,       K36,        K38, K39, K3A, K3B, K3C  \
) KEYMAP_ortho_4x12(                                                                                  \
    K01, K02, K03, K04,            K05,        K06,      K07,                K08,  K09, K0A, K0B, K0C, \
    K11, K12, K13, K14,            K15,        K16,      K17,                K18,  K19, K1A, K1B, K1C, \
    K21, K22, K23, K24,            K25,        K26,      K27,                K28,  K29, K2A, K2B, K2C, \
    K31, K32, K33, K34, LT(_LOWER, K35), SFT_T(K36),     XXXXXXX, LT(_RAISE, K38), K39, K3A, K3B, K3C  \
)

#define WRAPPER_planck_modifiers(                                       \
    K01, K02, K03, K04, K05,   K06,     K07,   K08, K09, K0A, K0B, K0C, \
    K11, K12, K13, K14, K15,   K16,     K17,   K18, K19, K1A, K1B, K1C, \
    K21, K22, K23, K24, K25,   K26,     K27,   K28, K29, K2A, K2B, K2C, \
    K31, K32, K33, K34, K35,        K36,       K38, K39, K3A, K3B, K3C  \
) WRAPPER_planck_layers(                                                                                                       \
          K01,       K02,        K03,        K04,  K05,   K06,      K07,   K08,       K09,        K0A,        K0B,       K0C,  \
          K11, SFT_T(K12), GUI_T(K13), ALT_T(K14), K15,   K16,      K17,   K18, ALT_T(K19), GUI_T(K1A), SFT_T(K1B),      K1C,  \
    CTL_T(K21),      K22,        K23,        K24,  K25,   K26,      K27,   K28,       K29,        K2A,        K2B, CTL_T(K2C), \
          K31,       K32,        K33,        K34,  K35,        K36,        K38,       K39,        K3A,        K3B,       K3C   \
)
// clang-format on

#define KEYMAP_planck_layers(...)       WRAPPER_planck_layers(__VA_ARGS__)
#define KEYMAP_planck_modifiers(...)    WRAPPER_planck_modifiers(__VA_ARGS__)
