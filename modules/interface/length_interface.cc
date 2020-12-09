//
// Created by lilua on 2020/11/25.
//

#include "length_interface.h"

LengthInterface::LengthInterface() : length_(0) {}

LengthInterface::~LengthInterface() = default;

/// 获取长度
/// \return 得到人类语言的长度
[[maybe_unused]] int LengthInterface::getLength() const {
  return this->length_;
}

/// 修改长度
/// \param length 设置长度为length
void LengthInterface::setLength(int length) { this->length_ = length; }
