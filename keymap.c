/* Copyright 2018 MechMerlin
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
#include "Keymap.h"

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  }

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  M_HVIS = SAFE_RANGE,
  M_XOPSLAG,
  M_FLASK,
  M_SELECT,
  M_EXECUTE,
  M_WHERE,
  M_FROM,
  M_DROP,
  M_CREATE_TABLE,
  M_CREATE_PROC
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE] = LAYOUT_ortho_5x15(
        KC_F2   ,KC_F4  ,KC_F5    ,KC_ESC  ,XXXXXXX ,KC_NUBS ,S(KC_NUBS),S(KC_SLSH),KC_SLSH ,KC_ASTR   ,S(KC_7) ,S(KC_8)  ,S(KC_9)  ,RALT(KC_8)      ,RALT(KC_9) ,
        KC_7    ,KC_8   ,KC_9     ,KC_TAB  ,KC_Q    ,KC_W    ,KC_F      ,KC_P      ,KC_G    ,KC_J      ,KC_L    ,KC_U     ,KC_Y     ,LCTL(KC_BSPC)   ,KC_DEL     ,  
        KC_4    ,KC_5   ,KC_6     ,KC_BSPC ,TDDK_AA ,KC_R    ,KC_S      ,KC_T      ,KC_D    ,KC_H      ,KC_N    ,TDDK_EE  ,KC_I     ,TDDK_OO         ,KC_ENT     ,
        KC_1    ,KC_2   ,KC_3     ,KC_LSFT ,KC_Z    ,KC_X    ,KC_C      ,KC_V      ,KC_B    ,KC_K      ,KC_M    ,KC_COMM  ,KC_DOT   ,KC_UP           ,KC_MINS    ,
        KC_0    ,KC_LCTL,KC_ENT   ,KC_LCTL ,KC_LGUI ,KC_LALT ,KC_SPC    ,KC_SPC    ,KC_SPC  ,LOWER     ,RAISE   ,KC_RALT  ,KC_LEFT  ,KC_DOWN         ,KC_RIGHT       
  ),
 [_LOWER] = LAYOUT_ortho_5x15(
        _______ ,_______ ,_______ ,_______ ,KC_F1   ,KC_F2   ,KC_F3    ,KC_F4    ,XXXXXXX  ,XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX   ,XXXXXXX ,RESET     ,
        _______ ,_______ ,_______ ,_______ ,KC_F5   ,KC_F6   ,KC_F7    ,KC_F8    ,XXXXXXX  ,XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX   ,XXXXXXX ,XXXXXXX   ,  
        _______ ,_______ ,_______ ,_______ ,KC_F9   ,KC_F10  ,KC_F11   ,KC_F12   ,XXXXXXX  ,XXXXXXX  ,XXXXXXX ,XXXXXXX ,M_HVIS    ,XXXXXXX ,XXXXXXX   ,
        _______ ,_______ ,_______ ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX ,XXXXXXX ,M_XOPSLAG ,_______ ,XXXXXXX   ,
        _______ ,_______ ,_______ ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,_______  ,_______ ,XXXXXXX ,_______   ,_______ ,_______    
  ),
 [_RAISE] = LAYOUT_ortho_5x15(
        M_CREATE_PROC  ,M_SELECT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,RESET     ,
        M_CREATE_TABLE ,M_FROM   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX   ,  
        M_DROP         ,M_WHERE  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX   ,
        M_EXECUTE      ,XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX   ,
        XXXXXXX        ,XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,_______  ,_______ ,XXXXXXX ,_______ ,_______ ,_______   
  ),
  [_ADJUST] = LAYOUT_ortho_5x15(
        XXXXXXX ,XXXXXXX, XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,RESET     ,
        XXXXXXX ,XXXXXXX, XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX   ,  
        XXXXXXX ,XXXXXXX, XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX   ,
        XXXXXXX ,XXXXXXX, XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX   ,
        XXXXXXX ,XXXXXXX, XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,_______  ,_______ ,XXXXXXX ,_______ ,_______ ,_______   
  ),
  [_EXTEND] = LAYOUT_ortho_5x15(
        KC_ESC  ,KC_1    ,KC_2    ,KC_3   ,KC_4    ,KC_5     ,KC_6     ,KC_7     ,KC_8    ,KC_9      ,KC_0    ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX    ,
        KC_TAB  ,KC_Q    ,KC_W    ,KC_E   ,KC_R    ,KC_T     ,KC_Y     ,KC_U     ,KC_I    ,KC_O      ,KC_P    ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX    ,  
        M_FLASK ,KC_A    ,KC_S    ,KC_D   ,KC_F    ,KC_G     ,KC_H     ,KC_J     ,KC_K    ,KC_L      ,KC_X    ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX    ,
        KC_LSFT ,KC_Z    ,KC_X    ,KC_C   ,KC_V    ,KC_B     ,KC_N     ,KC_M     ,KC_X    ,KC_X      ,KC_X    ,XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX    ,
        KC_LCTL ,KC_LGUI ,KC_LALT ,KC_SPC ,KC_SPC  ,KC_SPC   ,LOWER    ,RAISE    ,KC_RALT ,_______   ,_______ ,XXXXXXX ,_______ ,_______ ,_______  
    )
};

// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    //EXCEL
    case M_XOPSLAG:
      if (record->event.pressed) {
        // when keycode M_XOPSLAG is pressed
        SEND_STRING("XOPSLAG");
      } else {
        // when keycode M_XOPSLAG is released
      } 
      break;
    case M_HVIS:
      if (record->event.pressed) {
        // when keycode M_HVIS is pressed
        SEND_STRING("HVIS");
      } else {
        // when keycode M_HVIS is released
      }
      break;

      //SQL
    case M_SELECT:
      if (record->event.pressed) {
        // when keycode M_HVIS is pressed
        SEND_STRING("SELECT ");
      } else {
        // when keycode M_HVIS is released
      }
      break;
    case M_EXECUTE:
      if (record->event.pressed) {
        // when keycode M_HVIS is pressed
        SEND_STRING("EXECUTE ");
      } else {
        // when keycode M_HVIS is released
      }
      break;
    case M_CREATE_PROC:
      if (record->event.pressed) {
        // when keycode M_HVIS is pressed
        SEND_STRING("CREATE PROC ");
      } else {
        // when keycode M_HVIS is released
      }
      break;
    case M_WHERE:
      if (record->event.pressed) {
        // when keycode M_HVIS is pressed
        SEND_STRING("WHERE ");
      } else {
        // when keycode M_HVIS is released
      }
      break;
    case M_FROM:
      if (record->event.pressed) {
        // when keycode M_HVIS is pressed
        SEND_STRING("FROM ");
      } else {
        // when keycode M_HVIS is released
      }
      break;
    case M_DROP:
      if (record->event.pressed) {
        // when keycode M_HVIS is pressed
        SEND_STRING("DROP ");
      } else {
        // when keycode M_HVIS is released
      }
      break;
    case M_CREATE_TABLE:
      if (record->event.pressed) {
        // when keycode M_HVIS is pressed
        SEND_STRING("CREATE TABLE ");
      } else {
        // when keycode M_HVIS is released
      }
      break;

      //ANDET
    case M_FLASK:
      if (record->event.pressed) {
        // when keycode M_HVIS is pressed
        SEND_STRING("12345");
      } else {
        // when keycode M_HVIS is released
      }
      break;
  }
  return true;

}
