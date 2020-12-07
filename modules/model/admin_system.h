//
// Created by lilua on 2020/12/3.
//

#ifndef STORE_SYSTEM_ADMIN_SYSTEM_H
#define STORE_SYSTEM_ADMIN_SYSTEM_H

#include "admin_message.h"
#include "login_system.h"
/*
 * 私有继承
 * 为了只包含功能，但是和原类不是一个作用
 */
class AdminSystem : public LoginSystem<AdminMessage>{
 public:
  explicit AdminSystem(const char* address);
  ~AdminSystem() override;
//  void addUser();
  bool hasAccount(AdminMessage t) override;
  bool login() override;
};

#endif  // STORE_SYSTEM_ADMIN_SYSTEM_H
