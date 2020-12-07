//
// Created by lilua on 2020/12/7.
//

#ifndef STORE_SYSTEM_MODIFY_INTERFACE_H
#define STORE_SYSTEM_MODIFY_INTERFACE_H

#include "data_struct_interface.h"

template <typename T>
class [[maybe_unused]] ModifyInterface : public DataStructInterface {
 protected:
  ~ModifyInterface() override = default;

  // 修改操作，T为数据类型，aim是要插入的位置
  [[maybe_unused]] void modify(int aim, T data) = 0;
};

#endif  // STORE_SYSTEM_MODIFY_INTERFACE_H
