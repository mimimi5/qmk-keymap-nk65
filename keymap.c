/* Copyright 2019 Yiancar
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
#include QMK_KEYBOARD_H
#include "drivers/led/issi/is31fl3733.h"
#include "keymap_jp.h"

enum layers {
    _BASE = 0,
    _MAC,
    _VIM,
    _FN
};

enum custom_keycodes {
  DISABLE_FORCE_IME_OFF = SAFE_RANGE,
  VIM_UNDO,
  VIM_WORD_END,
  VIM_WORD_BACK
};

const key_override_t at_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_2, JP_AT); // @
const key_override_t circ_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_6, JP_CIRC); // ^
const key_override_t ampr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_7, JP_AMPR); // &
const key_override_t astr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_8, JP_ASTR); // *
const key_override_t lprn_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_9, JP_LPRN); // (
const key_override_t rprn_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_0, JP_RPRN); // )
const key_override_t unds_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, JP_UNDS); // _
const key_override_t plus_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, JP_PLUS); // +
const key_override_t lcbr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, JP_LCBR); // {
const key_override_t rcbr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_RBRC, JP_RCBR); // }
const key_override_t pipe_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSLS, JP_PIPE); // |
const key_override_t coln_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SCLN, JP_COLN); // :
const key_override_t dquo_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, JP_DQUO); // "
const key_override_t tild_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_GRV, JP_TILD); // ~
const key_override_t eql_key_override = ko_make_with_layers_and_negmods(0, KC_EQL, JP_EQL, ~0, (uint8_t) MOD_MASK_SHIFT); // =
const key_override_t lbrc_key_override = ko_make_with_layers_and_negmods(0, KC_LBRC, JP_LBRC, ~0, (uint8_t) MOD_MASK_SHIFT); // [
const key_override_t rbrc_key_override = ko_make_with_layers_and_negmods(0, KC_RBRC, JP_RBRC, ~0, (uint8_t) MOD_MASK_SHIFT); // ]
const key_override_t bsls_key_override = ko_make_with_layers_and_negmods(0, KC_BSLS, JP_BSLS, ~0, (uint8_t) MOD_MASK_SHIFT); // backslash
const key_override_t quot_key_override = ko_make_with_layers_and_negmods(0, KC_QUOT, JP_QUOT, ~0, (uint8_t) MOD_MASK_SHIFT); // '
const key_override_t grv_key_override = ko_make_with_layers_and_negmods(0, KC_GRV, JP_GRV, ~0, (uint8_t) MOD_MASK_SHIFT); // `

const key_override_t **key_overrides = (const key_override_t *[]){
    &at_key_override,
    &circ_key_override,
    &ampr_key_override,
    &astr_key_override,
    &lprn_key_override,
    &rprn_key_override,
    &unds_key_override,
    &plus_key_override,
    &lcbr_key_override,
    &rcbr_key_override,
    &pipe_key_override,
    &coln_key_override,
    &dquo_key_override,
    &tild_key_override,
    &eql_key_override,
    &lbrc_key_override,
    &rbrc_key_override,
    &bsls_key_override,
    &quot_key_override,
    &grv_key_override,
    NULL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_65_ansi( /* Base */
    KC_GESC,          KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,   KC_0,    KC_MINS,      KC_EQL,  KC_BSPC, TG(_MAC),\
    KC_TAB,           KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC,      KC_RBRC, KC_BSLS, KEY_OVERRIDE_TOGGLE, \
    LCTL_T(KC_LANG2), KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,               KC_ENT,  DISABLE_FORCE_IME_OFF, \
    LSFT_T(KC_LANG1), KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_GRV),        KC_UP,   MO(_FN), \
    MO(_VIM),         KC_LALT, KC_DEL,                 KC_SPC,                          KC_ENT, KC_RALT, KC_RGUI,      KC_LEFT, KC_DOWN, KC_RGHT),

[_MAC] = LAYOUT_65_ansi( /* Mac */
    KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
    KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
    LGUI_T(KC_LANG2), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,\
    KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,\
    KC_TRNS,          KC_TRNS, KC_TRNS,                   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_RCTL, KC_TRNS, KC_TRNS, KC_TRNS),

[_VIM] = LAYOUT_65_ansi( /* Vim */
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,  KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME,       KC_PGDN,  KC_PGUP, KC_END,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT,       KC_DOWN,  KC_UP,   KC_RGHT,      KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,\
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, VIM_WORD_BACK, KC_TRNS,  KC_TRNS, VIM_WORD_END, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,\
    KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                                   KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[_FN] = LAYOUT_65_ansi( /* FN */
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_TRNS,\
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,   KC_TRNS,\
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, S1_DEC,  S1_INC,  S2_DEC,  S2_INC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,\
    KC_TRNS, EF_DEC,  EF_INC,  H1_DEC,  H1_INC,  H2_DEC,  H2_INC,  BR_DEC,  BR_INC,  ES_DEC,  ES_INC,  KC_TRNS,          KC_TRNS, KC_TRNS,\
    KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

const uint16_t PROGMEM force_ime_off_keycodes[] = {
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL,
    KC_BSLS,
    KC_SCLN, KC_QUOT,
    KC_GRV
};
const size_t force_ime_off_keycodes_length = sizeof(force_ime_off_keycodes) / sizeof(force_ime_off_keycodes[0]);

const uint16_t PROGMEM force_ime_off_shift_keycodes[] = {
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,
    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH
};
const size_t force_ime_off_shift_keycodes_length = sizeof(force_ime_off_shift_keycodes) / sizeof(force_ime_off_shift_keycodes[0]);

bool enable_force_ime_off = true;

void matrix_init_user(void) {
  //user initialization
  key_override_off();
}

void matrix_scan_user(void) {
  //user matrix
}

void process_record_force_ime_off(uint16_t keycode, keyrecord_t *record) {
    bool force_ime_off = false;

    if (0 < (get_mods() & MOD_MASK_SHIFT)) {
        for (size_t i = 0; i < force_ime_off_shift_keycodes_length; ++i) {
            if (keycode == force_ime_off_shift_keycodes[i]) {
                force_ime_off = true;
                break;
            }
        }
    } else {
        for (size_t i = 0; i < force_ime_off_keycodes_length; ++i) {
            if (keycode == force_ime_off_keycodes[i]) {
                force_ime_off = true;
                break;
            }
        }
    }

    if (force_ime_off && record->event.pressed) {
        uint8_t current_real_mods = get_mods();
        clear_mods();
        tap_code(KC_LANG2);
        set_mods(current_real_mods);
    }
}

bool register_and_unregister_code16(uint16_t mac_keycode, uint16_t keycode, keyrecord_t *record) {
    if (layer_state_is(_MAC)) {
        if (record->event.pressed) {
            register_code16(mac_keycode);
        } else {
            unregister_code16(mac_keycode);
        }
    } else {
        if (record->event.pressed) {
            register_code16(keycode);
        } else {
            unregister_code16(keycode);
        }
    }

    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
    case DISABLE_FORCE_IME_OFF:
        enable_force_ime_off = !record->event.pressed;
        return true;
    case VIM_UNDO:
        return register_and_unregister_code16(G(KC_Z), C(KC_Z), record);
    case VIM_WORD_END:
        return register_and_unregister_code16(A(KC_RGHT), C(KC_RGHT), record);
    case VIM_WORD_BACK:
        return register_and_unregister_code16(A(KC_LEFT), C(KC_LEFT), record);
    case KEY_OVERRIDE_TOGGLE:
        if (!record->event.pressed) {
            IS31FL3733_set_color(7 + 64 - 1, 0, key_override_is_enabled() ? 255 : 0, 0);
        }

        return true;
    default:
        break;
    }

    if (enable_force_ime_off) {
        process_record_force_ime_off(keycode, record);
    }

    return true;
}

bool led_update_user(led_t led_state) {
    return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t R = 0;
    uint8_t G = 0;
    uint8_t B = 0;

    if (layer_state_cmp(state, _MAC)) {
        G = 255;
    }

    if (layer_state_cmp(state, _FN)) {
        R = 255;
        B = 255;
    }

    IS31FL3733_set_color(6 + 64 - 1, R, G, B);
    return state;
}
