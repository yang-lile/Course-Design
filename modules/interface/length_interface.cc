//
// Created by lilua on 2020/11/25.
//

#include "length_interface.h"

LengthInterface::LengthInterface() : length_(0) {}

LengthInterface::~LengthInterface() = default;

[[maybe_unused]] int LengthInterface::getLength() const { return this->length_; }

void LengthInterface::setLength(int length) { this->length_ = length; }
