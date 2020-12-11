//
// Created by lilua on 2020/11/25.
//

#ifndef STORE_SYSTEM_LENGTH_INTERFACE_H
#define STORE_SYSTEM_LENGTH_INTERFACE_H

#include "data_struct_interface.h"

/// 接口类，提供长度操作的接口
/// 其中get和set都是已经实现了的虚函数，可以直接私有继承，直接使用
class LengthInterface : public DataStructInterface {
 protected:
  LengthInterface();

  ~LengthInterface() override = 0;

  [[nodiscard]] virtual unsigned getLength() const = 0;

  virtual void setLength(unsigned length) = 0;

 private:
  /// 唯一的长度
  unsigned length_;
};

#endif  // STORE_SYSTEM_LENGTH_INTERFACE_H
