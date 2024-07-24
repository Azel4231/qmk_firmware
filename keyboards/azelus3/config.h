// Copyright 2023 Azel4231 (@Azel4231)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once 

/* Neu */
#define MATRIX_ROWS 5
#define MATRIX_COLS 12

#define MATRIX_ROW_PINS { D1, D2, B0, D3, B2 }
#define MATRIX_COL_PINS { F7, F6, F5, F4, F1, F0,     D4, C6, D7, B6, B4, B5 }

/* Alt: 
#define MATRIX_ROWS 4
#define MATRIX_COLS 12
#define MATRIX_ROW_PINS { D3, B0, B2, D2 }
#define MATRIX_COL_PINS { F7, F6, F5, F0, F4, F1,     D0, D4, D7, B4, B5, B6 }
*/

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
#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT
#define FORCE_NKRO

