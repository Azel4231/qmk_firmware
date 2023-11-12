// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"
 
#define _SYM 5
#define _NAV 4
#define _OLD 3
#define _ALT_LAY 2
#define _MAC 1
#define _COLEMAK 0

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
 - avrdude -D -patmega32u4 -cavr109 -P/dev/ttyACM0 -b57600 -Uflash:w:/home/.../github/qmk_firmware/azelus3_default.hex:i 
 (-D avoids clearing the memory before trying to read the new firmware)
 (absolute path mandatory!) 


*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAK] = { 
  {KC_ESC,  XXXXX, XXXXX,   XXXXX,   KC_F5,   XXXXX,      XXXXX,   KC_KP_SLASH,  XXXXX,   XXXXX,  XXXXX,   DE_ODIA},
  {KC_TAB,  KC_Q,  KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,         KC_U,    DE_Z,   DE_UDIA, DE_ADIA},
  {KC_LCTL, KC_A,  KC_R,    KC_S,    KC_T,    KC_G,       KC_M,    KC_N,         KC_E,    KC_I,   KC_O,    KC_BSPC},
  {XXXXX,   DE_Y,  KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H,         KC_COMM, KC_DOT, DE_MINS, KC_DEL},
  {XXXXX,   XXXXX, KC_LGUI, KC_LALT, KC_LSFT, MO(_SYM),   KC_ENT,  MO(_NAV),     KC_SPC,  _____,  XXXXX,   XXXXX}
},
[_ALT_LAY] =  { 
  {KC_ESC,  XXXXX, XXXXX,   XXXXX,   KC_F5,   XXXXX,      XXXXX,   KC_KP_SLASH,  XXXXX,    XXXXX,  XXXXX,   DE_ODIA},
  {KC_TAB,  KC_Q,  KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,         KC_U,     DE_Z,   DE_UDIA, DE_ADIA},
  {KC_LSFT, KC_A,  KC_R,    KC_S,    KC_T,    KC_G,       KC_M,    KC_N,         KC_E,     KC_I,   KC_O,    KC_BSPC},
  {KC_LCTL, DE_Y,  KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H,         KC_COMM,  KC_DOT, DE_MINS, KC_DEL},
  {XXXXX,   XXXXX, KC_LGUI, KC_LALT, KC_LSFT, MO(_SYM),   KC_ENT,  MO(_NAV),     KC_SPC,   _____,  XXXXX,   XXXXX}
},
[_NAV] = { 
  {DF(_COLEMAK), XXXXX,   XXXXX,   XXXXX,    _____,  XXXXX,      XXXXX,   _____,   XXXXX,   XXXXX,    XXXXX, _____},
  {DF(_ALT_LAY), DE_DEG,  KC_F7,   KC_F8,    KC_F9,  KC_F10,     KC_PGUP, KC_HOME, KC_UP,   KC_END,   _____, KC_AUDIO_VOL_UP},
  {_____,        _____,   KC_F4,   KC_F5,    KC_F6,  KC_F11,     KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, _____, KC_AUDIO_VOL_DOWN},
  {_____,        _____,   KC_F1,   KC_F2,    KC_F3,  KC_F12,     _____,   KC_INS,  XXXXX,   KC_DEL,   _____, _____},
  {XXXXX,        XXXXX,   _____,   KC_LALT,  _____,  _____,      KC_ENT,  _____,   _____,   _____,    XXXXX, XXXXX}
},
[_SYM] = { 
  {DE_PERC, XXXXX,   XXXXX,   XXXXX,   DE_PIPE, XXXXX,     XXXXX,   _____,   XXXXX,  XXXXX, XXXXX,    DE_ACUT},
  {DE_AMPR, DE_AT,   DE_DQUO, DE_EURO, DE_LCBR, DE_RCBR,   DE_TILD, KC_7,    KC_8,   KC_9,  KC_DOT,   DE_QUOT},
  {DE_SECT, DE_EXLM, DE_SS,   DE_HASH, DE_LPRN, DE_RPRN,   DE_ASTR, KC_4,    KC_5,   KC_6,  DE_PLUS,  _____},
  {DE_DLR,  DE_QUES, DE_LABK, DE_RABK, DE_LBRC, DE_RBRC,   DE_BSLS, KC_1,    KC_2,   KC_3,  DE_EQL,   DE_GRV},
  {XXXXX,   XXXXX,   DE_CIRC, _____,   _____,   _____,     KC_ENT,  KC_0,    _____,  _____, XXXXX,    XXXXX}
}
};



/*
MacLayer
* Problem: Layers werden anhand ihrer Indizes von oben nach unten verwendet. Wenn die Sym Layer ein KC_TRNS hat, würde sie erst auf der Mac Layer landen und danach auf Colemak. 
* Wenn man es sauber will, müsste man also die SymLayers für Mac duplizieren. Und sie wie einen serialisierten Baum anordnen: base, sym-base, nav-base, mac, sym-mac, nav-mac. Das war mir zu viel Aufwandnur für ein @, ich merke mir lieber Alt+L.


[_MAC] = { 
  {_____,   XXXXX,  XXXXX, XXXXX,   _____, XXXXX,      XXXXX,  _____, XXXXX,   XXXXX,  XXXXX,   _____},
  {_____,   _____,  _____, _____,   _____, _____,      _____,  _____, _____,   _____,  _____,   _____},
  {KC_LCMD, _____,  _____, _____,   _____, _____,      _____,  _____, _____,   _____,  _____,   _____},
  {KC_LCTL, _____,  _____, _____,   _____, _____,      _____,  _____, _____,   _____,  _____,   _____},
  {XXXXX,   XXXXX,  _____, KC_LOPT, _____, _____,      _____,  _____, _____,   _____,  XXXXX,   XXXXX}
},


Old - selbes Problem:

[_OLD] = { 
  {KC_ESC,  XXXXX, XXXXX,   XXXXX,   KC_F5,   XXXXX,      XXXXX,   KC_KP_SLASH,  XXXXX,   XXXXX,  XXXXX,   DE_ODIA},
  {KC_TAB,  KC_Q,  KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,         KC_U,    DE_Z,   DE_UDIA, DE_ADIA},
  {KC_LSFT, KC_A,  KC_R,    KC_S,    KC_T,    KC_G,       KC_M,    KC_N,         KC_E,    KC_I,   KC_O,    KC_BSPC},
  {KC_LCTL, DE_Y,  KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H,         KC_COMM, KC_DOT, DE_MINS, KC_RSFT},
  {XXXXX,   XXXXX, KC_LGUI, KC_LALT, KC_SPC,  MO(_SYM),   KC_ENT,  MO(_NAV),     XXXXX,   _____,  XXXXX,   XXXXX}
},


*/


/*
Keyboard Layout Editor: http://www.keyboard-layout-editor.com/#/




["Esc", {x:3}, "F5", {x:2.5}, "/", {x:3}, "Ö"],
["Tab", "Q", "W", "F", "P", "B", {x:0.5},"J", "L", "U", "Z", "Ü", "Ä"],
["Shift", "A", "R", "S",{n:true}, "T", "G", {x:0.5}, "M", {n:true},"N", "E", "I", "O", "←"],
["Ctrl", "Y", "X", "C", "D", "V", {x:0.5}, "K", "H", ",", ".", "-", "Shift"],
[{x:3}, "Meta", {x:4.5}, ""],
[{x:3}, "Alt", "Blank", {c:"#90B0F0"}, "Sym", {c:"#D0D0D0",x:0.5}, "Enter", {c:"#F0F0A0"}, "Nav", {c:"#D0D0D0"},  "Del"],

,

[{y:1}, "Esc", {x:3}, "F5", {x:2.5}, "/", {x:3}, "Ö"],
["Tab", "Q", "W", "F", "P", "B", {x:0.5},"J", "L", "U", "Z", "Ü", "Ä"],
["Ctrl", "A", "R", "S",{n:true}, "T", "G", {x:0.5}, "M", {n:true},"N", "E", "I", "O", "←"],
["", "Y", "X", "C", "D", "V", {x:0.5}, "K", "H", ",", ".", "-", ""],
[{x:3}, "Meta", {x:4.5}, "Toggle Alt Layout"],
[{x:3}, "Alt", "Shift", {c:"#90B0F0"}, "Sym", {c:"#D0D0D0",x:0.5}, "Enter", {c:"#F0F0A0"}, "Nav", {c:"#D0D0D0"},  "Blank"]

,

[{c:"#F0F0A0", y:1},"Base Layer",           {x:3}, ""        , {x:2.5}, ""                    , {x:3}, ""],
["Alt Layer", "°", "F7", "F8", "F9", "F10", {x:0.5},"Pg↑", "Home", "↑", "End", "", "Vol+"],
["", "Old Layer", "F4", "F5",{n:true}, "F6", "F11", {x:0.5}, "Pg↓",{n:true}, "←", "↓", "→", "", "Vol-"],
["", "Mac Layer", "F1", "F2", "F3", "F12", {x:0.5}, "", "Ins", "", "Del", "", ""],
[{x:3}, "", {x:4.5}, ""],
[{x:3}, "", "", "", {x:0.5}, "", "", ""]

,

[{c:"#90B0F0", y:1},"%", {x:3}, "|", {x:2.5}, "", {x:3}, "´"],
["&", "@", "\"", "€", "{", "}", {x:0.5},"~", "7", "8", "9", ".", "'"],
["§", "!", "ß", "#", {n:true},"(", ")", {x:0.5}, "*", {n:true},"4", "5", "6", "+", "←"],
["$", "?", "<", ">", "[", "]", {x:0.5}, "\\", "1", "2", "3", "=", "`"],
[{x:3}, "^", {x:4.5}, ""],
[{x:3}, "", "", "", {x:0.5}, "", "0", ""]




*/


/*
Ergogen: https://ergogen.cache.works/



points:
  zones:
    matrix:
      anchor:
        rotate: 0
      columns:
        pinky2:
          rows.extra.skip: true 
        pinky:
          key.stagger: 1 
        ring:
          key.stagger: 12 
        middle:
          key.stagger: 5
        index:
          key.stagger: -8 
        inner:
          key.stagger: -4
          rows.extra.skip: true 
      rows: 
        bottom: 
        home:
        top:
        extra:
    meta:
      anchor:
        ref: matrix_middle_bottom
        shift: [0,-1.4u]
      columns:
        meta_col:
      rows:
        meta_row:
    thumbfan:
      anchor:
        ref: matrix_inner_bottom
        shift: [-0.6u, -1.4u]
      columns:
        near:
        home:
        far:
      rows:
        thumb: 
  rotate: -20
  mirror:
    ref: matrix_pinky_home
    distance: 195

*/