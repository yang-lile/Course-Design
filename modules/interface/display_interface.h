//
// Created by lilua on 2020/11/25.
//

#ifndef STORE_SYSTEM_DISPLAY_INTERFACE_H
#define STORE_SYSTEM_DISPLAY_INTERFACE_H

#include "data_struct_interface.h"

/// 接口类，提供打印操作的接口
class [[maybe_unused]] DisplayInterface : public DataStructInterface {
 protected:
  ~DisplayInterface() override = default;

  /// 打印数据结构的所有数据
  [[maybe_unused]] virtual void display() const = 0;
};

#endif  // STORE_SYSTEM_DISPLAY_INTERFACE_H
