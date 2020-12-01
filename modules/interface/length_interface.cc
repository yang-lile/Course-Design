//
// Created by lilua on 2020/11/25.
//

#include "length_interface.h"

LengthInterface::LengthInterface():length_(0) {
  BaseInterface::_printLog();
}

int LengthInterface::GetLength() const { return this->length_;  }

void LengthInterface::SetLength(int length) { this->length_ = length; }

void LengthInterface::_printLog() const { BaseInterface::_printLog(); }
