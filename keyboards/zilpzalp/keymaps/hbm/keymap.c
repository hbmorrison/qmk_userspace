#include QMK_KEYBOARD_H

#include "conditional_layers.h"

#include "keymap.h"

// Layer masks for conditional layers.

#define MASK_NM_LX (LAYER_BIT(LAYER_NM_L) | LAYER_BIT(LAYER_BS_LX))
#define MASK_SM_LX (LAYER_BIT(LAYER_SM_L) | LAYER_BIT(LAYER_BS_LX))

#define MASK_FN_L  (LAYER_BIT(LAYER_SM_L) | LAYER_BIT(LAYER_NM_L))
#define MASK_FN_LX (LAYER_BIT(LAYER_SM_L) | LAYER_BIT(LAYER_NM_L) | LAYER_BIT(LAYER_BS_LX))

#define MASK_NV_RX (LAYER_BIT(LAYER_NV_R) | LAYER_BIT(LAYER_BS_RX))
#define MASK_SM_RX (LAYER_BIT(LAYER_SM_R) | LAYER_BIT(LAYER_BS_RX))

#define MASK_CT_R  (LAYER_BIT(LAYER_SM_R) | LAYER_BIT(LAYER_NV_R))

// Define the base keymap for zilpzalp.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BS] = LAYOUT(
        KC_W,  KC_F,  KC_P,   KC_B,  KC_J,  KC_L,  KC_U,    KC_BSPC,
  KC_A, LT_RS, LT_RN, LT_RX,  KC_G,  KC_M,  LT_LX, LT_LN,   LT_LS,   KC_O,
        KC_X,  KC_C,  KC_D,                 KC_H,  KC_COMM, KC_DOT,
                      KC_NO,  LT_LM, LT_RM, KC_NO
  ),
  [LAYER_BS_LX] = LAYOUT(
         KC_Q, KC_NO,  KC_B,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO, KC_A, KC_TAB, KC_G,    KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
         KC_Z, A_ST,   KC_V,                      KC_NO,   KC_NO,   KC_NO,
                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [LAYER_BS_RX] = LAYOUT(
           KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_J,   KC_NO,  KC_Y,
  KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_M,   KC_ESC, KC_O,    KC_NO,
           KC_NO,   KC_NO,   KC_NO,                     KC_K,   CK_VC,  KC_SLSH,
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [LAYER_SM_L] = LAYOUT(
         KC_EXLM, KC_AT,   KC_DLR,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO, A_PP,    KC_LPRN, KC_LCBR, KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
         A_BS,    KC_LPRN, KC_RCBR,                   KC_NO,   KC_NO,   KC_NO,
                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [LAYER_SM_LX] = LAYOUT(
         KC_GRV, KC_HASH, KC_PERC, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO, KC_NO,  KC_NO,   KC_LBRC, KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
         KC_NO,  KC_NO,   KC_RBRC,                   KC_NO,   KC_NO,   KC_NO,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [LAYER_SM_R] = LAYOUT(
         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_AMPR, KC_ASTR, KC_DEL,
  KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_COLN, KC_DQUO, KC_PIPE, KC_NO,
         KC_NO,   KC_NO,   KC_NO,                     KC_SCLN, KC_QUOT, KC_BSLS,
                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [LAYER_SM_RX] = LAYOUT(
         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_CIRC, KC_UNDS, KC_PLUS,
  KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_MINS, KC_EQL,  KC_NO,
         KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,
                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [LAYER_NM_L] = LAYOUT(
          KC_1, KC_2, KC_3,    KC_SLSH, KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_DOT, KC_4, KC_5, KC_6,    KC_0,    KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
          KC_7, KC_8, KC_9,                      KC_NO,   KC_NO,   KC_NO,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [LAYER_NM_LX] = LAYOUT(
         KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO, KC_SLSH, KC_DOT, KC_0,    KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
         KC_NO,   KC_NO,  KC_NO,                     KC_NO,   KC_NO,   KC_NO,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [LAYER_NV_R] = LAYOUT(
         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   W_PT,    KC_UP,   W_NT,
  KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO,
         KC_NO,   KC_NO,   KC_NO,                     AT_PWIN, CK_SS,   AT_NWIN,
                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [LAYER_NV_RX] = LAYOUT(
         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   W_PD,    KC_PGUP, W_ND,
  KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_HOME, KC_PGDN, KC_END, KC_NO,
         KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,
                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [LAYER_FN_L] = LAYOUT(
         KC_F1, KC_F2, KC_F3,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
  KC_NO, KC_F4, KC_F5, KC_F6,   KC_NO,   KC_NO,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_NO,
         KC_F7, KC_F8, KC_F9,                     KC_NO,    KC_NO,   KC_NO,
                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [LAYER_FN_LX] = LAYOUT(
         KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO, KC_F10, KC_F11, KC_F12,  KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
         KC_NO,  KC_NO,  KC_NO,                     KC_NO,   KC_NO,   KC_NO,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [LAYER_CT_R] = LAYOUT(
         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MUTE, KC_MPLY, KC_PSCR,
  KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_VOLU, KC_MNXT, KC_BRIU, KC_NO,
         KC_NO,   KC_NO,   KC_NO,                     KC_VOLD, KC_MPRV, KC_BRID,
                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [LAYER_MD_L] = LAYOUT(
         KC_NO,   DM_LGUI, KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_NO, DM_LALT, DM_LCTL, DM_LSFT, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
         KC_NO,   KC_NO,   KC_NO,                     KC_TRNS, KC_TRNS, KC_TRNS,
                           KC_TRNS, KC_TRNS, CW_TOGG, KC_TRNS
  ),
  [LAYER_MD_R] = LAYOUT(
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   DM_RGUI, KC_NO,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   DM_RSFT, DM_RCTL, DM_RALT, KC_NO,
           A_CX,    A_CC,    A_CV,                      KC_NO,   KC_NO,   KC_NO,
                             KC_TRNS, CW_TOGG, KC_TRNS, KC_TRNS
  )
};

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
