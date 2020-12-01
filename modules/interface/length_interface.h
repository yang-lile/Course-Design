//
// Created by lilua on 2020/11/25.
//

#ifndef STORE_SYSTEM_LENGTH_INTERFACE_H
#define STORE_SYSTEM_LENGTH_INTERFACE_H

#include "base_interface.h"

// 接口类，提供长度操作的接口
class LengthInterface : virtual public BaseInterface {
 protected:
  LengthInterface();

  ~LengthInterface() override = default;

  // 获取长度
  // 标记为const，不会改变类的方法
  [[nodiscard]] virtual int GetLength() const;

  // 修改长度
  virtual void SetLength(int length);

 private:
  void _printLog() const override;
  int length_;
};

#endif  // STORE_SYSTEM_LENGTH_INTERFACE_H
