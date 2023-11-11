// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"

#define _SYM 3
#define _NAV 2
#define _ALTLAY 1
#define _COLEMAK_DH 0

#define _____ KC_TRNS
#define XXXXX KC_NO

/* 
How to build and flash on Ubuntu
--------------------------------
QMK master has a lot of setup changes (Python, potentially Docker): 
  - Follow https://docs.qmk.fm/#/newbs_getting_started?id=set-up-qmk if necessary.

Linux: Make sure ModemManager is not running:
- systemctl status ModemManager.service
- systemctl stop ModemManager.service

Uninstall permanently if you wish:
- sudo systemctl disable ModemManager.service

Install:
- sudo apt-get install avrdude avr-libc binutils-avr gcc-avr

Navigate to qmk folder:
 - qmk compile -kb azelus3 -km default
 (old: make planck/rev5:azelus:dfu)

Flash the arduino micro:
 - double tap the reset button, give it a second to register with the system, and within 5 seconds execute:
 - avrdude -D -patmega32u4 -cavr109 -P/dev/ttyACM0 -b57600 -Uflash:w:/home/.../github/qmk_firmware/planck_rev5_azelus.hex:i 
 - avrdude -D -patmega32u4 -cavr109 -P/dev/ttyACM0 -b57600 -Uflash:w:/home/.../github/qmk_firmware/azelus3_default.hex:i 
 (-D avoids clearing the memory before trying to read the new firmware)
 (absolute path mandatory!) 


*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAK_DH] = { 
  {KC_ESC,  XXXXX, XXXXX,   XXXXX,   KC_F5,   XXXXX,      XXXXX,   KC_KP_SLASH,  XXXXX,   XXXXX,       XXXXX,   DE_ODIA},
  {KC_TAB,  KC_Q,  KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,         KC_U,    DE_Z,        DE_UDIA, DE_ADIA},
  {KC_LSFT, KC_A,  KC_R,    KC_S,    KC_T,    KC_G,       KC_M,    KC_N,         KC_E,    KC_I,        KC_O,    KC_BSPC},
  {KC_LCTL, DE_Y,  KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H,         KC_COMM, KC_DOT,      DE_MINS, KC_RSFT},
  {XXXXX,   XXXXX, KC_LGUI, KC_LALT, KC_SPC,  MO(_SYM),   KC_ENT,  MO(_NAV),     XXXXX,   TG(_ALTLAY), XXXXX,   XXXXX}
},
[_ALTLAY] = { 
  {KC_ESC,  XXXXX, XXXXX,   XXXXX,   KC_F5,   XXXXX,      XXXXX,   KC_KP_SLASH,  XXXXX,   XXXXX,       XXXXX,   DE_ODIA},
  {KC_TAB,  KC_Q,  KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,         KC_U,    DE_Z,        DE_UDIA, DE_ADIA},
  {KC_LCTL, KC_A,  KC_R,    KC_S,    KC_T,    KC_G,       KC_M,    KC_N,         KC_E,    KC_I,        KC_O,    KC_BSPC},
  {XXXXX,   DE_Y,  KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H,         KC_COMM, KC_DOT,      DE_MINS, KC_DEL},
  {XXXXX,   XXXXX, KC_LGUI, KC_LALT, KC_LSFT, MO(_SYM),   KC_ENT,  MO(_NAV),     KC_SPC,  TG(_ALTLAY), XXXXX,   XXXXX}
},
[_NAV] = { 
  {_____,   XXXXX,  XXXXX,   XXXXX,    _____,  XXXXX,      XXXXX,   _____,   XXXXX,   XXXXX,    XXXXX, _____},
  {_____,   DE_DEG, KC_F7,   KC_F8,    KC_F9,  KC_F10,     KC_PGUP, KC_HOME, KC_UP,   KC_END,   _____, KC_AUDIO_VOL_UP},
  {_____,   _____,  KC_F4,   KC_F5,    KC_F6,  KC_F11,     KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, _____, KC_AUDIO_VOL_DOWN},
  {_____,   _____,  KC_F1,   KC_F2,    KC_F3,  KC_F12,     _____,   KC_INS,  XXXXX,   KC_DEL,   _____, _____},
  {XXXXX,   XXXXX,  _____,   KC_LALT,  _____,  _____,      KC_ENT,  _____,   _____,   _____,    XXXXX, XXXXX}
},
[_SYM] = { 
  {DE_PERC, XXXXX,   XXXXX,   XXXXX,   DE_PIPE, XXXXX,     XXXXX,   DE_BSLS, XXXXX,  XXXXX, XXXXX,    DE_ACUT},
  {DE_AMPR, DE_AT,   DE_DQUO, DE_EURO, DE_LCBR, DE_RCBR,   DE_TILD, KC_7,    KC_8,   KC_9,  DE_MINS,  DE_QUOT},
  {DE_SECT, DE_EXLM, DE_SS,   DE_HASH, DE_LPRN, DE_RPRN,   DE_ASTR, KC_4,    KC_5,   KC_6,  DE_PLUS,  _____},
  {DE_DLR,  DE_QUES, DE_LABK, DE_RABK, DE_LBRC, DE_RBRC,   KC_DOT,  KC_1,    KC_2,   KC_3,  DE_EQL,   DE_GRV},
  {XXXXX,   XXXXX,   DE_CIRC, _____,   _____,   _____,     KC_ENT,  _____,   _____,  KC_0,  XXXXX,    XXXXX}
}
};