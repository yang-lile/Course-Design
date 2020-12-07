//
// Created by lilua on 2020/12/3.
//

#ifndef STORE_SYSTEM_ADMIN_MESSAGE_H
#define STORE_SYSTEM_ADMIN_MESSAGE_H

#include "user_message.h"

class AdminMessage : public UserMessage{
 public:
  AdminMessage();

  AdminMessage(const FixedString&id,const FixedString&pw);

  // 重载输入输出函数
  friend std::istream& operator>>(std::istream&, AdminMessage&);
  friend std::ostream& operator<<(std::ostream&, AdminMessage&);

  // 判断是否相等
  bool operator==(AdminMessage& message);
};

#endif  // STORE_SYSTEM_ADMIN_MESSAGE_H
