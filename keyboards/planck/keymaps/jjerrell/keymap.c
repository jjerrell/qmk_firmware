/* Copyright 2023 Jacob Jerrell <@jjerrell>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "jjerrell.h"
#include "layouts.h"

#define LYR_TGL TOGGLE_LAYER_COLOR

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default - Workman layout
    * ,-----------------------------------------------------------------------------------.
    * |   Q  |   D  |  R   |   W  |   B  |  ->  |  -   |   J  |   F  |   U  |   P  |  ;   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |   A  |   S  |  H   |   T  |   G  |   (  |  )   |   Y  |   N  |   E  |   O  |  I   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |   Z  |   X  |  M   |   C  |   V  |   [  |  ]   |   K  |   L  |   ,  |   .  |  /   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | LEAD | HYPR |      | SCAP | BSPC |    Space    | ENTR |  RGB |LYR_TG|  MEH |LED_CG|
    * `-----------------------------------------------------------------------------------'
    */
    [_WORKMAN] = KEYMAP_planck_modifiers(
        _________________WORKMN_L1_________________, KC_ARROW, KC_MINS, _________________WORKMN_R1_________________,
        _________________WORKMN_L2_________________, KC_LPRN,  KC_RPRN, _________________WORKMN_R2_________________,
        _________________WORKMN_L3_________________, KC_LBRC,  KC_RBRC, _________________WORKMN_R3_________________,
        QK_LEAD, KC_HYPR, XXXXXXX, CW_TOGG, KC_BSPC,      KC_SPC,       KC_ENT, RGB_TOG, LYR_TGL, KC_MEH, LED_LEVEL
    ),
    /* Lower - Nav/Select/Nums
    * ,-----------------------------------------------------------------------------------.
    * | PGUP | BSPC |  UP  | DEL  | PGDN |      |      |      |   7  |   8  |   9  |  *   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | HOME | LEFT | DOWN | RGHT | END  |      |      |      |   4  |   5  |   6  |  /   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | ESC  | TAB  | CUT  | ENTR |CpyPst|      |      |      |   1  |   2  |   3  |  -   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      | held |    SPACE    | ENTR |   0  |   .  |   ,  |  +   |
    * `-----------------------------------------------------------------------------------'
    */
    [_LOWER] = KEYMAP_planck_modifiers(
        _________________LOWER_L1__________________, _______, _______, _________________LOWER_R1__________________,
        _________________LOWER_L2__________________, _______, _______, _________________LOWER_R2__________________,
        _________________LOWER_L3__________________, _______, _______, _________________LOWER_R3__________________,
        _______, _______,  _______,  _______, KC_BSPC,     KC_SPC,     KC_ENT,  _____________LOWER_R4_____________
    ),
    /* Raise - Symbols
    * ,-----------------------------------------------------------------------------------.
    * |   |  |   -  |   [  |   ]  |   &  |      |      |   !  |   <  |   >  |   _  |  :   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |   \  |   /  |   (  |   )  |   *  |      |      |   ?  |   {  |   }  |   =  |  ;   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |   #  |   $  |   %  |   ~  |   `  |      |      |   @  |   '  |   "  |   +  |  ^   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      | BSPC |    SPACE    | held |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_RAISE] = KEYMAP_planck_modifiers(
        _________________RAISE_L1__________________, _______, _______, _________________RAISE_R1__________________,
        _________________RAISE_L2__________________, _______, _______, _________________RAISE_R2__________________,
        _________________RAISE_L3__________________, _______, _______, _________________RAISE_R3__________________,
        _______, _______, _______, _______, KC_BSPC,       KC_SPC,     KC_ENT,  _______, _______, _______, _______
    ),
    /* Adjust (Lower + Raise)
    * ,-----------------------------------------------------------------------------------.
    * | Make | Debug| Reset|QWERTY|WRKMAN|      |      |MusNxt|Mus On|MusOff|MidiOn|MidOff|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Mute | Vol- | Vol+ | Play | Skip |      |      |AudNxt| HUE+ | HUE- | SAT+ | SAT- |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Vrsn | AudOn|AudOff|CGswap|CGnorm|      |      |AudPrv|RGBTog|RGBMod|BRGHT+|BRGHT-|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      | held |             | held |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_ADJUST] = KEYMAP_planck_layers(
        _________________ADJUST_L1_________________, _______, _______, _________________ADJUST_R1_________________,
        _________________ADJUST_L2_________________, _______, _______, _________________ADJUST_R2_________________,
        _________________ADJUST_L3_________________, _______, _______, _________________ADJUST_R3_________________,
        _______, _______, _______, _______, _______,     XXXXXXX,      _______, _______, _______, _______, _______
    )
};
// clang-format on

layer_state_t layer_state_set_keymap(layer_state_t state) {
    planck_ez_right_led_level((uint8_t)keyboard_config.led_level * 255 / 8);
    planck_ez_left_led_level((uint8_t)keyboard_config.led_level * 255 / 8);
    planck_ez_left_led_off();
    planck_ez_right_led_off();
    switch (get_highest_layer(state)) {
        case _LOWER:
            planck_ez_left_led_on();
            break;
        case _RAISE:
            planck_ez_right_led_on();
            break;
        case _ADJUST:
            planck_ez_right_led_on();
            planck_ez_left_led_on();
            break;
        default:
            break;
    }
    return state;
}
