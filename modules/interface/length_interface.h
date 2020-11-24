//
// Created by lilua on 2020/11/25.
//

#ifndef STORE_SYSTEM_LENGTH_INTERFACE_H
#define STORE_SYSTEM_LENGTH_INTERFACE_H

#include "base_interface.h"

// 接口类，提供长度操作的接口
class [[maybe_unused]] LengthInterface : virtual BaseInterface {
 protected:
  LengthInterface();

  ~LengthInterface() override = default;

  // 获取长度
  [[maybe_unused]] virtual int GetLength();

 private:
  int length_;

  // 修改长度
  [[maybe_unused]] virtual void SetLength(int length);
};

#endif  // STORE_SYSTEM_LENGTH_INTERFACE_H
