//
// Created by lilua on 2020/12/7.
//

#ifndef STORE_SYSTEM_FIND_INTERFACE_H
#define STORE_SYSTEM_FIND_INTERFACE_H

#include "data_struct_interface.h"

/// 接口类，提供查找元素的接口
template <typename T>
class [[maybe_unused]] FindInterface : public DataStructInterface {
 protected:
  ~FindInterface() override = default;

  /// 通过下标aim来查找值，并通过data返回
  /// \param aim 下标，使用人类语言
  /// \param data 引用传值，返回找到的值
  /// \return 返回false表示没有找到
  [[maybe_unused]] virtual bool find(int aim, T& data) const = 0;
};

#endif  // STORE_SYSTEM_FIND_INTERFACE_H
