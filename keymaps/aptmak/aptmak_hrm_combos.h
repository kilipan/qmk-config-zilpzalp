#ifndef APTMAK_HRM_COMBOS_H
#define APTMAK_HRM_COMBOS_H


enum layers {
    _APTMAK,
    _NUM,
    _NAV,
    _SYM,
    _FUN
};

enum custom_keycodes {
    APTMAK = SAFE_RANGE,
    NUM,
    NAV,
    SYM,
    FUN,
    KC_MDOT,
    KC_SCH,
    KC_DELLINE
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
#define SYM_KCE LT(_SYM, KC_E)
#define FUN_ENT LT(_FUN, KC_ENT)
// OTHER
#define KC_MDOT LSFT(RALT(KC_SCLN))
// combos
enum combo_events {
    // "alpha"
    Q_COMBO,
    Z_COMBO,
    V_COMBO,
    SCH_COMBO,
    SLASH_COMBO,
    MINUS_COMBO,
    QUOT_COMBO,
    // parentheticals
    L_CBR_COMBO,
    L_BRC_COMBO,
    L_PRN_COMBO,
    L_ABK_COMBO,
    R_CBR_COMBO,
    R_BRC_COMBO,
    R_PRN_COMBO,
    R_ABK_COMBO,
    // caps
    CAPSWORD_COMBO,
    CAPSLOCK_COMBO,
    // deletion
    BSPC_COMBO,
    DELW_COMBO,
    DELLINE_COMBO,
    DEL_COMBO,
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
const uint16_t PROGMEM minus_combo[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM quot_combo[] = {KC_G, KC_D, COMBO_END};
// const uint16_t PROGMEM enter_combo[] = {KC_M, KC_COMMA, COMBO_END};
// parentheticals
const uint16_t PROGMEM l_cbr_combo[] = {KC_W, HRM_S, COMBO_END};
const uint16_t PROGMEM l_brc_combo[] = {KC_F, HRM_T, COMBO_END};
const uint16_t PROGMEM l_prn_combo[] = {KC_P, HRM_H, COMBO_END};
const uint16_t PROGMEM l_abk_combo[] = {KC_B, HRM_K, COMBO_END};
const uint16_t PROGMEM r_cbr_combo[] = {KC_Y, HRM_I, COMBO_END};
const uint16_t PROGMEM r_brc_combo[] = {KC_U, HRM_A, COMBO_END};
const uint16_t PROGMEM r_prn_combo[] = {KC_L, HRM_N, COMBO_END};
const uint16_t PROGMEM r_abk_combo[] = {KC_J, HRM_X, COMBO_END};
// caps
const uint16_t PROGMEM capsword_combo[] = {HRM_H, HRM_N, COMBO_END};
const uint16_t PROGMEM capslock_combo[] = {KC_W, KC_Y, COMBO_END};
// deletion
const uint16_t PROGMEM bspc_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM delw_combo[] = {KC_L, KC_Y, COMBO_END};
const uint16_t PROGMEM delline_combo[] = {KC_L, KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM del_combo[] =  {KC_U, KC_Y, COMBO_END};

combo_t key_combos[] = {
    // alphas usually on base
    [Q_COMBO] = COMBO(q_combo, KC_Q),
    [Z_COMBO] = COMBO(z_combo, KC_Z),
    [V_COMBO] = COMBO(v_combo, KC_V),
    [SCH_COMBO] = COMBO(sch_combo, KC_SCH),
    [SLASH_COMBO] = COMBO(slash_combo, KC_SLASH),
    [MINUS_COMBO] = COMBO(minus_combo, KC_MINUS),
    [QUOT_COMBO] = COMBO(quot_combo, KC_QUOT),
    // parentheticals
    [L_BRC_COMBO] = COMBO(l_brc_combo, KC_LBRC),
    [L_CBR_COMBO] = COMBO(l_cbr_combo, KC_LCBR),
    [L_PRN_COMBO] = COMBO(l_prn_combo, KC_LPRN),
    [L_ABK_COMBO] = COMBO(l_abk_combo, KC_LABK),
    [R_BRC_COMBO] = COMBO(r_brc_combo, KC_RBRC),
    [R_CBR_COMBO] = COMBO(r_cbr_combo, KC_RCBR),
    [R_PRN_COMBO] = COMBO(r_prn_combo, KC_RPRN),
    [R_ABK_COMBO] = COMBO(r_abk_combo, KC_RABK),
    // caps
    [CAPSWORD_COMBO] = COMBO(capsword_combo, CW_TOGG),
    [CAPSLOCK_COMBO] = COMBO(capslock_combo, KC_CAPS),
    // deletion
    [BSPC_COMBO] = COMBO(bspc_combo, KC_BSPC),
    [DELW_COMBO] = COMBO(delw_combo, C(KC_BSPC)),
    [DELLINE_COMBO] = COMBO(delline_combo, KC_DELLINE),
    [DEL_COMBO] = COMBO(del_combo, KC_DEL),
};


#endif//APTMAK_HRM_COMBOS_H
