/* Copyright 2019 T.Shinohara
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MRCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layer_number {
  _NUMBER = 0,
  _CURSOL,
  _MOUSE
};

enum custom_keycodes {
  HELLO = SAFE_RANGE,
  HEY,
  BBACK,
  BFORWARD,
  REDO,
  UNDO,
  SELECTALL,
  TERMINAL,
  CLSTERMINAL,
  CLSWINDOW,
  BROWSER,
  CTL1,
  CTL2,
  CTL3,
  CTL4,
  CTL5,
  NEXTWINDOW,
  CUT,
  COPY,
  PASTE,
  NEWTAB
};

#define NUMBER TO(_NUMBER)
#define CURSOL TO(_CURSOL)
#define MOUSE  TO(_MOUSE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_NUMBER] = LAYOUT( 
    NUMBER,   CURSOL,   MOUSE,
    CTL1,    CTL2,    CTL3,
    NEXTWINDOW,    CTL4,    CTL5,
    KC_TAB,    KC_LALT,    KC_ENT,
    KC_LSFT,    KC_LCTL,  NEWTAB
  ),
  [_CURSOL] = LAYOUT( 
    NUMBER,   CURSOL,   MOUSE,
    BFORWARD, KC_HOME, KC_PGUP,
    BBACK,   KC_END,  KC_PGDN,
    KC_BSPC,  KC_UP,    KC_ENT,
    KC_LEFT,  KC_DOWN, KC_RIGHT
  ), 
  [_MOUSE] = LAYOUT( 
    NUMBER,   CURSOL,   MOUSE,
    CUT,   COPY,  PASTE,
    SELECTALL,  UNDO,  REDO,
    TERMINAL,  BROWSER,  KC_ENT,
    CLSTERMINAL,   CLSWINDOW,  KC_BSPC
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case HELLO:
      if (record->event.pressed) {
        SEND_STRING("Hello world!");
      }
      break;
    case HEY:
      if (record->event.pressed) {
        SEND_STRING("Hey!");
      }
      break;
    case BBACK:
      if (record->event.pressed) {
        register_code(KC_LALT);
        register_code(KC_LEFT);
        unregister_code(KC_LALT);
        unregister_code(KC_LEFT);
      }
      break;
    case BFORWARD:
      if (record->event.pressed) {
        register_code(KC_LALT);
        register_code(KC_RIGHT);
        unregister_code(KC_LALT);
        unregister_code(KC_RIGHT);
      }
      break;
    case REDO:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_LSFT);
        register_code(KC_Z);
        unregister_code(KC_LCTL);
        unregister_code(KC_LSFT);
        unregister_code(KC_Z);
      }
      break;
    case UNDO:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_Z);
        unregister_code(KC_LCTL);
        unregister_code(KC_Z);
      }
      break;
    case SELECTALL:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_A);
        unregister_code(KC_A);
        unregister_code(KC_LCTL);
      }
      break;
    case TERMINAL:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_LALT);
        register_code(KC_T);
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
        unregister_code(KC_T);
      }
      break;
    case BROWSER:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_LALT);
        register_code(KC_F);
        unregister_code(KC_LCTL);
        unregister_code(KC_LALT);
        unregister_code(KC_F);
      }
      break;
    case CLSTERMINAL:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_D);
        unregister_code(KC_LCTL);
        unregister_code(KC_D);
      }
      break;
    case CLSWINDOW:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_W);
        unregister_code(KC_LCTL);
        unregister_code(KC_W);
      }
      break;
    case CTL1:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_1);
        unregister_code(KC_LCTL);
        unregister_code(KC_1);
      }
      break;
    case CTL2:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_2);
        unregister_code(KC_LCTL);
        unregister_code(KC_2);
      }
      break;
    case CTL3:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_3);
        unregister_code(KC_LCTL);
        unregister_code(KC_3);
      }
      break;
    case CTL4:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_4);
        unregister_code(KC_LCTL);
        unregister_code(KC_4);
      }
      break;
    case CTL5:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_5);
        unregister_code(KC_LCTL);
        unregister_code(KC_5);
      }
      break;
    case NEXTWINDOW:
      if (record->event.pressed) {
        register_code(KC_LALT);
        register_code(KC_TAB);
        unregister_code(KC_TAB);
        register_code(KC_TAB);
        unregister_code(KC_TAB);
        unregister_code(KC_LALT);
      }
      break;
    case CUT:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_X);
        unregister_code(KC_LCTL);
        unregister_code(KC_X);
      }
      break;
    case COPY:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_C);
        unregister_code(KC_LCTL);
        unregister_code(KC_C);
      }
      break;
    case PASTE:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_V);
        unregister_code(KC_LCTL);
        unregister_code(KC_V);
      }
      break;
    case NEWTAB:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_T);
        unregister_code(KC_LCTL);
        unregister_code(KC_T);
      }
      break;
  }
  return true;
}
