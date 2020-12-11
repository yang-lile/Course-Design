//
// Created by lilua on 2020/11/24.
//

#ifndef STORE_SYSTEM_DATA_STRUCT_INTERFACE_H
#define STORE_SYSTEM_DATA_STRUCT_INTERFACE_H

/// 总的基类，保证了以下的类都是同源的，都是用来组合的组件
class DataStructInterface {
  // TODO: 长度类型的定义，重构

 protected:
  /// 带上析构函数是编码的健壮
  /// 不使用接口指针跨级访问是编程规范
  virtual ~DataStructInterface() = default;
};

#endif  // STORE_SYSTEM_DATA_STRUCT_INTERFACE_H
