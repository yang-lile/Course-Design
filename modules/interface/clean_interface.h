//
// Created by lilua on 2020/11/25.
//

#ifndef STORE_SYSTEM_CLEAN_INTERFACE_H
#define STORE_SYSTEM_CLEAN_INTERFACE_H

#include "base_interface.h"

// 接口类，提供清空数据结构的操作
class [[maybe_unused]] CleanInterface : virtual public BaseInterface {
 protected:
  CleanInterface();

  ~CleanInterface() override = default;

  // 清空数据结构
  [[maybe_unused]] virtual void clean() = 0;
};

#endif  // STORE_SYSTEM_CLEAN_INTERFACE_H
