/* -*- mode: c++ -*-
 * Atreus -- Chrysalis-enabled Sketch for the Keyboardio Atreus
 * Copyright (C) 2018, 2019  Keyboard.io, Inc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

#include "Kaleidoscope.h"
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-EEPROM-Keymap.h"
#include "Kaleidoscope-FocusSerial.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-OneShot.h"
#include "Kaleidoscope-Qukeys.h"
#include "Kaleidoscope-SpaceCadet.h"


enum {
  MACRO_QWERTY,
  MACRO_VERSION_INFO
};

#define Key_Exclamation LSHIFT(Key_1)
#define Key_At LSHIFT(Key_2)
#define Key_Hash LSHIFT(Key_3)
#define Key_Dollar LSHIFT(Key_4)
#define Key_Percent LSHIFT(Key_5)
#define Key_Caret LSHIFT(Key_6)
#define Key_And LSHIFT(Key_7)
#define Key_Star LSHIFT(Key_8)
#define Key_Plus LSHIFT(Key_Equals)

#define Key_Star LSHIFT(Key_8)
#define Key_Underscore LSHIFT(Key_Minus)
#define Key_LeftParenthesis LSHIFT(Key_9)
#define Key_RightParenthesis LSHIFT(Key_0)
#define Key_LeftBrace LSHIFT(Key_LeftBracket)
#define Key_RightBrace LSHIFT(Key_RightBracket)
#define Key_Less LSHIFT(Key_Comma)
#define Key_Greater LSHIFT(Key_Period)

enum {
  QWERTY,
  DIGITS,
  ARROWS,
  MOUSE,
  REPEAT,
  CODING
};

/* *INDENT-OFF* */
KEYMAPS(
  [QWERTY] = KEYMAP_STACKED
  (
       Key_Q   ,Key_W        ,LT(CODING, E) ,Key_R           ,Key_T
      ,Key_A   ,LT(MOUSE, S) ,LT(REPEAT, D) ,LT(ARROWS, F)   ,LT(DIGITS, G)
      ,Key_Z   ,Key_X        ,Key_C         ,Key_V           ,Key_B            ,Key_Backtick
      ,Key_Esc ,Key_Esc      ,Key_Tab       ,Key_LeftGui     ,CTL_T(Spacebar)  ,ALT_T(Backspace)

                       ,Key_Y         ,Key_U        ,LT(CODING, I) ,Key_O      ,Key_P
                       ,LT(DIGITS, H) ,CTL_T(J)     ,ALT_T(K)      ,Key_L      ,Key_Semicolon
       ,Key_Backslash  ,Key_N         ,Key_M        ,Key_Comma     ,Key_Period ,Key_Slash
       ,Key_Esc        ,SFT_T(Enter)  ,Key_RightGui ,Key_Minus     ,Key_Quote  ,Key_Enter
  ),

  [DIGITS] = KEYMAP_STACKED
  (
       Key_Exclamation ,Key_At           ,Key_Star      ,Key_KeypadDivide     ,Key_Less
      ,Key_Hash        ,Key_Dollar       ,Key_Plus      ,Key_Minus            ,___
      ,Key_Percent     ,Key_Caret        ,Key_Equals    ,Key_Exclamation      ,Key_Greater        ,___
      ,___             ,___              ,___           ,Key_Spacebar         ,Key_Delete         ,Key_Backspace

                   ,Key_0        ,Key_7     ,Key_8       ,Key_9 ,Key_Underscore
                   ,___          ,Key_4     ,Key_5       ,Key_6 ,Key_Exclamation
      ,Key_Star    ,Key_Slash    ,Key_1     ,Key_2       ,Key_3 ,Key_Equals
      ,Key_Plus    ,Key_Minus    ,Key_Enter ,Key_Period  ,Key_0 ,___
   ),

  [ARROWS] = KEYMAP_STACKED
  (
       ___                   ,___                      ,___           ,___            ,___
      ,___                   ,Key_LeftAlt              ,___           ,___            ,___
      ,___                   ,___                      ,___           ,___            ,___     , ___
      ,___                   ,___                      ,___           ,___            ,Key_Esc , ___

                ,___           ,Key_PageUp          ,Key_UpArrow     ,Key_Home       ,___
                ,Key_0         ,Key_LeftArrow       ,Key_DownArrow   ,Key_RightArrow ,Key_Dollar
      ,___      ,___           ,Key_PageDown        ,___             ,Key_End        ,___
      ,___      ,___           ,___                 ,___             ,___            ,___
   ),

  [MOUSE] = KEYMAP_STACKED
  (
       ___                   ,___                      ,___           ,___            ,___
      ,___                   ,___                      ,___           ,___            ,___
      ,___                   ,___                      ,___           ,___            ,___, ___
      ,___                   ,___                      ,___           ,___            ,___, ___

                ,___           ,Key_mouseBtnL       ,Key_mouseUp     ,Key_mouseBtnR  ,___
                ,___           ,Key_mouseL          ,Key_mouseDn     ,Key_mouseR     ,___
      ,___      ,___           ,___                 ,___             ,___            ,___
      ,___      ,___           ,___                 ,___             ,___            ,___
   ),

  [REPEAT] = KEYMAP_STACKED
  (
       ___                   ,___                      ,___           ,___            ,___
      ,___                   ,___                      ,___           ,Key_F          ,Key_G
      ,___                   ,___                      ,___           ,___            ,___          ,___
      ,___                   ,___                      ,___           ,___            ,Key_Spacebar ,Key_Backspace

                ,___           ,___                 ,Key_Tab         ,Key_Spacebar   ,___
                ,Key_H         ,Key_J               ,Key_Backspace   ,Key_Delete     ,___
      ,___      ,___           ,___                 ,___             ,___            ,___
      ,___      ,Key_Enter     ,___                 ,___             ,___            ,___
   ),

  [CODING] = KEYMAP_STACKED
  (
       ___                   ,___                      ,___           ,Key_LeftParenthesis ,___
      ,___                   ,___                      ,___           ,Key_LeftBrace       ,___
      ,___                   ,___                      ,___           ,Key_LeftBracket     ,___ , ___
      ,___                   ,___                      ,___           ,___                 ,___ , ___

                ,Key_LeftParenthesis ,Key_RightParenthesis ,Key_And            ,Key_Star              ,Key_Underscore
                ,Key_LeftBrace       ,Key_RightBrace       ,Key_Minus          ,Key_Period            ,Key_Equals
      ,___      ,Key_LeftBracket     ,Key_RightBracket     ,Key_Less           ,Key_Greater           ,Key_Dollar
      ,___      ,___                 ,___                  ,___                ,___                   ,___
   )
)
/* *INDENT-ON* */

KALEIDOSCOPE_INIT_PLUGINS(
  EEPROMSettings,
  EEPROMKeymap,
  Focus,
  FocusEEPROMCommand,
  FocusSettingsCommand,
  Qukeys,
  SpaceCadet,
  OneShot,
  Macros,
  MouseKeys
);

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {
  case MACRO_QWERTY:
    // This macro is currently unused, but is kept around for compatibility
    // reasons. We used to use it in place of `MoveToLayer(QWERTY)`, but no
    // longer do. We keep it so that if someone still has the old layout with
    // the macro in EEPROM, it will keep working after a firmware update.
    Layer.move(QWERTY);
    break;
  case MACRO_VERSION_INFO:
    if (keyToggledOn(keyState)) {
      Macros.type(PSTR("Keyboardio Atreus - Kaleidoscope "));
      Macros.type(PSTR(BUILD_INFORMATION));
    }
    break;
  default:
    break;
  }

  return MACRO_NONE;
}

void setup() {
  Kaleidoscope.setup();
  SpaceCadet.disable();
  EEPROMKeymap.setup(10);
  MouseKeys.speed = 40;
}

void loop() {
  Kaleidoscope.loop();
}
