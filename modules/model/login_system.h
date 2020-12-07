//
// Created by lilua on 2020/12/2.
//

#ifndef STORE_SYSTEM_LOGIN_SYSTEM_H
#define STORE_SYSTEM_LOGIN_SYSTEM_H

#include "user_message.h"

template <typename T>
class LoginSystem {
 public:
  // 从文件读数据
  explicit LoginSystem(const char *address);
  // 退出系统，保存数据
  virtual ~LoginSystem() = 0;

  // 登录系统
  virtual bool login();

 protected:

  // 核实是否存在账户
  virtual bool hasAccount(T t) = 0;

  int length_;
  T *head_;
  FixedString address_;
};

#endif  // STORE_SYSTEM_LOGIN_SYSTEM_H
