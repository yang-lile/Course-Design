//
// Created by lilua on 2020/12/7.
//

#ifndef STORE_SYSTEM_SEARCH_INTERFACE_H
#define STORE_SYSTEM_SEARCH_INTERFACE_H

#include "data_struct_interface.h"

template <typename T>
class [[maybe_unused]] SearchInterface : public DataStructInterface {
 protected:
  ~SearchInterface() override = default;

  // 查找操作，给定值data去找坐标，找到的值通过返回值返回
  [[maybe_unused]] virtual int search(T data) = 0;
};

#endif  // STORE_SYSTEM_SEARCH_INTERFACE_H
