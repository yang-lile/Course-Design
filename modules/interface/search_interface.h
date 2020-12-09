//
// Created by lilua on 2020/12/7.
//

#ifndef STORE_SYSTEM_SEARCH_INTERFACE_H
#define STORE_SYSTEM_SEARCH_INTERFACE_H

#include "data_struct_interface.h"

/// 接口类，提供搜索元素的接口
template <typename T>
class [[maybe_unused]] SearchInterface : public DataStructInterface {
 protected:
  ~SearchInterface() override = default;

  /// 查找操作，给定值data去找坐标
  /// \param data 待查找的值，不修改它，所以传了常引用
  /// \return 返回人类语言的下标，返回0为没找到
  [[maybe_unused]] virtual int search(const T &data) const = 0;
};

#endif  // STORE_SYSTEM_SEARCH_INTERFACE_H
