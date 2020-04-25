#include QMK_KEYBOARD_H
#include "hvp.c"

#define LT3_ESC MT(MOD_LSFT, KC_ESC)
#define LT4_TAB LT(4, KC_TAB)
#define D_NAVI MT(MOD_LCTL | MOD_LSFT, KC_D)
#define D_NAVI MT(MOD_LCTL | MOD_LSFT, KC_D)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT(
		LT4_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LEFT_PAREN, KC_BSPC, 
		LT3_ESC, KC_A, KC_S, KC_D, LT(3,KC_F), KC_G, KC_H, KC_J, KC_K, KC_L, TD(TD1), TD(TD2),
		CTL_T(KC_SPC), KC_Z, KC_X, GUI_T(KC_C), ALT_T(KC_V), LT(2, KC_B), LT(3, KC_SPC), LT(1,KC_N), KC_M, KC_COMM, KC_DOT, TD(TD3), KC_ENT),

	[1] = LAYOUT(
		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_RBRC, KC_BSLS, 
		KC_DELETE, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, 
		_______, _______, _______, _______, _______, _______, _______, _______, KC_UNDERSCORE, KC_PLUS, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_PIPE),

	[2] = LAYOUT(
		KC_TILDE,  KC_EXCLAIM,  KC_AT,  KC_HASH,  KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_DEL, KC_BSPC,
		_______, _______, _______, _______, _______, _______, _______, KC_UNDERSCORE, KC_PLUS, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_PIPE, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

	[3] = LAYOUT(
		KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_BSPC,
		_______, _______, _______, D_NAVI, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______, 
		_______, _______, _______, _______, _______, KC_MUTE, KC_MPLY, _______, KC_MSTP, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT),
    
    [4] = LAYOUT(
	    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		KC_PSCR, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______, 
		RESET, _______, _______, _______, _______, KC_MUTE, KC_MPLY, _______, KC_MSTP, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT),
    
};


void matrix_init_user(void) {
  // set CapsLock LED to output and low
  setPinOutput(B2);
  writePinLow(B2);
  // set NumLock LED to output and low
  setPinOutput(B6);
  writePinLow(B6);

}

layer_state_t layer_state_set_user(layer_state_t state)
{
    if (layer_state_cmp(state, 1)) {
        writePinHigh(B2);
    } else if (state & (1<<2)) {
        writePinLow(B2);
        writePinHigh(B6);
    } else if (state & (1<<3)) {
        writePinHigh(B2);
        writePinHigh(B6);
    } else {
        writePinLow(B2);
        writePinLow(B6);
    }
    return state;
}
