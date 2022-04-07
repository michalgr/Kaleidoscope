/* -*- mode: c++ -*-
 * Kaleidoscope - Firmware for computer input devices
 * Copyright (C) 2021-2022  Keyboard.io, Inc.
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef ARDUINO_GD32F303CC_GENERIC

#include <Arduino.h>

#include "kaleidoscope/device/Base.h"
#include "kaleidoscope/driver/bootloader/gd32/Base.h"
#include "kaleidoscope/driver/hid/Keyboardio.h"
#include "kaleidoscope/driver/mcu/GD32.h"
#include "kaleidoscope/driver/storage/GD32Flash.h"

namespace kaleidoscope {
namespace device {
namespace gd32 {

struct EvalStorageProps : kaleidoscope::driver::storage::GD32FlashProps {};

struct EvalProps : kaleidoscope::device::BaseProps {
  typedef kaleidoscope::driver::hid::KeyboardioProps HIDProps;
  typedef kaleidoscope::driver::hid::Keyboardio<HIDProps> HID;

  typedef kaleidoscope::driver::bootloader::gd32::Base BootLoader;
  typedef EvalStorageProps StorageProps;
  typedef kaleidoscope::driver::storage::GD32Flash<StorageProps> Storage;

  typedef kaleidoscope::driver::mcu::GD32Props MCUProps;
  typedef kaleidoscope::driver::mcu::GD32<MCUProps> MCU;

  static constexpr const char *short_name = "GD32Eval";
};

class Eval : public kaleidoscope::device::Base<EvalProps> {
 public:
  auto serialPort() -> decltype(Serial) & {
    return Serial;
  }
  static void rebootBootloader();
};

// clang-format off
#define PER_KEY_DATA(dflt,                                           \
         R0C0, R0C1                                                  \
  )                                                                  \
         R0C0, R0C1
// clang-format on

}  // namespace gd32
}  // namespace device

EXPORT_DEVICE(kaleidoscope::device::gd32::Eval)

}  // namespace kaleidoscope

#endif  // ifdef ARDUINO_GD32F303CC_GENERIC
