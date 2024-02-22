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

#define ML_LED_L1(status) ML_LED_1((bool)status)
#define ML_LED_L2(status) ML_LED_2((bool)status)
#define ML_LED_L3(status) ML_LED_3((bool)status)

#define ML_LED_R1(status) ML_LED_4((bool)status)
#define ML_LED_R2(status) ML_LED_5((bool)status)
#define ML_LED_R3(status) ML_LED_6((bool)status)

void moonlander_led_all(bool status);
