// Copyright 2024 Andre (@No)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#ifdef ENCODER_ENABLE
 #define ENCODERS_PAD_A { B2, B1 }
 #define ENCODERS_PAD_B { B6, B3 }
#endif

#ifdef RGB_MATRIX_ENABLE
 #define WS2812_DI_PIN F5 
 #define RGB_MATRIX_LED_COUNT 13

 #define RGB_MATRIX_TIMEOUT 20000
 #define ENABLE_RGB_MATRIX_BREATHING
 #define ENABLE_RGB_MATRIX_ALPHAS_MODS
#endif

#ifdef RGBLIGHT_ENABLE
 #define RGBLIGHT_LED_COUNT 13
#endif