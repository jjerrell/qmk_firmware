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

#define KEYMAP_ergodox_ez(...) LAYOUT_ergodox_pretty(__VA_ARGS__)

// clang-format off
/** Common Wrapper
     .---------------------------------------------. .---------------------------------------------.
     |       |     |     |     |     |     |       | !       |     |     |     |     |     |       |
     !-------+-----+-----+-----+-----+-------------! !-------+-----+-----+-----+-----+-----+-------!
     |       |     |     |     |     |     |       | !       |     |     |     |     |     |       |
     !-------+-----+-----+-----x-----x-----!       ! !       !-----x-----x-----+-----+-----+-------!
     |       |     |     |     |     |     |-------! !-------!     |     |     |     |     |       |
     !-------+-----+-----+-----x-----x-----!       ! !       !-----x-----x-----+-----+-----+-------!
     |       |     |     |     |     |     |       | !       |     |     |     |     |     |       |
     '-------+-----+-----+-----+-----+-------------' '-------------+-----+-----+-----+-----+-------'
      |      |     |     |     |     |                             !     |     |     |     |      |
      '------------------------------'                             '------------------------------'
                                   .---------------. .---------------.
                                   |       |       | !       |       |
                           .-------+-------+-------! !-------+-------+-------.
                           !       !       |       | !       |       !       !
                           ! LOWER !       !-------! !-------!       ! RAISE !
                           |       |       |       | !       |       |       |
                           '-----------------------' '-----------------------'
*/
#define WRAPPER_ergodox_layers(                                              \
        L00,L01,L02,L03,L04,L05,L06,           R00,R01,R02,R03,R04,R05,R06,  \
        L10,L11,L12,L13,L14,L15,L16,           R10,R11,R12,R13,R14,R15,R16,  \
        L20,L21,L22,L23,L24,L25,                   R21,R22,R23,R24,R25,R26,  \
        L30,L31,L32,L33,L34,L35,L36,           R30,R31,R32,R33,R34,R35,R36,  \
        L40,L41,L42,L43,L44,                           R42,R43,R44,R45,R46,  \
                                L55,L56,   R50,R51,                          \
                                    L54,   R52,                              \
                            L53,L52,L51,   R55,R54,R53                       \
) KEYMAP_ergodox_ez(                                                        \
    L00, L01, L02, L03, L04, L05, L06,             R00, R01, R02, R03, R04, R05, R06,  \
    L10, L11, L12, L13, L14, L15, L16,             R10, R11, R12, R13, R14, R15, R16,  \
    L20, L21, L22, L23, L24, L25,                       R21, R22, R23, R24, R25, R26,  \
    L30, L31, L32, L33, L34, L35, L36,             R30, R31, R32, R33, R34, R35, R36,  \
    L40, L41, L42, L43, L44,                                 R42, R43, R44, R45, R46,  \
                                  L55, L56,   R50, R51,                                \
                                       L54,   R52,                                     \
                 LT(_LOWER, L53), L52, L51,   R55, R54, LT(_RAISE, R53)                )

/** Common Wrapper with Mod Tap/Hold overlay
     .---------------------------------------------. .---------------------------------------------.
     |       |     |     |     |     |     |       | !       |     |     |     |     |     |       |
     !-------+-----+-----+-----+-----+-------------! !-------+-----+-----+-----+-----+-----+-------!
     |       |     |     |     |     |     |       | !       |     |     |     |     |     |       |
     !-------+-----+-----+-----x-----x-----!       ! !       !-----x-----x-----+-----+-----+-------!
     |       |     | Sft | Cmd | Alt |     |-------! !-------!     | Alt | Cmd | Sft |     |       |
     !-------+-----+-----+-----x-----x-----!       ! !       !-----x-----x-----+-----+-----+-------!
     |       | Ctr |     |     |     |     |       | !       |     |     |     |     | Ctr |       |
     '-------+-----+-----+-----+-----+-------------' '-------------+-----+-----+-----+-----+-------'
      |      |     |     |     |     |                             !     |     |     |     | SPCL |
      '------------------------------'                             '------------------------------'
                                   .---------------. .---------------.
                                   |       |       | !       |       |
                           .-------+-------+-------! !-------+-------+-------.
                           !       !       |       | !       |       !       !
                           !  (i)  !       !-------! !-------!       !  (i)  !
                           | LOWER |       |       | !       |       | RAISE |
                           '-----------------------' '-----------------------'
*/

#define WRAPPER_ergodox_modifiers(                                         \
      L00,L01,L02,L03,L04,L05,L06,           R00,R01,R02,R03,R04,R05,R06,  \
      L10,L11,L12,L13,L14,L15,L16,           R10,R11,R12,R13,R14,R15,R16,  \
      L20,L21,L22,L23,L24,L25,                   R21,R22,R23,R24,R25,R26,  \
      L30,L31,L32,L33,L34,L35,L36,           R30,R31,R32,R33,R34,R35,R36,  \
      L40,L41,L42,L43,L44,                           R42,R43,R44,R45,R46,  \
                              L55,L56,   R50,R51,                          \
                                  L54,   R52,                              \
                          L53,L52,L51,   R55,R54,R53                       \
) WRAPPER_ergodox_layers(                                                                                                                                     \
        L00,       L01,        L02,        L03,        L04,  L05,       L06,                  R00,  R01,       R02,        R03,        R04,        R05,  R06, \
        L10,       L11,        L12,        L13,        L14,  L15,       L16,                  R10,  R11,       R12,        R13,        R14,        R15,  R16, \
        L20,       L21,  SFT_T(L22), GUI_T(L23), ALT_T(L24), L25,                                   R21, ALT_T(R22), GUI_T(R23), SFT_T(R24),       R25,  R26, \
        L30, CTL_T(L31),       L32,        L33,        L34,  L35, ALL_T(L36),           MEH_T(R30), R31,       R32,        R33,        R34,  CTL_T(R35), R36, \
        L40,       L41,        L42,        L43,        L44,                                                    R42,        R43,        R44,        R45,  R46, \
                                                                        L55, L56,        R50, R51,                                                            \
                                                                             L54,        R52,                                                                 \
                                                                   L53, L52, L51,        R55, R54,  R53                                                       )
// clang-format on

// These macros are used when defining layouts in keymap.c
#define KEYMAP_ergodox_layers(...) WRAPPER_ergodox_layers(__VA_ARGS__)
#define KEYMAP_ergodox_modifiers(...) WRAPPER_ergodox_modifiers(__VA_ARGS__)
