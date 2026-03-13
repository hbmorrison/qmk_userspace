// Module headers.

#include "core_keymap.h"
#include "custom_keys.h"
#include "handed_mods.h"

// Tell the handed mods module to ignore thumb keys.

bool handed_mods_is_ignored_key(uint16_t keycode) {
  switch (keycode) {
    case LT_NUM:
    case LT_NAV:
    case LT_LEXT:
    case LT_REXT:
      return true;
  }
  return false;
}

// Tell the handed mods module which side of the keyboard the given key position
// is on. On the zilpzalp keyboard, keys on the left side are on even rows on
// the matrix, and keys on the right side are on odd rows on the matrix.

bool handed_mods_is_left_key(keypos_t key) {
  return key.row % 2 == 0;
}

// Define the keymap.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_zilpzalp(
    /**/           CORE_BASE_TL,   CORE_BASE_IT, CORE_BASE_TR,
    CORE_BASE_OML, HANDED_BASE_ML, CORE_BASE_IM, HANDED_BASE_MR, CORE_BASE_OMR,
    /**/           CORE_BASE_BL,   /**/          CORE_BASE_BR,
    /**/           CORE_BASE_THL,  CORE_BASE_TH, CORE_BASE_THR
  ),
  [LAYER_LEXT] = LAYOUT_zilpzalp(
    /**/           CORE_EXT_TL,  CORE_FILL_IT, CORE_FILL_TR,
    CORE_FILL_OML, CORE_EXT_ML,  CORE_FILL_IM, CORE_FILL_MR, CORE_FILL_OMR,
    /**/           CORE_EXT_BL,  /**/          CORE_FILL_BR,
    /**/           CORE_EXT_THL, CORE_LEXT_TH, CORE_FILL_THR
  ),
  [LAYER_REXT] = LAYOUT_zilpzalp(
    /**/           CORE_FILL_TL,  CORE_FILL_IT, CORE_EXT_TR,
    CORE_FILL_OML, CORE_FILL_ML,  CORE_FILL_IM, CORE_EXT_MR,  CORE_FILL_OMR,
    /**/           CORE_FILL_BL,  /**/          CORE_EXT_BR,
    /**/           CORE_FILL_THL, CORE_REXT_TH, CORE_EXT_THR
  ),
  [LAYER_LSYM] = LAYOUT_zilpzalp(
    /**/          CORE_SYM_TL,   CORE_LSYM_IT, CORE_FILL_TR,
    CORE_SYM_OML, CORE_SYM_ML,   CORE_LSYM_IM, CORE_FILL_MR, CORE_FILL_OMR,
    /**/          CORE_SYM_BL,   /**/          CORE_FILL_BR,
    /**/          CORE_FILL_THL, CORE_FILL_TH, CORE_FILL_THR
  ),
  [LAYER_LSYM_EXT] = LAYOUT_zilpzalp(
    /**/           CORE_SYM_EXT_TL, CORE_FILL_IT, CORE_FILL_TR,
    CORE_FILL_OML, CORE_SYM_EXT_ML, CORE_FILL_IM, CORE_FILL_MR, CORE_FILL_OMR,
    /**/           CORE_SYM_EXT_BL, /**/          CORE_FILL_BR,
    /**/           CORE_FILL_THL,   CORE_FILL_TH, CORE_FILL_THR
  ),
  [LAYER_RSYM] = LAYOUT_zilpzalp(
    /**/           CORE_FILL_TL,  CORE_RSYM_IT, CORE_SYM_TR,
    CORE_FILL_OML, CORE_FILL_ML,  CORE_RSYM_IM, CORE_SYM_MR,  CORE_SYM_OMR,
    /**/           CORE_FILL_BL,  /**/          CORE_SYM_BR,
    /**/           CORE_FILL_THL, CORE_FILL_TH, CORE_FILL_THR
  ),
  [LAYER_RSYM_EXT] = LAYOUT_zilpzalp(
    /**/           CORE_FILL_TL,  CORE_FILL_IT, CORE_SYM_EXT_TR,
    CORE_FILL_OML, CORE_FILL_ML,  CORE_FILL_IM, CORE_SYM_EXT_MR, CORE_FILL_OMR,
    /**/           CORE_FILL_BL,  /**/          CORE_SYM_EXT_BR,
    /**/           CORE_FILL_THL, CORE_FILL_TH, CORE_FILL_THR
  ),
  [LAYER_NUM] = LAYOUT_zilpzalp(
    /**/          CORE_NUM_TL,   CORE_NUM_IT,  CORE_FILL_TR,
    CORE_NUM_OML, CORE_NUM_ML,   CORE_NUM_IM,  CORE_FILL_MR, CORE_FILL_OMR,
    /**/          CORE_NUM_BL,   /**/          CORE_FILL_BR,
    /**/          CORE_FILL_THL, CORE_FILL_TH, CORE_FILL_THR
  ),
  [LAYER_NUM_EXT] = LAYOUT_zilpzalp(
    /**/           CORE_NUM_EXT_TL, CORE_FILL_IT, CORE_FILL_TR,
    CORE_FILL_OML, CORE_NUM_EXT_ML, CORE_FILL_IM, CORE_FILL_MR, CORE_FILL_OMR,
    /**/           CORE_NUM_EXT_BL, /**/          CORE_FILL_BR,
    /**/           CORE_FILL_THL,   CORE_FILL_TH, CORE_FILL_THR
  ),
  [LAYER_NAV] = LAYOUT_zilpzalp(
    /**/           CORE_FILL_TL,  CORE_NAV_IT, CORE_NAV_TR,
    CORE_FILL_OML, CORE_FILL_ML,  CORE_NAV_IM, CORE_NAV_MR,  CORE_NAV_OMR,
    /**/           CORE_FILL_BL,  /**/         CORE_NAV_BR,
    /**/           CORE_FILL_THL, CORE_FILL_TH, CORE_FILL_THR
  ),
  [LAYER_NAV_EXT] = LAYOUT_zilpzalp(
    /**/           CORE_FILL_TL,  CORE_FILL_IT, CORE_NAV_EXT_TR,
    CORE_FILL_OML, CORE_FILL_ML,  CORE_FILL_IM, CORE_NAV_EXT_MR, CORE_FILL_OMR,
    /**/           CORE_FILL_BL,  /**/          CORE_NAV_EXT_BR,
    /**/           CORE_FILL_THL, CORE_FILL_TH, CORE_FILL_THR
  ),
  [LAYER_FUNC] = LAYOUT_zilpzalp(
    /**/           CORE_FUNC_TL,  CORE_FUNC_IT, CORE_FILL_TR,
    CORE_FUNC_OML, CORE_FUNC_ML,  CORE_FUNC_IM, CORE_FILL_MR, CORE_FILL_OMR,
    /**/           CORE_FUNC_BL,  /**/          CORE_FILL_BR,
    /**/           CORE_FILL_THL, CORE_FILL_TH, CORE_FILL_THR
  ),
  [LAYER_FUNC_EXT] = LAYOUT_zilpzalp(
    /**/           CORE_FUNC_EXT_TL, CORE_FILL_IT, CORE_FILL_TR,
    CORE_FILL_OML, CORE_FUNC_EXT_ML, CORE_FILL_IM, CORE_FILL_MR, CORE_FILL_OMR,
    /**/           CORE_FUNC_EXT_BL, /**/          CORE_FILL_BR,
    /**/           CORE_FILL_THL,    CORE_FILL_TH, CORE_FILL_THR
  ),
  [LAYER_CTLS] = LAYOUT_zilpzalp(
    /**/           CORE_FILL_TL,  CORE_CTLS_IT, CORE_CTLS_TR,
    CORE_FILL_OML, CORE_FILL_ML,  CORE_CTLS_IM, CORE_CTLS_MR, CORE_CTLS_OMR,
    /**/           CORE_FILL_BL,  /**/          CORE_CTLS_BR,
    /**/           CORE_FILL_THL, CORE_FILL_TH, CORE_FILL_THR
  ),
  [LAYER_LMOD] = LAYOUT_zilpzalp(
    /**/           CORE_TRNS_TL,  CORE_TRNS_ITR, HANDED_MOD_TR,
    CORE_TRNS_OML, CORE_TRNS_ML,  CORE_TRNS_IMR, HANDED_MOD_MR, HANDED_MOD_OMR,
    /**/           CORE_TRNS_BL,  /**/           HANDED_MOD_BR,
    /**/           CORE_FILL_THL, CORE_FILL_TH,  CORE_FILL_THR
  ),
  [LAYER_RMOD] = LAYOUT_zilpzalp(
    /**/            HANDED_MOD_TL, CORE_TRNS_ITL, CORE_TRNS_TR,
    HANDED_MOD_OML, HANDED_MOD_ML, CORE_TRNS_IML, CORE_TRNS_MR, CORE_TRNS_OMR,
    /**/            HANDED_MOD_BL, /**/           CORE_TRNS_BR,
    /**/            CORE_FILL_THL, CORE_FILL_TH,  CORE_FILL_THR
  )
};
