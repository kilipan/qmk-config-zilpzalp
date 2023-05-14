#include QMK_KEYBOARD_H
#include "zilpzalp.h"
// all combos and custom keycodes defined here
#include "aptmak_hrm_combos.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *     ┌───┬───┬───┬───┐        ┌───┬───┬───┬───┐
     *   V │ W │ F │ P │ B │ Q      │ J │ L │ U │ Y │
     * ┌───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┐
     * │ R │ S │ T │ H │ K │        │ X │ N │ A │ I │ O │
     * └───┼───┼───┼───┼───┘        └───┼───┼───┼───┼───┘
     *   z │ C │ G │ D │             ENT│ M │ , │ . │ /
     *     └───┴───┼───┼───┐        ┌───┼───┼───┴───┘
     *             │ESC│SPC│        │ E │ENT│
     *             └───┴───┘        └───┴───┘
     */
    [_QWERTY] = LAYOUT(
                 KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,  KC_P,
                 KC_X,    KC_C,    KC_B,                      KC_M,    KC_COMM, KC_DOT,
                                   NUM_ESC, NAV_SPC, KC_N,    FUN_ENT
    ),
    [_APTMAK] = LAYOUT(
                 KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,
        HRM_R,   HRM_S,   HRM_T,   HRM_H,   HRM_K,   HRM_X,   HRM_N,   HRM_A,   HRM_I,  HRM_O,
                 KC_C,    KC_G,    KC_D,                      KC_M,    KC_COMM, KC_DOT,
                                   NUM_ESC, NAV_SPC, SYM_KCE, FUN_ENT
    ),
    [_COLEMAK] = LAYOUT(
                 KC_W,    KC_F,    KC_P,    KC_B,    KC_K,    KC_L,    KC_U,    KC_Y,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,  KC_O,
                 KC_X,    KC_C,    KC_D,                      KC_H,    KC_COMM, KC_DOT,
                                   NUM_ESC, NAV_SPC, SYM_KCE, FUN_ENT
    ),
    [_NUM] = LAYOUT(
                 KC_9,    KC_8,    KC_7,    XXXXXXX,             KC_PLUS, KC_7,    KC_8,    KC_9,
        KC_LCTL, ALT_T(KC_6),GUI_T(KC_5),SFT_T(KC_4), XXXXXXX,   KC_MINS, KC_4,    KC_5,    KC_6,    KC_SLASH,
                 KC_3,    KC_2,    KC_1,                                  KC_1,    KC_2,    KC_3,
                                   _______, _______,             KC_E,    KC_0
    ),
    [_NAV] = LAYOUT(
                 KC_INS,  KC_UP,   KC_BSPC, KC_VOLD,                   KC_VOLU, KC_BSPC, KC_DEL,  KC_INS,
        KC_LCTL, ALT_T(KC_LEFT),GUI_T(KC_DOWN),SFT_T(KC_RGHT),KC_MUTE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  KC_TAB,
                 KC_HOME, KC_PGDN, KC_END,                                      KC_HOME, KC_PGUP, KC_END,
                                   _______, _______,                   _______, _______
    ),
    [_SYM] = LAYOUT(
                 KC_GRV,  KC_DQT,  KC_MDOT, KC_LBRC, KC_RBRC, KC_BSLS, KC_PIPE, KC_QUES,
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_AMPR, KC_ASTR, KC_PERC,  KC_CIRC,
                 KC_TILD, KC_QUOT, KC_UNDS,                   KC_MINS, KC_PLUS, KC_EQL,
                                   _______, KC_LSFT, _______, _______
    ),
    [_FUN] = LAYOUT(
                 QK_BOOT, _______, _______, _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,
        QK_RBT,  _______, _______, _______, _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_F10,
                 _______, _______, _______,                   KC_F1,   KC_F2,   KC_F3,
                                   _______, _______, _______, _______
    )
};

//// custom shifted comma (->semicolon) and dot (->colon)
// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {
        case KC_COMMA:
        {
            // Initialize a boolean variable that keeps track
            // of the comma key status: registered or not?
            static bool sclnkey_registered;
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_SCLN keycode
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_SCLN);
                    // Update the boolean variable to reflect the status of KC_SCLN
                    sclnkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(mod_state);
                    return false;
                }
            } else { // on release of KC_COMMA
                // In case KC_SCLN is still being sent even after the release of KC_COMMA
                if (sclnkey_registered) {
                    unregister_code(KC_SCLN);
                    sclnkey_registered = false;
                    return false;
                }
            }
            // Let QMK process the KC_COMMA keycode as usual outside of shift
            return true;
        }
        case KC_DOT:
        {
            // Initialize a boolean variable that keeps track
            // of the comma key status: registered or not?
            static bool sclnkey_registered;
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                    // send KC_SCLN instead (turns to colon due to shift)
                    register_code(KC_SCLN);
                    // Update the boolean variable to reflect the status of KC_SCLN
                    sclnkey_registered = true;
                    return false;
                }
            } else { // on release of KC_DOT
                // In case KC_SCLN is still being sent even after the release of KC_DOT
                if (sclnkey_registered) {
                    unregister_code(KC_SCLN);
                    sclnkey_registered = false;
                    return false;
                }
            }
            // Let QMK process the KC_DOT keycode as usual outside of shift
            return true;
        }
        case KC_SCH:
        {
            if (record->event.pressed) {
                tap_code(KC_S);
                tap_code(KC_C);
                tap_code(KC_H);
            } else {
            }
            break;
        }
    }
    return true;
};
