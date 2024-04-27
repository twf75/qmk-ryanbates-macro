// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
enum custom_keycodes {
  SHUTUP = SAFE_RANGE,  // Based on https://getreuer.info/posts/keyboards/macros/index.html
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(LSFT(KC_LEFT), LSFT(KC_RIGHT))  },
    [1] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [2] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [3] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case SHUTUP:  // Mutes Teams Mic, Mute system Audio, Disable video
      if (record->event.pressed) {
//        SEND_STRING(SS_LCTL(SS_LSFT(TAP (X_M))) SS_LCTL(SS_LSFT(TAP (X_o))) TAP(X_AUDIO_MUTE));
		  SEND_STRING( 
			SS_LCTL(SS_LSFT(SS_TAP(X_M)))
			SS_LCTL(SS_LSFT(SS_TAP(X_O)))
			SS_TAP(X_AUDIO_MUTE)
			);
      }
      return false;
  }
  return true;
}


led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {   0, 1, 2,   3 },
  {   4, 5, 6,   7 },
  {   8, 9, 10,  11 },
  {   13 }
}, {
  // LED Index to Physical Position
  { 188,  16 }, { 187,  48 }, { 149,  64 }, { 112,  64 }, {  37,  48 }, {  38,  16 }
}, {
  // LED Index to Flag
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1
} };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYER 0 - Teams call shortcuts
 *         ,-------------------------------.
 *         | Audio | Disabl| All   | Raise |
 *		   | Mute  | Video | Off   | hand  |
 *         |-------+-------+-------+-------|
 *         |  NO   |   NO  |  Mute | Accept|
 *         |       |       | Audio |  call |
 * ,-------+-------+-------+-------+-------|
 * |   L1  |   NO  |  NO   |  NO   | End   |
 * |       |       |       |       |  call |
 * `-------+-------+-------+-------+-------'
 */
    [0] = LAYOUT_ortho_3x4(
        RCS(KC_M),  	RCS(KC_O),	SHUTUP,		RCS(KC_K),
        KC_NO,   		KC_NO,   	KC_AUDIO_MUTE,  RCS(KC_A),
        LCTL(KC_SPACE),	KC_NO,   	RGB_TOG,   		RCS(KC_H),
		DF(0),   		KC_NO,   	KC_NO,   		KC_NO
    ),
	
/* LAYER 1
 *         ,-------------------------------.
 *         |  L1   | Prev  | Next  | Play  |
 *         |       |       |       |       |
 *         |-------+-------+-------+-------|
 *         |       |       |       |       |
 *         |       |       |       |       |
 * ,-------+-------+-------+-------+-------|
 * |       |       |       |       |       |
 * |       |       |       |       |       |
 * `-------+-------------------------------'
 */	
	[1] = LAYOUT_ortho_3x4(
        RGB_MOD,   RGB_MODE_REVERSE,   RGB_MODE_TWINKLE,   RGB_MODE_GRADIENT,
        KC_5,   KC_6,   KC_7,   KC_8,
        KC_9,   KC_Z,   KC_X,   RGB_TOG,
		DF(0),   KC_NO,   KC_NO,   KC_NO
    ),
/* LAYER 2
 *         ,-------------------------------.
 *         |  L1   | Prev  | Next  | Play  |
 *         |       |       |       |       |
 *         |-------+-------+-------+-------|
 *         |       |       |       |       |
 *         |       |       |       |       |
 * ,-------+-------+-------+-------+-------|
 * |       |       |       |       |       |
 * |       |       |       |       |       |
 * `-------+-------------------------------'
 */	
	[2] = LAYOUT_ortho_3x4(
        KC_2,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
		DF(3),   KC_NO,   KC_NO,   KC_NO
    ),
/* LAYER 3
 *         ,-------------------------------.
 *         |  L1   | Prev  | Next  | Play  |
 *         |       |       |       |       |
 *         |-------+-------+-------+-------|
 *         |       |       |       |       |
 *         |       |       |       |       |
 * ,-------+-------+-------+-------+-------|
 * |       |       |       |       |       |
 * |       |       |       |       |       |
 * `-------+-------------------------------'
 */
	[3] = LAYOUT_ortho_3x4(
        KC_3,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
		DF(0),   KC_NO,   KC_NO,   KC_NO
	)
};
