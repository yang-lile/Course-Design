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

  [[nodiscard]] virtual int getLength() const = 0;

  virtual void setLength(int length) = 0;

 private:
  /// 唯一的长度
  int length_;
};

#endif  // STORE_SYSTEM_LENGTH_INTERFACE_H
