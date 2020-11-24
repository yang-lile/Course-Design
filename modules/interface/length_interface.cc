//
// Created by lilua on 2020/11/25.
//

#include "length_interface.h"

LengthInterface::LengthInterface() { BaseInterface::_printLog(); }

[[maybe_unused]] int LengthInterface::GetLength() { return this->length_; }

[[maybe_unused]] void LengthInterface::SetLength(int length) {
  this->length_ = length;
}
