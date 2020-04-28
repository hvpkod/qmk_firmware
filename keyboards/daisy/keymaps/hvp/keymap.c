

#include QMK_KEYBOARD_H
#include "hvp.c"

#define LT3_ESC MT(MOD_LSFT, KC_ESC)
#define LT4_TAB LT(4, KC_TAB)
#define D_NAVI MT(MOD_LCTL | MOD_LSFT, KC_D)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        LT4_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,        KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_BSPC,
        LT3_ESC,    KC_A,    KC_S,    KC_D,    LT(3,KC_F),  KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   TD(TD1),
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,        KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SFTENT,
        KC_LCPO,    KC_LGUI, KC_LALT,   LT(2,KC_BSPC),       LT(1,KC_SPC),              KC_RAPC,   TD(TD2),   TD(TD3)
    ),

 
    [1] = LAYOUT(
        KC_GRV,  KC_1,  KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_BSPC,
        _______,    _______,    _______,    _______,    _______,    _______,    KC_MINS,        KC_EQL, KC_LBRC,    KC_RBRC,    KC_BSLS,
        _______,    _______,    _______,    _______,    _______,    _______,    KC_UNDERSCORE, KC_PLUS, KC_LCBR,    KC_RCBR,   KC_PIPE,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,        _______
    ),


    [2] = LAYOUT(
        KC_TILDE,    KC_EXCLAIM,    KC_AT,    KC_HASH,    KC_DOLLAR,    KC_PERCENT,    KC_CIRCUMFLEX,    KC_AMPERSAND,    KC_ASTERISK,    KC_LPRN, KC_RPRN, KC_BSPC,
        KC_DEL,    _______,    _______,    _______,    _______,    _______,    KC_UNDERSCORE,    KC_PLUS,    KC_LCBR,    KC_RCBR,          KC_PIPE,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,
        _______,    _______,    _______,                   _______, _______,                   _______, _______, _______
    ),

    [3] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        KC_DEL, _______,   KC_LCTL,   D_NAVI,   _______,  _______,  KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______,
        _______,          _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______,
        _______, _______, KC_MPRV,                   KC_MSTP, KC_MPLY,                   KC_MNXT, KC_VOLD, KC_VOLU
    ),
    
    [4] = LAYOUT(
        _______,    RGB_TOG,    RGB_MOD,    RGB_RMOD,   _______,    _______,    _______,    KC_7, KC_8,     KC_9,   KC_0,   _______,
        _______,    RGB_M_P,    RGB_HUD,    RGB_HUI,    _______,    _______,    KC_4,       KC_5, KC_6,     _______,    _______,
        KC_PSCR,    RGB_VAD,    RGB_SAD,    RGB_SAI,    _______,    KC_0,       KC_1,       KC_2, KC_3,     KC_UP,    _______,
        RESET,      RGB_VAI,    _______,    _______,    _______,    KC_LEFT,    KC_DOWN,    KC_RGHT
    )
        
};



enum combos {
  KL_ALTW,
  KL_ALTQU
};


const uint16_t PROGMEM altqu_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM altw_combo[] = {KC_K, KC_L, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [KL_ALTQU] = COMBO(altqu_combo, KC_QUOT),
  [KL_ALTW] = COMBO(altw_combo, ALGR(KC_W))
};
