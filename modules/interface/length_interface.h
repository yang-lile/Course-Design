//
// Created by lilua on 2020/11/25.
//

#ifndef STORE_SYSTEM_LENGTH_INTERFACE_H
#define STORE_SYSTEM_LENGTH_INTERFACE_H

#include "data_struct_interface.h"

// 接口类，提供长度操作的接口
class LengthInterface : public DataStructInterface {
 protected:
  LengthInterface();

  ~LengthInterface() override = 0;

 protected:
  // 获取长度
  // 标记为const，不会改变类的方法
  [[maybe_unused]] [[nodiscard]] virtual int getLength() const;

  // 修改长度
  virtual void setLength(int length);

 private:
  // 唯一的长度常量
  int length_;
};

#endif  // STORE_SYSTEM_LENGTH_INTERFACE_H
