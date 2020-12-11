//
// Created by lilua on 2020/12/7.
//

#ifndef STORE_SYSTEM_REMOVE_INTERFACE_H
#define STORE_SYSTEM_REMOVE_INTERFACE_H

#include "data_struct_interface.h"

/// 接口类，提供删除元素的接口
/// \tparam T 处理数据类型
/// \tparam ClassT 链式操作的返回类型
template <typename T, template <typename> class ClassT>
class [[maybe_unused]] RemoveInterface : public DataStructInterface {
 protected:
  ~RemoveInterface() override = default;

  /// 删除操作
  /// \param aim 人类语言中要删除的元素位置
  /// \return 返回该类型的引用以便于链式调用
  [[maybe_unused]] virtual ClassT<T>& remove(int aim) = 0;
};

#endif  // STORE_SYSTEM_REMOVE_INTERFACE_H
