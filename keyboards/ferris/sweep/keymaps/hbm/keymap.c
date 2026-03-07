#include QMK_KEYBOARD_H

// Module headers.

#include "conditional_layers.h"
#include "custom_keys.h"

// Define layers.

enum {
  LAYER_BS,
  LAYER_BS_LX,
  LAYER_BS_RX,
  LAYER_SM_L,
  LAYER_SM_LX,
  LAYER_SM_R,
  LAYER_SM_RX,
  LAYER_NM_L,
  LAYER_NM_LX,
  LAYER_NV_R,
  LAYER_NV_RX,
  LAYER_FN_L,
  LAYER_FN_LX,
  LAYER_CT_R,
  LAYER_MD_L,
  LAYER_MD_R
};

// Define keycodes for primary layers.

#define LT_RS LT(LAYER_SM_R,  KC_R)
#define LT_RN LT(LAYER_NV_R,  KC_S)
#define LT_RX LT(LAYER_BS_RX, KC_T)
#define LT_LX LT(LAYER_BS_LX, KC_N)
#define LT_LN LT(LAYER_NM_L,  KC_E)
#define LT_LS LT(LAYER_SM_L,  KC_I)
#define LT_LM LT(LAYER_MD_L, KC_SPC)
#define LT_RM LT(LAYER_MD_R, KC_ENT)

// Layer masks for conditional layers.

#define MASK_NM_LX (LAYER_BIT(LAYER_NM_L) | LAYER_BIT(LAYER_BS_LX))
#define MASK_NV_RX (LAYER_BIT(LAYER_NV_R) | LAYER_BIT(LAYER_BS_RX))
#define MASK_SM_LX (LAYER_BIT(LAYER_SM_L) | LAYER_BIT(LAYER_BS_LX))
#define MASK_SM_RX (LAYER_BIT(LAYER_SM_R) | LAYER_BIT(LAYER_BS_RX))
#define MASK_FN_L  (LAYER_BIT(LAYER_SM_L) | LAYER_BIT(LAYER_NM_L))
#define MASK_FN_LX (LAYER_BIT(LAYER_SM_L) | LAYER_BIT(LAYER_NM_L) | LAYER_BIT(LAYER_BS_LX))
#define MASK_CT_R  (LAYER_BIT(LAYER_SM_R) | LAYER_BIT(LAYER_NV_R))

// Add conditional layers.

void add_conditional_layers() {

  // Add the extended number layer, extended nav layer and both extended symbol
  // layers as conditional layers.

  set_conditional_layer_mask(LAYER_NM_LX, MASK_NM_LX);
  set_conditional_layer_mask(LAYER_NV_RX, MASK_NV_RX);
  set_conditional_layer_mask(LAYER_SM_LX, MASK_SM_LX);
  set_conditional_layer_mask(LAYER_SM_RX, MASK_SM_RX);

  // Add the function layer and its extended layer as conditional layers.

  set_conditional_layer_mask(LAYER_FN_L,  MASK_FN_L);
  set_conditional_layer_mask(LAYER_FN_LX, MASK_FN_LX);

  // Add the controls layer as a conditional layer.

  set_conditional_layer_mask(LAYER_CT_R,  MASK_CT_R);
};

// Keymap.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LAYER_BS] = LAYOUT_split_3x5_2(
KC_NO,  KC_W,  KC_F,  KC_P,  KC_B, KC_J, KC_L,  KC_U,    KC_BSPC, KC_NO,
KC_A,   LT_RS, LT_RN, LT_RX, KC_G, KC_M, LT_LX, LT_LN,   LT_LS,   KC_O,
KC_Z,   KC_X,  KC_C,  KC_D,  KC_V, KC_K, KC_H,  KC_COMM, KC_DOT,  KC_SLSH,
KC_TAB, LT_LM, LT_RM, KC_ESC
),
[LAYER_BS_LX] = LAYOUT_split_3x5_2(
KC_NO,   KC_Q,    KC_NO,   KC_B,   KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
KC_NO,   KC_A,    KC_TAB,  KC_G,   KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
KC_NO,   KC_Z,    A_ST,    KC_V,   KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[LAYER_BS_RX] = LAYOUT_split_3x5_2(
KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_J, KC_NO,  KC_Y,    KC_NO,
KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_M, KC_ESC, KC_O,    KC_NO,
KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_K, CK_VC,  KC_SLSH, KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[LAYER_SM_L] = LAYOUT_split_3x5_2(
KC_NO, KC_EXLM, CK_AT,   KC_DLR,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
KC_NO, CK_TILD, KC_LPRN, KC_LCBR, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
KC_NO, CK_GRV,  KC_LPRN, KC_RCBR, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[LAYER_SM_LX] = LAYOUT_split_3x5_2(
KC_NO,   KC_GRV,  KC_HASH, KC_PERC, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
KC_NO,   KC_NO,   KC_NO,   KC_LBRC, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
KC_NO,   KC_NO,   KC_NO,   KC_RBRC, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[LAYER_SM_R] = LAYOUT_split_3x5_2(
KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_AMPR, KC_ASTR, KC_DEL,  KC_NO,
KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_COLN, CK_DQUO, CK_PIPE, KC_NO,
KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_SCLN, KC_QUOT, CK_BSLS, KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[LAYER_SM_RX] = LAYOUT_split_3x5_2(
KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_CIRC, KC_UNDS, KC_PLUS, KC_NO,
KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO,   KC_MINS, KC_EQL,  KC_NO,
KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[LAYER_NM_L] = LAYOUT_split_3x5_2(
KC_NO,   KC_1,    KC_2,    KC_3,   KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
KC_DOT,  KC_4,    KC_5,    KC_6,   KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
KC_NO,   KC_7,    KC_8,    KC_9,   KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[LAYER_NM_LX] = LAYOUT_split_3x5_2(
KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
KC_NO,   KC_SLSH, KC_DOT,  KC_0,   KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[LAYER_NV_R] = LAYOUT_split_3x5_2(
KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, W_PT,    KC_UP,   W_NT,     KC_NO,
KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, P_QA,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO,
KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, P_AT,  AT_PWIN, CK_SS,   AT_NWIN,  KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[LAYER_NV_RX] = LAYOUT_split_3x5_2(
KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, W_PD,    KC_PGUP, W_ND,   KC_NO,
KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_HOME, KC_PGDN, KC_END, KC_NO,
KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,  KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[LAYER_FN_L] = LAYOUT_split_3x5_2(
KC_NO,   KC_F1,   KC_F2,   KC_F3,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
KC_NO,   KC_F4,   KC_F5,   KC_F6,  KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
KC_NO,   KC_F7,   KC_F8,   KC_F9,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[LAYER_FN_LX] = LAYOUT_split_3x5_2(
KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
KC_NO,   KC_F10,  KC_F11,  KC_F12, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[LAYER_CT_R] = LAYOUT_split_3x5_2(
KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_MUTE, KC_MPLY, KC_PSCR, KC_NO,
KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_VOLU, KC_MNXT, KC_BRIU, KC_NO,
KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_VOLD, KC_MPRV, KC_BRID, KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[LAYER_MD_L] = LAYOUT_split_3x5_2(
KC_NO,   KC_NO,   DM_RGUI, KC_NO,   KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_NO,   DM_RALT, DM_RCTL, DM_RSFT, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_NO,   A_CX,    A_CC,    A_CV,    KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, CW_TOGG, KC_TRNS
),
[LAYER_MD_R] = LAYOUT_split_3x5_2(
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO,   DM_LGUI, KC_NO,   KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, DM_LSFT, DM_LCTL, DM_LALT, KC_NO,
KC_TRNS, A_CX,    A_CC,    A_CV,    KC_TRNS, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
KC_TRNS, CW_TOGG, KC_TRNS, KC_TRNS
)
};
