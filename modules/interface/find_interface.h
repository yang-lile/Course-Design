//
// Created by lilua on 2020/12/7.
//

#ifndef STORE_SYSTEM_FIND_INTERFACE_H
#define STORE_SYSTEM_FIND_INTERFACE_H

#include "data_struct_interface.h"

template <typename T>
class [[maybe_unused]] FindInterface : public DataStructInterface {
 protected:
  ~FindInterface() override = default;

  // 给定的坐标aim找值，返回不可改变的常量
  [[maybe_unused]] virtual bool find(int aim, T& data) const = 0;
};

#endif  // STORE_SYSTEM_FIND_INTERFACE_H
