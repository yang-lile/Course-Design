//
// Created by lilua on 2020/11/26.
//

#ifndef STORE_SYSTEM_FIXED_STRING_H
#define STORE_SYSTEM_FIXED_STRING_H

// 用于重写输入输出流
#include <iostream>

// 用于导入LengthInterface
#include "interface/length_interface.h"

// 限定长度的字符串
class [[maybe_unused]] FixedString : virtual public LengthInterface {
 public:
  // 默认limit为-1，无限制
  FixedString();

  // 给定一个限制上限的字符串
  [[maybe_unused]] explicit FixedString(int limit);

  [[maybe_unused]] explicit FixedString(const char*);

  [[maybe_unused]] FixedString(const FixedString&);

  // 析构
  ~FixedString() override;

  // 重载输入输出函数
  friend std::istream& operator>>(std::istream&, FixedString&);
  friend std::ostream& operator<<(std::ostream&, FixedString&);

  [[maybe_unused]] const char * GetString();

 private:
  // 指向字符串的指针
  char* str_;

  // 限制的大小，如果为非-1，则长度最大不超过`limit_`
  int limit_;

  // 隐藏LengthInterface的方法
  void SetLength(int length) override;
  [[nodiscard]] int GetLength() const override;
};

#endif  // STORE_SYSTEM_FIXED_STRING_H
