//
// Created by lilua on 2020/12/7.
//

#ifndef STORE_SYSTEM_MODIFY_INTERFACE_H
#define STORE_SYSTEM_MODIFY_INTERFACE_H

#include "data_struct_interface.h"

/// 接口类，提供修改元素的接口
template <typename T>
class [[maybe_unused]] ModifyInterface : public DataStructInterface {
 protected:
  ~ModifyInterface() override = default;

  /// 修改操作
  /// \param aim 人类语言中的要插入的位置
  /// \param data 要修改的值
  /// \return 返回该类型的引用以便于链式调用
  virtual ModifyInterface<T> &modify(int aim,const T& data) = 0;
};

#endif  // STORE_SYSTEM_MODIFY_INTERFACE_H
