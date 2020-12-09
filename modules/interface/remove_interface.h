//
// Created by lilua on 2020/12/7.
//

#ifndef STORE_SYSTEM_REMOVE_INTERFACE_H
#define STORE_SYSTEM_REMOVE_INTERFACE_H

#include "data_struct_interface.h"

template <typename T>
class [[maybe_unused]] RemoveInterface : public DataStructInterface {
 protected:
  ~RemoveInterface() override = default;

  // 删除操作，aim是要删除的位置
  [[maybe_unused]] virtual RemoveInterface<T>& remove(int aim) = 0;
};

#endif  // STORE_SYSTEM_REMOVE_INTERFACE_H
