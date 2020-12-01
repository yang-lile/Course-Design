//
// Created by lilua on 2020/11/24.
//

#ifndef STORE_SYSTEM_EMPTY_INTERFACE_H
#define STORE_SYSTEM_EMPTY_INTERFACE_H

#include "base_interface.h"

// 接口类，提供判断空的接口
class [[maybe_unused]] EmptyInterface : virtual public BaseInterface {
 protected:
  EmptyInterface();

  ~EmptyInterface() override = default;

  // 判断为空
  [[maybe_unused]] virtual bool IsEmpty() = 0;

  // 判断不为空
  [[maybe_unused]] virtual bool IsNotEmpty() = 0;
};

#endif  // STORE_SYSTEM_EMPTY_INTERFACE_H
