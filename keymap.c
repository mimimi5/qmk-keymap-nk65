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
    _JP,
    _JP_SHIFT,
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_65_ansi( /* Base */
    KC_GESC,          KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,   KC_0,    KC_MINS,      KC_EQL,  KC_BSPC, TG(_MAC),\
    KC_TAB,           KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC,      KC_RBRC, KC_BSLS, TG(_JP), \
    LCTL_T(KC_LANG2), KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,               KC_ENT,  DISABLE_FORCE_IME_OFF, \
    LSFT_T(KC_LANG1), KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_GRV),        KC_UP,   MO(_FN), \
    MO(_VIM),         KC_LALT, KC_DEL,                 KC_SPC,                          KC_ENT, KC_RALT, KC_RGUI,      KC_LEFT, KC_DOWN, KC_RGHT),

[_JP] = LAYOUT_65_ansi( /* 106/109 */
    KC_TRNS,                 JP_1,    JP_2,   JP_3,   JP_4,   JP_5,   JP_6,   JP_7,   JP_8,    JP_9,    JP_0,    JP_MINS, JP_EQL,  KC_TRNS, KC_TRNS,\
    KC_TRNS,                 JP_Q,    JP_W,   JP_E,   JP_R,   JP_T,   JP_Y,   JP_U,   JP_I,    JP_O,    JP_P,    JP_LBRC, JP_RBRC, JP_BSLS, KC_TRNS,\
    KC_TRNS,                 JP_A,    JP_S,   JP_D,   JP_F,   JP_G,   JP_H,   JP_J,   JP_K,    JP_L,    JP_SCLN, JP_QUOT,          KC_TRNS, KC_TRNS,\
    LT(_JP_SHIFT, KC_LANG1), JP_Z,    JP_X,   JP_C,   JP_V,   JP_B,   JP_N,   JP_M,   JP_COMM, JP_DOT,  JP_SLSH, JP_GRV,           KC_TRNS, KC_TRNS,\
    KC_TRNS,                 KC_TRNS, KC_TRNS,                KC_TRNS,                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[_JP_SHIFT] = LAYOUT_65_ansi( /* 106/109 Shift */
    KC_TRNS,   JP_EXLM,   JP_AT,      JP_HASH, JP_DLR,  JP_PERC,   JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN,   JP_RPRN,    JP_UNDS,    JP_PLUS,    S(KC_BSPC), KC_TRNS,\
    S(KC_TAB), S(JP_Q),   S(JP_W),    S(JP_E), S(JP_R), S(JP_T),   S(JP_Y), S(JP_U), S(JP_I), S(JP_O),   S(JP_P),    JP_LCBR,    JP_RCBR,    JP_PIPE,    KC_TRNS,\
    KC_TRNS,   S(JP_A),   S(JP_S),    S(JP_D), S(JP_F), S(JP_G),   S(JP_H), S(JP_J), S(JP_K), S(JP_L),   JP_COLN,    JP_DQUO,                S(KC_ENT),  KC_TRNS,\
    KC_TRNS,   S(JP_Z),   S(JP_X),    S(JP_C), S(JP_V), S(JP_B),   S(JP_N), S(JP_M), JP_LABK, JP_RABK,   JP_QUES,    JP_TILD,                S(KC_UP),   KC_TRNS,\
    KC_TRNS,   S(KC_LALT), S(KC_DEL),                   S(KC_SPC),                            S(KC_ENT), S(KC_RGUI), S(KC_RGUI), S(KC_LEFT), S(KC_DOWN), S(KC_RGHT)),

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

const uint16_t PROGMEM force_ime_off_jp_keycodes[] = {
    JP_1, JP_2, JP_3, JP_4, JP_5, JP_6, JP_7, JP_8, JP_9, JP_0, JP_EQL,
    JP_BSLS,
    JP_SCLN, JP_QUOT,
    JP_GRV
};
const size_t force_ime_off_jp_keycodes_length = sizeof(force_ime_off_jp_keycodes) / sizeof(force_ime_off_jp_keycodes[0]);

const uint16_t PROGMEM force_ime_off_shift_jp_keycodes[] = {
    JP_EXLM, JP_AT, JP_HASH, JP_DLR,JP_PERC, JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, JP_UNDS, JP_PLUS,
    S(JP_Q), S(JP_W), S(JP_E), S(JP_R), S(JP_T), S(JP_Y), S(JP_U), S(JP_I), S(JP_O), S(JP_P), JP_LCBR, JP_RCBR, JP_PIPE,
    S(JP_A), S(JP_S), S(JP_D), S(JP_F), S(JP_G), S(JP_H), S(JP_J), S(JP_K), S(JP_L), JP_COLN, JP_DQUO,
    S(JP_Z), S(JP_X), S(JP_C), S(JP_V), S(JP_B), S(JP_N), S(JP_M), JP_LABK, JP_RABK, JP_QUES, JP_TILD
};
const size_t force_ime_off_shift_jp_keycodes_length = sizeof(force_ime_off_shift_jp_keycodes) / sizeof(force_ime_off_shift_jp_keycodes[0]);

bool enable_force_ime_off = true;

void matrix_init_user(void) {
  //user initialization
}

void matrix_scan_user(void) {
  //user matrix
}

void process_record_force_ime_off(uint16_t keycode, keyrecord_t *record) {
    bool force_ime_off = false;

    if (layer_state_is(_JP_SHIFT)) {
        for (size_t i = 0; i < force_ime_off_shift_jp_keycodes_length; ++i) {
            if (keycode == force_ime_off_shift_jp_keycodes[i]) {
                force_ime_off = true;
                break;
            }
        }
    } else if (layer_state_is(_JP)) {
        for (size_t i = 0; i < force_ime_off_jp_keycodes_length; ++i) {
            if (keycode == force_ime_off_jp_keycodes[i]) {
                force_ime_off = true;
                break;
            }
        }
    } else if (0 < (get_mods() & MOD_MASK_SHIFT)) {
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
    if (keycode == DISABLE_FORCE_IME_OFF) {
        enable_force_ime_off = !record->event.pressed;
        return true;
    }

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
    if (layer_state_cmp(state, _FN)) {
        IS31FL3733_set_color(7 + 64 - 1, 0, 255, 0);
    } else {
        IS31FL3733_set_color(7 + 64 - 1, 0, 0, 0);
    }

    uint8_t R = 0;
    uint8_t G = 0;
    uint8_t B = 0;

    if (layer_state_cmp(state, _JP)) {
        R = 255;
        B = 255;
    }

    if (layer_state_cmp(state, _MAC)) {
        G = 255;
    }

    IS31FL3733_set_color(6 + 64 - 1, R, G, B);
    return state;
}
