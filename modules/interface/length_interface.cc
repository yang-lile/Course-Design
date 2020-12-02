//
// Created by lilua on 2020/11/25.
//

#include "length_interface.h"

LengthInterface::LengthInterface():length_(0) { BaseInterface::printLog();
}

int LengthInterface::getLength() const { return this->length_;  }

void LengthInterface::setLength(int length) { this->length_ = length; }

void LengthInterface::printLog() const { BaseInterface::printLog(); }
