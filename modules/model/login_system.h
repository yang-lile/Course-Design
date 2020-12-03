//
// Created by lilua on 2020/12/2.
//

#ifndef STORE_SYSTEM_LOGIN_SYSTEM_H
#define STORE_SYSTEM_LOGIN_SYSTEM_H

#include "user_message.h"

enum loginAim { Admin = 1, Shopkeeper, Seller };

template <typename T>
class LoginSystem {
 public:
  // 从文件读数据
  explicit LoginSystem(const char *address);
  // 退出系统，保存数据
  ~LoginSystem();

  // 登录系统
  void login();

 private:
  FixedString address_;
  int length_;
  UserMessage *head_;

  // 核实是否存在账户
  bool hasAccount(UserMessage userMessage);
};

#endif  // STORE_SYSTEM_LOGIN_SYSTEM_H
