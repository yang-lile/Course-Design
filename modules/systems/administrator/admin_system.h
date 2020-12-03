//
// Created by lilua on 2020/12/3.
//

#ifndef STORE_SYSTEM_ADMIN_SYSTEM_H
#define STORE_SYSTEM_ADMIN_SYSTEM_H

#include "model/user_message.h"

/*
 * 私有继承
 * 为了只包含功能，但是和原类不是一个作用
*/
class AdminSystem : private UserMessage{
 public:
  AdminSystem(const char* address);
//  void addUser();
};

#endif  // STORE_SYSTEM_ADMIN_SYSTEM_H
