#pragma once

// Vial config
#define VIAL_KEYBOARD_UID {0xBE, 0x59, 0x18, 0xAE, 0x82, 0x68, 0xD8, 0xD7}
#define VIAL_UNLOCK_COMBO_ROWS { 2, 4 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 0 }

#define TAPPING_TERM 170

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD
