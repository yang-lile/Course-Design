//
// Created by lilua on 2020/11/24.
//

#ifndef STORE_SYSTEM_EMPTY_INTERFACE_H
#define STORE_SYSTEM_EMPTY_INTERFACE_H

#include "data_struct_interface.h"

// 接口类，提供判断空的接口
class [[maybe_unused]] EmptyInterface : public DataStructInterface {
 protected:
  ~EmptyInterface() override = default;

  // 判断数据结构里是没有元素的
  [[maybe_unused]] [[nodiscard]] virtual bool isEmpty() const= 0;

  // 判断数据结构里是有元素的
  [[maybe_unused]] [[nodiscard]] virtual bool isNotEmpty() const= 0;
};

#endif  // STORE_SYSTEM_EMPTY_INTERFACE_H
