//
// Created by lilua on 2020/11/26.
//

#ifndef STORE_SYSTEM_FIXED_STRING_H
#define STORE_SYSTEM_FIXED_STRING_H

// 用于重写输入输出流
#include <iostream>

// 用于导入LengthInterface
#include "interface/length_interface.h"

/// 限定长度的字符串
class FixedString : private LengthInterface {
 public:
  /// \构造函数
  /// 默认limit为-1，无限制
  FixedString();

  /// \构造函数
  /// 给定一个限制上限的字符串
  /// \param limit 字符串长度上限
  explicit FixedString(int limit);

  /// \构造函数
  /// 给定一个字符串来初始化
  /// \param str 字符串
  explicit FixedString(const char* str);

  /// \拷贝构造函数
  /// \param fixedString 传入另一个FixedString
  FixedString(const FixedString& fixedString);

  /// \析构函数
  ~FixedString() override;

  /// 获取字符串
  /// \return 返回这个字符串
  [[maybe_unused]] [[nodiscard]] char* getStr() const;

  /// 重载输入函数
  /// \param in 标准输入流
  /// \param string 输入到自身
  /// \return 返回输入流本身
  friend std::istream& operator>>(std::istream& is, FixedString& string);

  /// 输出流函数
  /// \param os 标准输出流
  /// \param string 输出自身
  /// \return 返回输出流本身
  friend std::ostream& operator<<(std::ostream& os, const FixedString& string);

  /// \重载等于运算符 判断相等
  /// \param fixedString
  /// \return 返回是否相等
  bool operator==(FixedString& fixedString);

 private:
  /// 指向字符串实体的指针
  char* str_;

  /// 限制的大小，如果为非-1，则长度最大不超过limit_
  int limit_;

  [[nodiscard]] unsigned getLength() const override;
  void setLength(unsigned length) override;
};

#endif  // STORE_SYSTEM_FIXED_STRING_H
