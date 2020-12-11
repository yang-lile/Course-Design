//
// Created by lilua on 2020/12/7.
//

#ifndef STORE_SYSTEM_INSERT_INTERFACE_H
#define STORE_SYSTEM_INSERT_INTERFACE_H

#include "data_struct_interface.h"

/// 接口类，提供插入元素的接口
/// \tparam T 处理数据类型
/// \tparam ClassT 链式操作的返回类型
template <typename T, template <typename> class ClassT>
class [[maybe_unused]] InsertInterface : public DataStructInterface {
 protected:
  ~InsertInterface() override = default;

  // 添加操作，T为数据类型，aim是要插入的位置
  /// 添加操作
  /// \param aim 插入的位置
  /// \param data 插入的元素，使用常引用来传递
  /// \return 返回该类型的引用以便于链式调用
  [[maybe_unused]] virtual ClassT<T>& insert(int aim, const T& data) = 0;
};

#endif  // STORE_SYSTEM_INSERT_INTERFACE_H
