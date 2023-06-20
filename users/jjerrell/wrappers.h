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

#pragma once
#include "jjerrell.h"

// Workman
#define _________________WORKMN_L1_________________ KC_Q, KC_D, KC_R, KC_W, KC_B
#define _________________WORKMN_L2_________________ KC_A, KC_S, KC_H, KC_T, KC_G
#define _________________WORKMN_L3_________________ KC_Z, KC_X, KC_M, KC_C, KC_V

#define _________________WORKMN_R1_________________ KC_J, KC_F, KC_U, KC_P, KC_SCLN
#define _________________WORKMN_R2_________________ KC_Y, KC_N, KC_E, KC_O, KC_I
#define _________________WORKMN_R3_________________ KC_K, KC_L, KC_COMM, KC_DOT, KC_SLSH

// QWERTY
#define _________________QWERTY_L1_________________ KC_Q, KC_W, KC_E, KC_R, KC_T
#define _________________QWERTY_L2_________________ KC_A, KC_S, KC_D, KC_F, KC_G
#define _________________QWERTY_L3_________________ KC_Z, KC_X, KC_C, KC_V, KC_B

#define _________________QWERTY_R1_________________ KC_Y, KC_U, KC_I, KC_O, KC_P
#define _________________QWERTY_R2_________________ KC_H, KC_J, KC_K, KC_L, KC_SCLN
#define _________________QWERTY_R3_________________ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH

// Numbers
#define _________________NUMBERS_L_________________ KC_1, KC_2, KC_3, KC_4, KC_5
#define _________________NUMBERS_R_________________ KC_6, KC_7, KC_8, KC_9, KC_0

// Lower
#define _________________LOWER_L1__________________ KC_PGUP, KC_TAB, KC_UP, KC_ENT, KC_PGDN
#define _________________LOWER_L2__________________ KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END
#define _________________LOWER_L3__________________ KC_ESC, KC_BSPC, KC_CUT, KC_DEL, KC_CCCV

#define _________________LOWER_R1__________________ XXXXXXX, KC_7, KC_8, KC_9, KC_ASTR
#define _________________LOWER_R2__________________ XXXXXXX, KC_4, KC_5, KC_6, KC_SLSH
#define _________________LOWER_R3__________________ XXXXXXX, KC_1, KC_2, KC_3, KC_MINS
#define _____________LOWER_R4_____________ KC_0, KC_DOT, KC_COMM, KC_PLUS

// Raise
#define _________________RAISE_L1__________________ KC_PIPE, KC_MINS, KC_LBRC, KC_RBRC, KC_AMPR
#define _________________RAISE_L2__________________ KC_BSLS, KC_SLSH, KC_LPRN, KC_RPRN, KC_ASTR
#define _________________RAISE_L3__________________ KC_HASH, KC_DLR, KC_PERC, KC_TILD, KC_GRV

#define _________________RAISE_R1__________________ KC_EXLM, KC_LABK, KC_RABK, KC_UNDS, KC_SCLN
#define _________________RAISE_R2__________________ KC_QUES, KC_LCBR, KC_RCBR, KC_EQL, KC_COLN
#define _________________RAISE_R3__________________ KC_AT, KC_QUOT, KC_DQUO, KC_PLUS, KC_CIRC

// Adjust
#define _________________ADJUST_L1_________________ KC_MAKE, DB_TOGG, QK_BOOT, KC_QWERTY, KC_WRKMAN
#define _________________ADJUST_L2_________________ KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_MNXT
#define _________________ADJUST_L3_________________ KC_VRSN, AU_ON, AU_OFF, CG_SWAP, CG_NORM

#define _________________ADJUST_R1_________________ MU_NEXT, MU_ON, MU_OFF, MI_ON, MI_OFF
#define _________________ADJUST_R2_________________ AU_NEXT, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD
#define _________________ADJUST_R3_________________ AU_PREV, RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD

// Function
#define _______________________FROW_L_______________________ KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6
#define _______________________FROW_R_______________________ KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12
