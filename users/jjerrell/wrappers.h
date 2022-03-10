// Copyright (C) 2021 Jerrell, Jacob <@jjerrell>
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

#pragma once
#include "jjerrell.h"

#define QWERTY  KC_QWERTY
#define WORKMN  KC_WORKMAN

// Non-sane shortcuts for software macros or keybindings
#define MACRO_0 HYPR(KC_F13)
#define MACRO_1 HYPR(KC_F14)
#define MACRO_2 HYPR(KC_F15)
#define MACRO_3 HYPR(KC_F16)
#define MACRO_4 HYPR(KC_F17)
#define MACRO_5 HYPR(KC_F18)
#define MACRO_6 HYPR(KC_F19)
#define MACRO_7 MEH(KC_F13)
#define MACRO_8 MEH(KC_F14)
#define MACRO_9 MEH(KC_F15)


// clang-format off
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

#if (defined(KEYBOARD_planck_ez))
/** Planck EZ Empty
  *,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

/**
 * Basic Planck EZ Wrapper to expand "block" defines before sending 
 * to LAYOUT_ortho_4x12
 */
#   define WRAPPER_ortho_4x12(...) LAYOUT_ortho_4x12(__VA_ARGS__)

#   define WRAPPER_planck_common( \
        K01, K02, K03, K04, K05,     K08, K09, K0A, K0B, K0C, \
        K11, K12, K13, K14, K15,     K18, K19, K1A, K1B, K1C, \
        K21, K22, K23, K24, K25,     K28, K29, K2A, K2B, K2C, \
        K31, K32, K33, K34,               K39, K3A, K3B, K3C  \
    ) WRAPPER_ortho_4x12( \
        K01,  K02,  K03,  K04,                  K05,         KC_LPRN,        KC_RPRN,                 K08,  K09,  K0A,  K0B,  K0C, \
        K11,  K12,  K13,  K14,                  K15,         KC_LBRC,        KC_RBRC,                 K18,  K19,  K1A,  K1B,  K1C, \
        K21,  K22,  K23,  K24,                  K25,         MACRO_1,        MACRO_2,                 K28,  K29,  K2A,  K2B,  K2C, \
        K31,  K32,  K33,  K34,  LT(_LOWER, KC_BSPC),   SFT_T(KC_SPC),        XXXXXXX,  LT(_RAISE, KC_ENT),  K39,  K3A,  K3B,  K3C)

#   define WRAPPER_planck_mods( \
        K01, K02, K03, K04, K05,     K08, K09, K0A, K0B, K0C, \
        K11, K12, K13, K14, K15,     K18, K19, K1A, K1B, K1C, \
        K21, K22, K23, K24, K25,     K28, K29, K2A, K2B, K2C, \
        K31, K32, K33, K34,               K39, K3A, K3B, K3C  \
    ) WRAPPER_planck_common( \
                 K01,        K02,        K03,        K04,  K05,       K08,  K09,        K0A,        K0B,       K0C,        \
                 K11, SFT_T(K12), GUI_T(K13), ALT_T(K14),  K15,       K18, ALT_T(K19), GUI_T(K1A), SFT_T(K1B), K1C,        \
          CTL_T(K21),        K22,        K23,        K24,  K25,       K28,  K29,        K2A,        K2B,       CTL_T(K2C), \
                 K31,        K32,        K33,        K34,                   K39,        K3A,        K3B,       K3C         )

// These macros are used when defining layouts in keymap.c
#   define LAYOUT_planck_common(...)  WRAPPER_planck_common(__VA_ARGS__)
#   define LAYOUT_planck_mods(...)    WRAPPER_planck_mods(__VA_ARGS__)

#elif defined(KEYBOARD_moonlander)
/** Moonlander Empty
 * ( \
        k00, k01, k02, k03, k04, k05, k06,   k60, k61, k62, k63, k64, k65, k66, \
        k10, k11, k12, k13, k14, k15, k16,   k70, k71, k72, k73, k74, k75, k76, \
        k20, k21, k22, k23, k24, k25, k26,   k80, k81, k82, k83, k84, k85, k86, \
        k30, k31, k32, k33, k34, k35,             k91, k92, k93, k94, k95, k96, \
        k40, k41, k42, k43, k44,      k53,   kb3,      ka2, ka3, ka4, ka5, ka6, \
                            k50, k51, k52,   kb4, kb5, kb6 \
    ) \
 */
#   define WRAPPER_moonlander(...)    LAYOUT_moonlander(__VA_ARGS__)
#   define WRAPPER_moonlander_common( \
             k11, k12, k13, k14, k15,             k71, k72, k73, k74, k75, \
             k21, k22, k23, k24, k25,             k81, k82, k83, k84, k85, \
             k31, k32, k33, k34, k35,             k91, k92, k93, k94, k95, \
             k41, k42, k43, k44,                       ka2, ka3, ka4, ka5  \
    ) WRAPPER_moonlander( \
         KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_ARROW,   KC_MINS,  KC_6,   KC_7,   KC_8,    KC_9,    KC_0,     KC_EQL,      \
        XXXXXXX,     k11,     k12,     k13,     k14,     k15,  KC_LPRN,   KC_RPRN,  k71,    k72,    k73,     k74,     k75,     KC_BSLS,      \
        XXXXXXX,     k21,     k22,     k23,     k24,     k25,  KC_LBRC,   KC_RBRC,  k81,    k82,    k83,     k84,     k85,     KC_QUOT,      \
        KC_LSFT,     k31,     k32,     k33,     k34,     k35,                       k91,    k92,    k93,     k94,     k95,     KC_RSFT,      \
   MO(_SPECIAL),     k41,     k42,     k43,     k44,           MACRO_1,   MACRO_2,          ka2,    ka3,     ka4,     ka5,     MO(_SPECIAL), \
                           LT(_LOWER, KC_SPC),HYPR_T(KC_BSPC), KC_LEAD,   KC_CCCV,MEH_T(KC_TAB),LT(_RAISE, KC_ENT)                            )

// Wraps modifiers on top of regular keys for convenient tap/hold composition
#   define WRAPPER_moonlander_mods( \
        k11, k12, k13, k14, k15,             k71, k72, k73, k74, k75, \
        k21, k22, k23, k24, k25,             k81, k82, k83, k84, k85, \
        k31, k32, k33, k34, k35,             k91, k92, k93, k94, k95, \
        k41, k42, k43, k44,                       ka2, ka3, ka4, ka5  \
    ) WRAPPER_moonlander_common( \
               k11,        k12,        k13,        k14, k15,             k71, k72,        k73,        k74,        k75, \
               k21, SFT_T(k22), GUI_T(k23), ALT_T(k24), k25,             k81, ALT_T(k82), GUI_T(k83), SFT_T(k84), k85, \
        CTL_T(k31),        k32,        k33,        k34, k35,             k91, k92,        k93,        k94,        CTL_T(k95), \
               k41,        k42,        k43,        k44,                       ka2,        ka3,        ka4,        ka5  \
    )

#   define WRAPPER_moonlander_gamepad( \
        k00, k01, k02, k03, k04, k05, k06, \
        k10, k11, k12, k13, k14, k15, k16, \
        k20, k21, k22, k23, k24, k25, k26, \
        k30, k31, k32, k33, k34, k35,      \
        k40, k41, k42, k43, k44,      k53, \
                            k50, k51, k52  \
    ) WRAPPER_moonlander( \
        k00, k01, k02, k03, k04, k05, k06,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        k10, k11, k12, k13, k14, k15, k16,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        k20, k21, k22, k23, k24, k25, k26,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        k30, k31, k32, k33, k34, k35,                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        k40, k41, k42, k43, k44,      k53,   XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                            k50, k51, k52,   XXXXXXX, XXXXXXX, TO(_WORKMAN) \
    )

#   define LAYOUT_moonlander_common(...)  WRAPPER_moonlander_common(__VA_ARGS__)
#   define LAYOUT_moonlander_mods(...)    WRAPPER_moonlander_mods(__VA_ARGS__)
#   define LAYOUT_moonlander_gamepad(...) WRAPPER_moonlander_gamepad(__VA_ARGS__)
#elif defined(KEYBOARD_ergodox_ez)
/** Ergodox EZ Empty
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
                           !       !       !-------! !-------!       !       !
                           |       |       |       | !       |       |       |
                           '-----------------------' '-----------------------'

    ---------- LEFT HAND -----------   ---------- RIGHT HAND ----------
    (                                                                    \
    L00,L01,L02,L03,L04,L05,L06,           R00,R01,R02,R03,R04,R05,R06,  \
    L10,L11,L12,L13,L14,L15,L16,           R10,R11,R12,R13,R14,R15,R16,  \
    L20,L21,L22,L23,L24,L25,                   R21,R22,R23,R24,R25,R26,  \
    L30,L31,L32,L33,L34,L35,L36,           R30,R31,R32,R33,R34,R35,R36,  \
    L40,L41,L42,L43,L44,                           R42,R43,R44,R45,R46,  \
                            L55,L56,   R50,R51,                          \
                                L54,   R52,                              \
                        L53,L52,L51,   R55,R54,R53                       \
    )
*/
#   define WRAPPER_ergodox_ez(...)     LAYOUT_ergodox_pretty(__VA_ARGS__)

/** Common Wrapper
     .---------------------------------------------. .---------------------------------------------.
     |   X   |  X  |  X  |  X  |  X  |  X  |   X   | !   X   |  X  |  X  |  X  |  X  |  X  |   X   |
     !-------+-----+-----+-----+-----+-------------! !-------+-----+-----+-----+-----+-----+-------!
     |   X   |     |     |     |     |     |   X   | !   X   |     |     |     |     |     |   X   |
     !-------+-----+-----+-----x-----x-----!       ! !       !-----x-----x-----+-----+-----+-------!
     |   X   |     |     |     |     |     |-------! !-------!     |     |     |     |     |   X   |
     !-------+-----+-----+-----x-----x-----!   X   ! !   X   !-----x-----x-----+-----+-----+-------!
     |   X   |     |     |     |     |     |       | !       |     |     |     |     |     |   X   |
     '-------+-----+-----+-----+-----+-------------' '-------------+-----+-----+-----+-----+-------'
      | SPCL |     |     |     |     |                             !     |     |     |     | SPCL |
      '------------------------------'                             '------------------------------'
                                   .---------------. .---------------.
                                   |   X   |   X   | !   X   |   X   |
                           .-------+-------+-------! !-------+-------+-------.
                           ! Space ! BSpace|   X   | !   X   |  Tab  ! Enter !
                           !   /   !   /   !-------! !-------!   /   !   /   !
                           | LOWER | Hyper |  LEAD | !  CCCV |  Meh  | RAISE |
                           '-----------------------' '-----------------------'
*/
#   define WRAPPER_ergodox_common( \
        L11,L12,L13,L14,L15,           R11,R12,R13,R14,R15,  \
        L21,L22,L23,L24,L25,           R21,R22,R23,R24,R25,  \
        L31,L32,L33,L34,L35,           R31,R32,R33,R34,R35,  \
        L41,L42,L43,L44,                   R42,R43,R44,R45   \
    ) WRAPPER_ergodox_ez( \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, \
        XXXXXXX,     L11,     L12,     L13,     L14,     L15, XXXXXXX,           XXXXXXX,     R11,     R12,     R13,     R14,     R15,      XXXXXXX, \
        XXXXXXX,     L21,     L22,     L23,     L24,     L25,                                 R21,     R22,     R23,     R24,     R25,      XXXXXXX, \
        KC_LSFT,     L31,     L32,     L33,     L34,     L35, XXXXXXX,           XXXXXXX,     R31,     R32,     R33,     R34,     R35,      KC_RSFT, \
   MO(_SPECIAL),     L41,     L42,     L43,     L44,                                                   R42,     R43,     R44,     R45, MO(_SPECIAL), \
                                                                                                                                                     \
                                                      XXXXXXX,XXXXXXX,           XXXXXXX,XXXXXXX,                                                    \
                                                              XXXXXXX,           XXXXXXX,                                                            \
                           LT(_LOWER, KC_SPC),HYPR_T(KC_BSPC),QK_LEAD,           KC_CCCV,SFT_T(KC_TAB),LT(_RAISE, KC_ENT)                            )

/** Common Wrapper with Mod Tap/Hold overlay
     .---------------------------------------------. .---------------------------------------------.
     |   X   |  X  |  X  |  X  |  X  |  X  |   X   | !   X   |  X  |  X  |  X  |  X  |  X  |   X   |
     !-------+-----+-----+-----+-----+-------------! !-------+-----+-----+-----+-----+-----+-------!
     |   X   |     |     |     |     |     |   X   | !   X   |     |     |     |     |     |   X   |
     !-------+-----+-----+-----x-----x-----!       ! !       !-----x-----x-----+-----+-----+-------!
     |   X   |     |Shift| Cmd | Alt |     |-------! !-------!     | Alt | Cmd |Shift|     |   X   |
     !-------+-----+-----+-----x-----x-----!   X   ! !   X   !-----x-----x-----+-----+-----+-------!
     |  Sft  | Ctl |     |     |     |     |       | !       |     |     |     |     | Ctl |  Sft  |
     '-------+-----+-----+-----+-----+-------------' '-------------+-----+-----+-----+-----+-------'
      | SPCL |     |     |     |     |                             !     |     |     |     | SPCL |
      '------------------------------'                             '------------------------------'
                                   .---------------. .---------------.
                                   |   X   |   X   | !   X   |   X   |
                           .-------+-------+-------! !-------+-------+-------.
                           ! Space ! BSpace|   X   | !   X   |  Tab  ! Enter !
                           !   /   !   /   !-------! !-------!   /   !   /   !
                           | LOWER | Hyper |  LEAD | !  CCCV |  Meh  | RAISE |
                           '-----------------------' '-----------------------'
*/
#   define WRAPPER_ergodox_mods( \
        L11,L12,L13,L14,L15,           R11,R12,R13,R14,R15,  \
        L21,L22,L23,L24,L25,           R21,R22,R23,R24,R25,  \
        L31,L32,L33,L34,L35,           R31,R32,R33,R34,R35,  \
        L41,L42,L43,L44,                   R42,R43,R44,R45   \
    ) WRAPPER_ergodox_common( \
               L11,        L12,        L13,        L14, L15,           R11,        R12,        R13,        R14,        R15,  \
               L21, SFT_T(L22), GUI_T(L23), ALT_T(L24), L25,           R21, ALT_T(R22), GUI_T(R23), SFT_T(R24),        R25,  \
        CTL_T(L31),        L32,        L33,        L34, L35,           R31,        R32,        R33,        R34, CTL_T(R35),  \
               L41,        L42,        L43,        L44,                            R42,        R43,        R44,        R45   )

// These macros are used when defining layouts in keymap.c
#   define LAYOUT_ergodox_common(...)  WRAPPER_ergodox_common(__VA_ARGS__)
#   define LAYOUT_ergodox_mods(...)    WRAPPER_ergodox_mods(__VA_ARGS__)
#endif // END LAYOUT Wrappers

/**
 * Alpha/Num key wrappers for portability
 */

// Workman
#define __________________WORKMN_L1__________________   KC_Q, KC_D, KC_R, KC_W, KC_B
#define __________________WORKMN_L2__________________   KC_A, KC_S, KC_H, KC_T, KC_G
#define __________________WORKMN_L3__________________   KC_Z, KC_X, KC_M, KC_C, KC_V

#define __________________WORKMN_R1__________________   KC_J, KC_F, KC_U,    KC_P,   KC_SCLN
#define __________________WORKMN_R2__________________   KC_Y, KC_N, KC_E,    KC_O,   KC_I
#define __________________WORKMN_R3__________________   KC_K, KC_L, KC_COMM, KC_DOT, KC_SLSH

// QWERTY
#define __________________QWERTY_L1__________________   KC_Q, KC_W, KC_E, KC_R, KC_T
#define __________________QWERTY_L2__________________   KC_A, KC_S, KC_D, KC_F, KC_G
#define __________________QWERTY_L3__________________   KC_Z, KC_X, KC_C, KC_V, KC_B

#define __________________QWERTY_R1__________________   KC_Y, KC_U, KC_I,    KC_O,   KC_P
#define __________________QWERTY_R2__________________   KC_H, KC_J, KC_K,    KC_L,   KC_SCLN
#define __________________QWERTY_R3__________________   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH

#define ________________QWERTY_R1_LHS________________   KC_P,    KC_O,   KC_I,     KC_U, KC_Y
#define ________________QWERTY_R2_LHS________________   KC_SCLN, KC_L,   KC_K,     KC_J, KC_H
#define ________________QWERTY_R3_LHS________________   KC_SLSH, KC_DOT, KC_COMM,  KC_M, KC_N

// Nums
#define ___________________NUMS_L____________________   KC_1, KC_2, KC_3, KC_4, KC_5,    KC_6
#define ___________________NUMS_R____________________   KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL

// Lower
#define __________________LOWER_L1___________________   KC_PGUP, KC_TAB,  KC_UP,   KC_ENT,  KC_PGDN
#define __________________LOWER_L2___________________   KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END
#define __________________LOWER_L3___________________   KC_ESC,  KC_BSPC, XXXXXXX, KC_DEL,  KC_CCCV

#define __________________LOWER_R1___________________   XXXXXXX, KC_7, KC_8,   KC_9,    KC_ASTR
#define __________________LOWER_R2___________________   XXXXXXX, KC_4, KC_5,   KC_6,    KC_SLSH
#define __________________LOWER_R3___________________   XXXXXXX, KC_1, KC_2,   KC_3,    KC_MINS
//  Relevant keys: ->                                            KC_0, KC_DOT, KC_COMM, KC_PLUS <- these keys break our lovely wrapper pattern
 
// Raise
#define __________________RAISE_L1___________________   KC_AMPR, KC_MINS, KC_LBRC, KC_RBRC, KC_PIPE
#define __________________RAISE_L2___________________   KC_BSLS, KC_SLSH, KC_LPRN, KC_RPRN, KC_ASTR
#define __________________RAISE_L3___________________   KC_HASH,  KC_DLR, KC_PERC, KC_TILD, KC_GRV

#define __________________RAISE_R1___________________   KC_EXLM, KC_LABK, KC_RABK, KC_UNDS, KC_SCLN
#define __________________RAISE_R2___________________   KC_QUES, KC_LCBR, KC_RCBR, KC_EQL,  KC_COLN
#define __________________RAISE_R3___________________   KC_AT,   KC_QUOT, KC_DQUO, KC_PLUS, KC_CIRC

// Adjust
#define __________________ADJUST_L1__________________   KC_MAKE, DB_TOGG, QK_BOOT, XXXXXXX, XXXXXXX
#define __________________ADJUST_L2__________________   KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT
#define __________________ADJUST_L3__________________   KC_VRSN, AU_ON,   AU_OFF,  CG_SWAP, CG_NORM

#define __________________ADJUST_R1__________________   MU_MOD, MU_ON,   MU_OFF,  MI_ON,   MI_OFF
#define __________________ADJUST_R2__________________   MUV_IN, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD
#define __________________ADJUST_R3__________________   MUV_DE, RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD
// clang-format on
