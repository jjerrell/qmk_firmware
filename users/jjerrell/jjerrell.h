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
#include QMK_KEYBOARD_H

#include "version.h"
#include "leader.h"
#include "wrappers.h"

// clang-format off
enum userspace_layers {
    _WORKMAN,
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _SPECIAL,
    _GAME,
    LAYER_SAFE_RANGE
};
// clang-format on

enum userspace_keycodes {
    KC_ARROW = QK_USER, // ->
    KC_MAKE,            // Runs the keyboard's make command
    KC_VRSN,            // Print QMK Firmware and board info
    KC_CCCV,
    USER_SAFE_RANGE
    // RGB_IDL,            // Toggle RGB Idle animations
    // RGB_TGL             // Toggle RGB Layer Indication
};

#define KC_QWERTY DF(_QWERTY)
#define KC_WRKMAN DF(_WORKMAN)

#define KC_GAME TG(_GAME)
#define KC_LOWR MO(_LOWER)
#define KC_RISE MO(_RAISE)

// Keymap and other callbacks
void matrix_scan_keymap(void);
void matrix_scan_secret(void);

void leader_start_keymap(void);
void leader_start_secret(void);

bool leader_end_keymap(void);
bool leader_end_secret(void);

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
bool process_record_secrets(uint16_t keycode, keyrecord_t *record);

layer_state_t layer_state_set_keymap(layer_state_t state);

void housekeeping_task_keymap(void);
