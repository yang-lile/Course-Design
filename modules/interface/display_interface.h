//
// Created by lilua on 2020/11/25.
//

#ifndef STORE_SYSTEM_DISPLAY_INTERFACE_H
#define STORE_SYSTEM_DISPLAY_INTERFACE_H

#include "base_interface.h"

// 接口类，提供打印操作的接口
class [[maybe_unused]] DisplayInterface : virtual BaseInterface {
 protected:
  DisplayInterface();

  ~DisplayInterface() override = default;

  // 打印
  [[maybe_unused]] virtual void Display() = 0;
};

#endif  // STORE_SYSTEM_DISPLAY_INTERFACE_H
