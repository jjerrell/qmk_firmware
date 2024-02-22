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

#ifdef KEYBOARD_planck_ez_glow
#    undef PRODUCT
#    define PRODUCT "Planck EZ Glow - Modified by <@jjerrell>"
#endif

#define LEADER_NO_TIMEOUT

// Get some keycodes and functionality for free See "../../ez/ez.c"
#define ORYX_CONFIGURATOR
#define PLANCK_EZ_USER_LEDS

#define CUSTOM_RGB_INDICATORS

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PLANCK_SOUND)
// #define STARTUP_SONG SONG(NO_SOUND)
#endif
