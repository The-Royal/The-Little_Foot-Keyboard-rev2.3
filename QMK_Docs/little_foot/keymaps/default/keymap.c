
#include QMK_KEYBOARD_H
#include "quantum.h"

// Layer names
enum{
  // - Base layer:
  _BASE,
  // - Symbols, numbers, and functions:
  _FN,
  // - Alternate Function layer:
  _LN
};

//Tap Dance Declarations
enum {
  TD_QUES_ENT = 0,
  TD_SPC_SHFT = 1,
  TD_CTRL_Z = 2,
  TD_CTRL_Y = 3,
  TD_CTRL_C = 4,
  TD_CTRL_V = 5,
  TD_CTRL_A = 6,
  TD_P_BSLS = 7
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for /?, twice for Enter
  [TD_QUES_ENT]  = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_ENT),
  [TD_SPC_SHFT]  = ACTION_TAP_DANCE_DOUBLE(KC_SPACE, KC_LSFT),
  [TD_CTRL_Z]  = ACTION_TAP_DANCE_DOUBLE(KC_Z, LCTL(KC_Z)),
  [TD_CTRL_Y]  = ACTION_TAP_DANCE_DOUBLE(KC_Y, LCTL(KC_Y)),
  [TD_CTRL_C]  = ACTION_TAP_DANCE_DOUBLE(KC_C, LCTL(KC_C)),
  [TD_CTRL_V]  = ACTION_TAP_DANCE_DOUBLE(KC_V, LCTL(KC_V)),
  [TD_CTRL_A]  = ACTION_TAP_DANCE_DOUBLE(KC_A, LCTL(KC_A)),
  [TD_P_BSLS]  = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_BSLS)
// Other declarations would go here, separated by commas, if you have them
};

enum combos {
  combo_ESC,
  combo_BACK
};


enum combo_events {
  RGB_COMBO
};

const uint16_t PROGMEM esc_combo[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_9, KC_0, COMBO_END};
const uint16_t PROGMEM rgb_combo[] = {KC_R, KC_G, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [combo_ESC] = COMBO(esc_combo, KC_ESC),
  [combo_BACK] = COMBO(bspc_combo, KC_BSPC),
  [RGB_COMBO] = COMBO_ACTION(rgb_combo)
};

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case RGB_COMBO:
      if (pressed) {
        tap_code16(RGB_MOD);
      }
      break;
  }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_big_space_base(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,              KC_0,
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TD(TD_CTRL_Y),    KC_U,    KC_I,     KC_O,              TD(TD_P_BSLS),
    TD(TD_CTRL_A),    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,           KC_SCLN,
    TD(TD_CTRL_Z),    KC_X,    TD(TD_CTRL_C),    TD(TD_CTRL_V),   KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT, TD(TD_QUES_ENT),
                                LSFT_T(KC_SPACE)     
  ),

  [_FN] = LAYOUT_big_space_base(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,              KC_0,
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,              KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,           KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,         KC_SLSH,
                                                   KC_TRNS   
  ), 

  [_LN] = LAYOUT_big_space_base(
    KC_TRNS,   KC_F1,   KC_F2,  KC_F3,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_7,    KC_8,    KC_9,
    KC_TRNS,   KC_F4,   KC_F5,  KC_F6,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_4,    KC_5,    KC_6,
    KC_TRNS,   KC_F7,   KC_F8,  KC_F9,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_1,    KC_2,    KC_3,
    KC_TRNS,   KC_F10,  KC_F11, KC_F12,   KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_0, KC_TRNS,
                                                KC_TRNS
  )
};
