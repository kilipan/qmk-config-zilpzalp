#ifndef APTMAK_HRM_COMBOS_H
#define APTMAK_HRM_COMBOS_H


enum layers {
    _QWERTY,
    _APTMAK,
    _COLEMAK,
    _NUM,
    _NAV,
    _SYM,
    _FUN
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    APTMAK,
    COLEMAK,
    NUM,
    NAV,
    SYM,
    FUN,
    KC_MDOT,
    KC_SCH
};

// LEFT HAND HOME ROW MODS
#define HRM_R MT(MOD_LCTL, KC_R)
#define HRM_S MT(MOD_LALT, KC_S)
#define HRM_T MT(MOD_LGUI, KC_T)
#define HRM_H MT(MOD_LSFT, KC_H)
#define HRM_K MT(MOD_RALT, KC_K)
// RIGHT HAND HOME ROW MODS
#define HRM_X MT(MOD_RALT, KC_X)
#define HRM_N MT(MOD_RSFT, KC_N)
#define HRM_A MT(MOD_RGUI, KC_A)
#define HRM_I MT(MOD_LALT, KC_I)
#define HRM_O MT(MOD_RCTL, KC_O)
// LAYER TAP BEHAVIORS
#define NUM_ESC LT(_NUM, KC_ESC)
#define NAV_SPC LT(_NAV, KC_SPC)
// #define SYM_ENT LT(_SYM, KC_ENT)
#define SYM_KCE LT(_SYM, KC_E)
// #define FUN_BSP LT(_FUN, KC_BSPC)
#define FUN_ENT LT(_FUN, KC_ENT)
// #define FUN_KCE LT(_FUN, KC_E)
// OTHER
#define KC_MDOT LSFT(RALT(KC_SCLN))
// flexibility
#define QWERTY DF(_QWERTY)
#define APTMAK DF(_APTMAK)
#define COLEMAK DF(_COLEMAK)
// combos
enum combo_events {
    // "alpha"
    Q_COMBO,
    Z_COMBO,
    V_COMBO,
    SCH_COMBO,
    SLASH_COMBO,
    MINUS_COMBO,
    ENTER_COMBO,
    // parentheticals
    L_CBR_COMBO,
    L_PRN_COMBO,
    L_BRC_COMBO,
    L_ABK_COMBO,
    R_CBR_COMBO,
    R_PRN_COMBO,
    R_BRC_COMBO,
    R_ABK_COMBO,
    // caps
    CAPSWORD_COMBO,
    CAPSLOCK_COMBO,
    // deletion
    BSPC_COMBO,
    DELW_COMBO,
    DEL_COMBO,
    // base keymap
    APTMAK_COMBO,
    COLEMAK_COMBO,
    QWERTY_COMBO,
    // missing colemak/qwerty alphas
    CQ_V_COMBO,
    CQ_J_COMBO,
    // convenience
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;
// alphas usually on base
const uint16_t PROGMEM q_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM z_combo[] = {KC_C, KC_G, COMBO_END};
const uint16_t PROGMEM v_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM sch_combo[] = {KC_W, KC_P, COMBO_END};
const uint16_t PROGMEM slash_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM minus_combo[] = {KC_G, KC_D, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_M, KC_COMMA, COMBO_END};
// parentheticals
const uint16_t PROGMEM l_cbr_combo[] = {KC_W, HRM_S, COMBO_END};
const uint16_t PROGMEM l_prn_combo[] = {KC_F, HRM_T, COMBO_END};
const uint16_t PROGMEM l_brc_combo[] = {KC_P, HRM_H, COMBO_END};
const uint16_t PROGMEM l_abk_combo[] = {KC_B, HRM_K, COMBO_END};
const uint16_t PROGMEM r_cbr_combo[] = {KC_Y, HRM_I, COMBO_END};
const uint16_t PROGMEM r_prn_combo[] = {KC_U, HRM_A, COMBO_END};
const uint16_t PROGMEM r_brc_combo[] = {KC_L, HRM_N, COMBO_END};
const uint16_t PROGMEM r_abk_combo[] = {KC_J, HRM_X, COMBO_END};
// caps
const uint16_t PROGMEM capsword_combo[] = {HRM_H, HRM_N, COMBO_END};
const uint16_t PROGMEM capslock_combo[] = {KC_W, KC_Y, COMBO_END};
// deletion
const uint16_t PROGMEM bspc_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM delw_combo[] = {KC_L, KC_Y, COMBO_END};
const uint16_t PROGMEM del_combo[] =  {KC_U, KC_Y, COMBO_END};
// base keymap
const uint16_t PROGMEM qwerty_combo[] =  {KC_W, KC_F, KC_P, KC_L, KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM aptmak_combo[] =  {HRM_S, HRM_T, HRM_A, HRM_I, COMBO_END};
const uint16_t PROGMEM colemak_combo[] =  {KC_C, KC_G, KC_D, KC_M, KC_COMMA, KC_DOT, COMBO_END};
// missing colemak/qwerty alphas
const uint16_t PROGMEM cq_v_combo[] = {KC_D, HRM_K, COMBO_END};
const uint16_t PROGMEM cq_j_combo[] = {KC_J, KC_L, COMBO_END};


combo_t key_combos[] = {
    // alphas usually on base
    [Q_COMBO] = COMBO(q_combo, KC_Q),
    [Z_COMBO] = COMBO(z_combo, KC_Z),
    [V_COMBO] = COMBO(v_combo, KC_V),
    [SCH_COMBO] = COMBO(sch_combo, KC_SCH),
    [SLASH_COMBO] = COMBO(slash_combo, KC_SLASH),
    [MINUS_COMBO] = COMBO(minus_combo, KC_MINUS),
    [ENTER_COMBO] = COMBO(enter_combo, KC_ENTER),
    // parentheticals
    [L_BRC_COMBO] = COMBO(l_brc_combo, KC_LBRC),
    [L_PRN_COMBO] = COMBO(l_prn_combo, KC_LPRN),
    [L_CBR_COMBO] = COMBO(l_cbr_combo, KC_LCBR),
    [L_ABK_COMBO] = COMBO(l_abk_combo, KC_LABK),
    [R_BRC_COMBO] = COMBO(r_brc_combo, KC_RBRC),
    [R_PRN_COMBO] = COMBO(r_prn_combo, KC_RPRN),
    [R_CBR_COMBO] = COMBO(r_cbr_combo, KC_RCBR),
    [R_ABK_COMBO] = COMBO(r_abk_combo, KC_RABK),
    // caps
    [CAPSWORD_COMBO] = COMBO(capsword_combo, CW_TOGG),
    [CAPSLOCK_COMBO] = COMBO(capslock_combo, KC_CAPS),
    // deletion
    [BSPC_COMBO] = COMBO(bspc_combo, KC_BSPC),
    [DELW_COMBO] = COMBO(delw_combo, C(KC_BSPC)),
    [DEL_COMBO] = COMBO(del_combo, KC_DEL),
    // base keymap
    [QWERTY_COMBO] = COMBO(qwerty_combo, QWERTY),
    [APTMAK_COMBO] = COMBO(aptmak_combo, APTMAK),
    [COLEMAK_COMBO] = COMBO(colemak_combo, COLEMAK),
    // missing colemak/qwerty alphas
    [CQ_V_COMBO] = COMBO(cq_v_combo, KC_V),
    [CQ_J_COMBO] = COMBO(cq_j_combo, KC_J),
};


#endif//APTMAK_HRM_COMBOS_H
