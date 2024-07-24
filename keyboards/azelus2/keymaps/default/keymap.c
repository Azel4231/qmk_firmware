// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "keymap_greek.h"


#define _SYM 3
#define _NAV 2
#define _GREEK 1
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
 - qmk compile -kb azelus2 -km default

Flash the arduino micro:
 - double tap the reset button, give it a second to register with the system, and within 5 seconds execute:
 - avrdude -D -patmega32u4 -cavr109 -P/dev/ttyACM0 -b57600 -Uflash:w:/home/.../github/qmk_firmware/azelus2_default.hex:i 
 (-D avoids clearing the memory before trying to read the new firmware)
 (absolute path mandatory!) 


*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAK_DH] = { 
  {KC_TAB,  KC_Q,  KC_W,    KC_J,    KC_R,        KC_T,          KC_Y,    KC_U,         KC_I,    KC_O,    KC_P,        DE_ADIA},
  {KC_LCTL, KC_A,  KC_S,    KC_D,    KC_F,        KC_G,          KC_H,    KC_N,         KC_E,    KC_L,    KC_SCLN,     KC_BSPC},
  {KC_LSFT, KC_Z,  KC_X,    KC_C,    KC_V,        KC_B,          KC_K,    KC_M,         KC_COMM, KC_DOT,  DE_SS,       DE_UDIA},
  {KC_ESC,  KC_F5, KC_LGUI, KC_LALT, MO(_GREEK),  MO(_SYM),      KC_ENT,  MO(_NAV),     KC_SPC,  KC_RALT, KC_KP_SLASH, DE_ODIA}
},
[_GREEK] = { 
  {_____,  GR_SCLN,  GR_FSIG,    KC_F,    KC_P,    KC_B,          KC_J,    KC_L,         KC_U,    DE_Z,        DE_UDIA,     DE_ADIA},
  {_____,  KC_A,  KC_R,    KC_S,    KC_T,    KC_G,          KC_M,    KC_N,         GR_EPSL,    KC_I,        GR_TONS,      _____},
  {_____,  DE_Y,  KC_X,    KC_C,    KC_D,    KC_V,          KC_K,    KC_H,         KC_COMM, KC_DOT,      DE_MINS,    XXXXX},
  {_____,  _____, _____, _____, XXXXX, XXXXX,               _____,  _____,     KC_SPC,  _____, KC_KP_SLASH, DE_ODIA}
},
[_NAV] = { 
  {_____,   DE_DEG, KC_F7,   KC_F8,    KC_F9,  KC_F10,       KC_PGUP, KC_HOME, KC_UP,   KC_END,   _____, KC_AUDIO_VOL_UP},
  {_____,   _____,  KC_F4,   KC_F5,    KC_F6,  KC_F11,       KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, _____, KC_AUDIO_VOL_DOWN},
  {_____,   _____,  KC_F1,   KC_F2,    KC_F3,  KC_F12,       _____,   KC_INS,  XXXXX,   KC_DEL,   _____, _____},
  {_____,   _____,  _____,   KC_LALT,  _____,  _____,        KC_ENT,  _____,   _____,   _____,    _____, _____}
},
[_SYM] = { 
  {DE_AMPR, DE_AT,   DE_DQUO, DE_EURO, DE_LCBR, DE_RCBR,     DE_TILD, KC_7,    KC_8,   KC_9,  DE_MINS, DE_QUOT},
  {DE_SECT, DE_EXLM, DE_SS,   DE_HASH, DE_LPRN, DE_RPRN,     DE_ASTR, KC_4,    KC_5,   KC_6,  DE_PLUS, _____},
  {DE_DLR,  DE_QUES, DE_LABK, DE_RABK, DE_LBRC, DE_RBRC,     KC_DOT,  KC_1,    KC_2,   KC_3,  DE_EQL,  DE_GRV},
  {DE_PERC, DE_PIPE, DE_CIRC, _____,   _____,   _____,       KC_ENT,  _____,   _____,  KC_0,  DE_BSLS, DE_ACUT}
}
};
