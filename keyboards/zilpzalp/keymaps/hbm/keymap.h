// Copyright 2026 Hannah Blythe Morrison
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include QMK_KEYBOARD_H

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

  // Modifier layers go last so that key presses on their transparent other
  // side will fall through to any other active layer.

  LAYER_MD_L,
  LAYER_MD_R
};

// Aliases for cut, copy and paste.

#define A_CX RCTL(KC_X)
#define A_CC RCTL(KC_C)
#define A_CV RCTL(KC_V)

// Aliases for modified keys and UK symbols (backslash and pipe).

#define A_ST S(KC_TAB)
#define A_BS KC_NUBS
#define A_PP S(KC_NUBS)

// 1Password shortcut for quick access.

#define A_QA C(S(KC_SPC))

// Aliases for Windows previous and next tab / window / desktop.

#define W_PT C(S(KC_TAB))
#define W_NT C(KC_TAB)
#define W_PD C(G(KC_LEFT))
#define W_ND C(G(KC_RIGHT))

// Layer keycodes. The other extended layers, function and controls layers are
// accessed by pressing combinations of layer key presses, as conditional
// layers.

#define LT_RS LT(LAYER_SM_R,  KC_R)
#define LT_RN LT(LAYER_NV_R,  KC_S)
#define LT_RX LT(LAYER_BS_RX, KC_T)
#define LT_LX LT(LAYER_BS_LX, KC_N)
#define LT_LN LT(LAYER_NM_L,  KC_E)
#define LT_LS LT(LAYER_SM_L,  KC_I)

// Modifier layers are toggled.

#define LT_LM LT(LAYER_MD_L, KC_SPC)
#define LT_RM LT(LAYER_MD_R, KC_ENT)
