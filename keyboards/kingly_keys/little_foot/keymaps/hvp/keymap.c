
#include QMK_KEYBOARD_H
#include "hvp.c"

#define LT3_ESC MT(MOD_LSFT, KC_ESC)
#define LT4_TAB LT(4, KC_TAB)
#define D_NAVI MT(MOD_LCTL | MOD_LSFT, KC_D)
#define D_NAVI MT(MOD_LCTL | MOD_LSFT, KC_D)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_split_space_base(
    KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,             KC_0,
    KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,             KC_P,
    KC_A,   KC_S,    KC_D,     LT(3,KC_F),    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,      KC_SCLN,
    KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,         TD(TD3),
                LT(1,KC_BSPC), MT(MOD_LSFT, KC_SPACE), CTL_T(KC_SPACE),  LT(2, KC_ENT)
  ),

  [1] = LAYOUT_split_space_base(
    LT(2, KC_ESC), _______, _______, _______, _______, _______, _______,  _______, KC_MINS, KC_BSPC,
    KC_TAB,  _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    KC_LSFT, _______, _______, _______, _______,KC_UNDERSCORE, KC_PLUS, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_QUOT,
    _______, _______, _______, _______, _______, _______, _______,   LSFT(KC_9), LSFT(KC_0), _______,
                  _______,            _______,        KC_LALT,              KC_LCTRL
  ), 

  [2] = LAYOUT_split_space_base(
      KC_F1,   KC_F2,  KC_F3, _______,  _______,  _______,  _______,  KC_7, KC_8, KC_9,
      KC_F4,   KC_F5,  KC_F6, _______,  _______,  _______,  _______,  KC_4, KC_5, KC_6,
      KC_F7,   KC_F8,  KC_F9, _______,  _______,  _______,  _______,  KC_1, KC_2, KC_3,
      KC_F10,  KC_F11, KC_F12, _______, _______,  _______,  _______,  _______,  KC_0, _______,
                  _______,             _______,          KC_LGUI,                _______
  ),

  [3] = LAYOUT_split_space_base(
    _______,  _______,  _______,  _______,    _______,    _______,   _______,    _______,    _______,    _______,
    _______,  _______,  _______,  _______,    _______,    KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______,
    KC_PSCR,  _______,  D_NAVI,  _______,    _______,    KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,    _______,
    RESET,  _______,  _______, _______,   _______,    KC_MSTP, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
                  _______,             KC_MUTE,          KC_MPLY,                _______
  )
};


enum combos {
  AS_ESC,
  QW_TAB,
  OP_BSP,
  KL_ALTA,
  KL_ALTW
};

const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM l_combo[] = {KC_L, KC_SCLN, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [AS_ESC] = COMBO(as_combo, KC_ESC),
  [QW_TAB] = COMBO(qw_combo, KC_TAB),
  [OP_BSP] = COMBO(op_combo, KC_BSPC),
  [KL_ALTA] = COMBO(kl_combo, ALGR(KC_A)),
  [KL_ALTW] = COMBO(l_combo, ALGR(KC_W))
};
