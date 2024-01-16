#include QMK_KEYBOARD_H
#include "zilpzalp.h"

//// definitions
// layers
enum zilpzalp_layers {
    _ALPHA,
    _NUM,
    _NAV,
    _SYM,
    _FUN
};
// custom keycodes
enum custom_keycodes {
    ALPHA = SAFE_RANGE,
    NUM,
    NAV,
    SYM,
    FUN,
    KC_MDOT
};
// LEFT HAND HOME ROW MODS
#define CTL_A MT(MOD_LCTL, KC_A)
#define ALT_S MT(MOD_LALT, KC_S)
#define GUI_D MT(MOD_LGUI, KC_D)
#define SFT_F MT(MOD_LSFT, KC_F)
#define RALT_G MT(MOD_RALT, KC_G)
// RIGHT HAND HOME ROW MODS
#define RALT_H MT(MOD_RALT, KC_H)
#define SFT_J MT(MOD_RSFT, KC_J)
#define GUI_K MT(MOD_RGUI, KC_K)
#define ALT_L MT(MOD_LALT, KC_L)
#define CTL_P MT(MOD_RCTL, KC_P)
// LAYER TAP BEHAVIORS
#define NUM_ESC LT(_NUM, KC_ESC)
#define NAV_SPC LT(_NAV, KC_SPC)
#define SYM_KCN LT(_SYM, KC_N)
#define FUN_ENT LT(_FUN, KC_ENT)
// OTHER
#define KC_MDOT LSFT(RALT(KC_SCLN))
// combos
enum combo_events {
    CAPSWORD_COMBO,
    CAPSLOCK_COMBO,
    Q_COMBO,
    Z_COMBO,
    B_COMBO,
    MINUS_COMBO,
    SLASH_COMBO,
    SEMI_COMBO,
    QUOT_COMBO,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;
const uint16_t PROGMEM capsword_combo[] = {SFT_F, SFT_J, COMBO_END};
const uint16_t PROGMEM capslock_combo[] = {KC_W, KC_O, COMBO_END};
const uint16_t PROGMEM q_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM z_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM b_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM minus_combo[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM slash_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM semi_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM quot_combo[] = {KC_U, KC_I, COMBO_END};
combo_t key_combos[] = {
    [CAPSWORD_COMBO] = COMBO(capsword_combo, CW_TOGG),
    [CAPSLOCK_COMBO] = COMBO(capslock_combo, KC_CAPS),
    [Q_COMBO] = COMBO(q_combo, KC_Q),
    [Z_COMBO] = COMBO(z_combo, KC_Z),
    [B_COMBO] = COMBO(b_combo, KC_B),
    [MINUS_COMBO] = COMBO(minus_combo, KC_MINUS),
    [SLASH_COMBO] = COMBO(slash_combo, KC_SLASH),
    [SEMI_COMBO] = COMBO(semi_combo, KC_SCLN),
    [QUOT_COMBO] = COMBO(quot_combo, KC_QUOT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *                                 '
     *     ┌───┬───┬───┬───┐   ┌───┬───┬───┬───┐
     *   Q │ W │ E │ R │ T │   │ Y │ U │ I │ O │ ;
     * ┌───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┐
     * │ A │ S │ D │ F │ G │   │ H │ J │ K │ L │ P │
     * └───┼───┼───┼───┼───┘   └───┼───┼───┼───┼───┘
     *   Z │ X │ C │ V │ B       - │ M │ , │ . │ /
     *     └───┴───┼───┼───┐   ┌───┼───┼───┴───┘
     *             │ESC│SPC│   │ N │ENT│
     *             └───┴───┘   └───┴───┘
     */
    [_ALPHA] = LAYOUT(
                 KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,
       CTL_A,    ALT_S,   GUI_D,   SFT_F,   RALT_G,  RALT_H,  SFT_J,   GUI_K,   ALT_L,   CTL_P,
                 KC_X,    KC_C,    KC_V,                      KC_M,    KC_COMM, KC_DOT,
                                   NUM_ESC, NAV_SPC, SYM_KCN, FUN_ENT
    ),
    [_NUM] = LAYOUT(
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PLUS, KC_7,    KC_8,    KC_9,
        KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX, KC_MINS, KC_4,    KC_5,    KC_6,    KC_SLASH,
                 XXXXXXX, XXXXXXX, XXXXXXX,                   KC_1,    KC_2,    KC_3,
                                   _______, _______, KC_E,    KC_0
    ),
    [_NAV] = LAYOUT(
                 XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, KC_BSPC, KC_DEL,  KC_INS,
        KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_MUTE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TAB,
                 XXXXXXX, XXXXXXX, XXXXXXX,                   KC_HOME, XXXXXXX, KC_END,
                                   _______, _______, _______, _______
    ),
    [_SYM] = LAYOUT(
                 KC_GRV,  KC_DQT,  KC_MDOT, KC_LBRC, KC_RBRC, KC_BSLS, KC_PIPE, KC_LT,
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_AMPR, KC_ASTR, KC_PERC, KC_CIRC,
                 KC_TILD, KC_QUOT, KC_UNDS,                   KC_MINS, KC_PLUS, KC_EQL,
                                   _______, KC_LSFT, _______, _______
    ),
    [_FUN] = LAYOUT(
                 QK_BOOT, _______, _______, _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,
        _______, _______, _______, _______, _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_F10,
                 _______, _______, _______,                   KC_F1,   KC_F2,   KC_F3,
                                   _______, _______, _______, _______
    )
};
