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

/** Moonlander Empty
   ( \
        k00, k01, k02, k03, k04, k05, k06,   k60, k61, k62, k63, k64, k65, k66, \
        k10, k11, k12, k13, k14, k15, k16,   k70, k71, k72, k73, k74, k75, k76, \
        k20, k21, k22, k23, k24, k25, k26,   k80, k81, k82, k83, k84, k85, k86, \
        k30, k31, k32, k33, k34, k35,             k91, k92, k93, k94, k95, k96, \
        k40, k41, k42, k43, k44,      k53,   kb3,      ka2, ka3, ka4, ka5, ka6, \
                            k50, k51, k52,   kb4, kb5, kb6 \
    ) \
 */
#define KEYMAP_moonlander(...)    LAYOUT_moonlander(__VA_ARGS__)

// clang-format off
#define WRAPPER_moonlander_layers(                                          \
    k00, k01, k02, k03, k04, k05, k06,   k60, k61, k62, k63, k64, k65, k66, \
    k10, k11, k12, k13, k14, k15, k16,   k70, k71, k72, k73, k74, k75, k76, \
    k20, k21, k22, k23, k24, k25, k26,   k80, k81, k82, k83, k84, k85, k86, \
    k30, k31, k32, k33, k34, k35,             k91, k92, k93, k94, k95, k96, \
    k40, k41, k42, k43, k44,      k53,   kb3,      ka2, ka3, ka4, ka5, ka6, \
                        k50, k51, k52,   kb4, kb5, kb6                      \
) KEYMAP_moonlander(                                                        \
    k00, k01, k02, k03, k04,  k05,   k06,         k60,       k61,            k62, k63, k64, k65, k66, \
    k10, k11, k12, k13, k14,  k15,   k16,         k70,       k71,            k72, k73, k74, k75, k76, \
    k20, k21, k22, k23, k24,  k25,   k26,         k80,       k81,            k82, k83, k84, k85, k86, \
    k30, k31, k32, k33, k34,  k35,                           k91,            k92, k93, k94, k95, k96, \
    k40, k41, k42, k43, k44,         k53,         kb3,                       ka2, ka3, ka4, ka5, ka6, \
                LT(_LOWER, k50), HYPR_T(k51), k52,   kb4, MEH_T(kb5),LT(_RAISE, kb6)                  \
)

#define WRAPPER_moonlander_modifiers(                                       \
    k00, k01, k02, k03, k04, k05, k06,   k60, k61, k62, k63, k64, k65, k66, \
    k10, k11, k12, k13, k14, k15, k16,   k70, k71, k72, k73, k74, k75, k76, \
    k20, k21, k22, k23, k24, k25, k26,   k80, k81, k82, k83, k84, k85, k86, \
    k30, k31, k32, k33, k34, k35,             k91, k92, k93, k94, k95, k96, \
    k40, k41, k42, k43, k44,      k53,   kb3,      ka2, ka3, ka4, ka5, ka6, \
                        k50, k51, k52,   kb4, kb5, kb6                      \
) WRAPPER_moonlander_layers(                                                                                                                \
    k00,       k01,       k02,        k03,        k04,  k05, k06,           k60, k61,       k62,        k63,        k64,        k65,  k66, \
    k10,       k11,       k12,        k13,        k14,  k15, k16,           k70, k71,       k72,        k73,        k74,        k75,  k76, \
    k20,       k21, SFT_T(k22), GUI_T(k23), OPT_T(k24), k25, k26,           k80, k81, OPT_T(k82), GUI_T(k83), SFT_T(k84),       k85,  k86, \
    k30, CTL_T(k31),      k32,        k33,        k34,  k35,                     k91,       k92,        k93,        k94,  CTL_T(k95), k96, \
    k40,       k41,       k42,        k43,        k44,       k53,           kb3,            ka2,        ka3,        ka4,        ka5,  ka6, \
                                                  k50,  k51, k52,           kb4, kb5,       kb6                                            \
)
// clang-format on

#define KEYMAP_moonlander_layers(...)    WRAPPER_moonlander_layers(__VA_ARGS__)
#define KEYMAP_moonlander_modifiers(...) WRAPPER_moonlander_modifiers(__VA_ARGS__)