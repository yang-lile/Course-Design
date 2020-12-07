//
// Created by lilua on 2020/12/7.
//

#ifndef STORE_SYSTEM_INSERT_INTERFACE_H
#define STORE_SYSTEM_INSERT_INTERFACE_H

#include "data_struct_interface.h"

template <typename T>
class [[maybe_unused]] InsertInterface : public DataStructInterface {
 protected:
  ~InsertInterface() override = default;

  // 添加操作，T为数据类型，aim是要插入的位置
  [[maybe_unused]] virtual void insert(T data, int aim) = 0;
};

#endif  // STORE_SYSTEM_INSERT_INTERFACE_H
