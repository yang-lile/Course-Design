//
// Created by lilua on 2020/11/26.
//

#include "fixed_string.h"

#include <cstring>

FixedString::FixedString() : str_(nullptr), limit_(-1) {}

FixedString::FixedString(int limit) : str_(nullptr), limit_(limit) {}

FixedString::FixedString(const char *str) : str_(nullptr), limit_(-1) {
  // 获取长度并设置长度
  int len = (int)strlen(str) + 1;  // 不能直接把ull和int相加，所以要转义
  FixedString::setLength(len);

  // 拷贝到新的空间
  this->str_ = new char[len];
  strcpy(this->str_, str);
}

FixedString::~FixedString() { delete[] this->str_; }

FixedString::FixedString(const FixedString &fixedString)
    // 拷贝构造函数构造父类
    : LengthInterface(fixedString) {
  this->limit_ = fixedString.limit_;
  this->str_ = new char[fixedString.getLength()];
  strcpy(this->str_, fixedString.str_);
}

bool FixedString::operator==(FixedString &fixedString) {
  return strcmp(fixedString.str_, this->str_) == 0;
}

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

      // 如果满足长度相等，退出
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

[[maybe_unused]] char *FixedString::getStr() const { return str_; }
std::ostream &operator<<(std::ostream &os, const FixedString &string) {
  os << string.str_ << std::endl << string.limit_;
  return os;
}

unsigned FixedString::getLength() const { return LengthInterface::getLength(); }

void FixedString::setLength(unsigned length) { LengthInterface::setLength(length); }
