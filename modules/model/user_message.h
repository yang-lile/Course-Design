//
// Created by lilua on 2020/12/2.
//

#ifndef STORE_SYSTEM_USER_MESSAGE_H
#define STORE_SYSTEM_USER_MESSAGE_H

#include <data_struct/fixed_string.h>

class UserMessage {
 public:
  UserMessage();

  UserMessage(const FixedString& id, const FixedString& passwd);
//  // 删除拷贝
//  [[maybe_unused]] UserMessage(const UserMessage&);
  // 重载输入输出函数
  friend std::istream& operator>>(std::istream&, UserMessage&);
  friend std::ostream& operator<<(std::ostream&, UserMessage&);

  // 判断是否相等
  bool operator==(UserMessage& userMessage);

//  UserMessage& operator=(const UserMessage& userMessage);

// private:
  // 账户
  FixedString id_;
  // 密码
  FixedString password_;
};

#endif  // STORE_SYSTEM_USER_MESSAGE_H
