//
// Created by lilua on 2020/11/26.
//

#include "fixed_string.h"

#include <cstring>

FixedString::FixedString() : str_(nullptr), limit_(-1) {}

[[maybe_unused]] FixedString::FixedString(int limit)
    : str_(nullptr), limit_(limit) {
  FixedString::setLength(0);
}

[[maybe_unused]] FixedString::FixedString(const FixedString &fixedString)
    : LengthInterface(fixedString)  // 不明其意
{
  this->str_ = new char[fixedString.getLength()]();
  strcpy(this->str_, fixedString.str_);
  this->limit_ = fixedString.limit_;
}

[[maybe_unused]] FixedString::FixedString(const char *str)
    : str_(nullptr), limit_(-1) {
  // 获取长度并设置长度
  int len = (int)strlen(str) + 1;  // 不能直接把ull和int相加
  FixedString::setLength(len);

  // 拷贝到新的空间
  this->str_ = new char[len];
  strcpy(this->str_, str);
}

FixedString::~FixedString() { delete[] this->str_; }

std::istream &operator>>(std::istream &input, FixedString &fixedString) {
  // 释放原内存
  delete[] fixedString.str_;

  if (fixedString.limit_ != -1) {
    // 直接用最大限度+1去设置内存值
    fixedString.str_ = new char[fixedString.limit_ + 1];
    // 做一个要求限定长度的输入
    do {
      // 借助string来输入
      std::string s;
      std::getline(input, s);

      // 如果满足条件，退出
      if (fixedString.limit_ == s.length()) {
        strcpy(fixedString.str_, s.c_str());
        break;
      }
      // 否则报错，然后继续循环
      std::cout << "Require input by fixed length" << std::endl;
      std::cout << "Now it set fixed length is [" << fixedString.limit_ << "]"
                << std::endl;
      std::cout << "Please input again:" << std::endl;
    } while (true);  // end-do
  } else {
    // 借助string来输入
    std::string s;
    std::getline(input, s);

    // 获取长度并设置长度
    int len = (int)s.length() + 1;  // 不能直接把ull和int相加
    fixedString.setLength(len);

    // 拷贝到新的空间
    fixedString.str_ = new char[len];
    strcpy(fixedString.str_, s.c_str());
  }
  return input;
}

std::ostream &operator<<(std::ostream &output, FixedString &fixedString) {
  output << fixedString.str_;
  return output;
}

void FixedString::setLength(int length) { LengthInterface::setLength(length); }

int FixedString::getLength() const { return LengthInterface::getLength(); }

[[maybe_unused]] const char *FixedString::getString() { return this->str_; }
