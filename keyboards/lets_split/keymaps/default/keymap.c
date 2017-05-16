#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"
#ifdef RGBLIGHT_ENABLE
  #include "rgblight.h"
#endif

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Tab  |Lower |Enter |Space |Raise | Esc  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 *                              CTL    LSFT           Super
 */
[_QWERTY] = KEYMAP( \
  KC_Q, KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  KC_A, KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_BSPC, \
  KC_Z, KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  ALT_T(KC_SLSH), \
                 KC_TAB, LOWER,   CTL_T(KC_ENT), MT(MOD_LSFT, KC_SPC), RAISE,   GUI_T(KC_ESC)  \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Lower | Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = KEYMAP( \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
                    KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_DOWN  \
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Lower | Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = KEYMAP( \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
                    KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_DOWN  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   \  |   '  |  -   |  =   |  [   |   ]  | Down |  Up  | Left |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Lock |   `  |  ~   |      |Paste |Delete| PgUP | PgDn | Home | End  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,     KC_PERC,  KC_CIRC,   KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN, \
  KC_BSLS, KC_QUOT, KC_MINS, KC_EQL,     KC_LBRC,  KC_RBRC,   KC_DOWN, KC_UP,   KC_LEFT,  KC_RIGHT,   \
  M(6)   ,  KC_GRV,  KC_TILD, _______, M(1),   KC_DELETE, KC_PGUP, KC_PGDN, KC_HOME,  KC_END,   \
                    _______, _______,    _______,  _______,   _______, _______  \
),   

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   |  |  "   |   _  |  +   |  {   |   }  |   4  |   5  |   6  |Shift |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Vol- | Vol+ | Mute |      |  ;   |   :  |   1  |   2  |   3  |CTLALT|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_1,    KC_2,    KC_3,         KC_4,         KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,           \
  KC_PIPE, KC_DQT , KC_UNDS,      KC_PLUS,      KC_LCBR, KC_RCBR, KC_4,    KC_5,    KC_6,    KC_LSFT,    \
  KC_VOLD, KC_VOLU, KC_MUTE,      _______,      KC_SCLN, KC_COLN, KC_1,    KC_2,    KC_3,    M(7), \
                    _______,      _______,      _______, _______, _______, _______                           \
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |  A0  |  A1  |  A2  |      |      |  WU  |  LC  |  Up  |  RC  | FWD  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  CAL |  CAR |  CPU | CPD  |      |  WD  | Left | Down |Right | RFSH |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |  PU  |  PD  |      |  CAD |  WL  |   MC |   WR |  BK  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = KEYMAP( \
  KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, _______,       _______, KC_WH_U,            KC_BTN1,       KC_MS_U,    KC_BTN2,    KC_WFWD,                \
  M(3),      M(2),      M(4),      M(5),       _______, KC_WH_D,            KC_MS_L,       KC_MS_D,    KC_MS_R,    KC_WWW_REFRESH,         \
  RGB_SAI,      RGB_SAD,      KC_PGUP,      KC_PGDN,       _______, LALT(LCTL(KC_DEL)), KC_WH_L,       KC_BTN3,    KC_WH_R,    KC_WBAK, \
                              _______,      _______,       _______, _______, _______, _______                           \
),


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_colemak, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) // this is the function signature -- just copy/paste it into your keymap file as it is.
{
  switch(id) {
    case 0: // this would trigger when you hit a key mapped as M(0)
      if (record->event.pressed) {
        return MACRO( D(LALT), D(TAB), U(TAB), U(LALT), END  ); // Alt Tab
      }
    case 1: // this would trigger when you hit a key mapped as M(1)
      if (record->event.pressed) {
        return MACRO( D(LSFT), D(LCTL), D(INS), U(INS), U(LCTL), U(LSFT), END  ); // control shift insert
      }
    case 2: // this would trigger when you hit a key mapped as M(2)
      if (record->event.pressed) {
        return MACRO( D(LALT), D(LCTL), D(RIGHT), U(RIGHT), U(LCTL), U(LALT), END  ); // control alt right
      }
    case 3: // this would trigger when you hit a key mapped as M(3)
      if (record->event.pressed) {
        return MACRO( D(LALT), D(LCTL), D(LEFT), U(LEFT), U(LCTL), U(LALT), END  ); // control alt left
      }
    case 4: // this would trigger when you hit a key mapped as M(4)
      if (record->event.pressed) {
        return MACRO( D(LCTL), D(PGUP), U(PGUP), U(LCTL), END  ); // control page up
      }
    case 5: // this would trigger when you hit a key mapped as M(5)
      if (record->event.pressed) {
        return MACRO( D(LCTL), D(PGDOWN), U(PGDOWN), U(LCTL), END  ); // control page down
      }
    case 6: // this would trigger when you hit a key mapped as M(6)
      if (record->event.pressed) {
        return MACRO( D(LCTL), D(LALT), D(L), U(L), U(LALT), U(LCTL), END  ); // control alt l
      }    
    case 7: // this would trigger when you hit a key mapped as M(7)
      if (record->event.pressed) {
        return MACRO( D(LCTL), D(LALT), U(LALT), U(LCTL), END  ); // control alt
      }
    break;
  }
  return MACRO_NONE;
};
