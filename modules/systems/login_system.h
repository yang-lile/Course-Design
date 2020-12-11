//
// Created by lilua on 2020/12/2.
//

#ifndef STORE_SYSTEM_LOGIN_SYSTEM_H
#define STORE_SYSTEM_LOGIN_SYSTEM_H

#include <tools/output_template.h>

#include <fstream>

#include "model/user_message.h"

template <typename T>
class LoginSystem {
 public:
  // 从文件读数据
  explicit LoginSystem(const char *address);
  // 退出系统，保存数据
  virtual ~LoginSystem() = 0;

  // 登录系统
  [[maybe_unused]] virtual bool login();

 protected:

  // 核实是否存在账户
  virtual bool hasAccount(T t) = 0;

  int length_;
  T *head_;
  FixedString address_;
};


template <typename T>
LoginSystem<T>::LoginSystem(const char *address)
    : address_(address), length_(0), head_(nullptr) {
  std::ifstream in(this->address_.getStr());

  // 读取账户数
  in >> this->length_;
  // 屏蔽回车
  in.get();
  // 所有的账户
  this->head_ = new UserMessage[this->length_];
  for (int i = 0; i < this->length_; ++i) {
    in >> this->head_[i];
  }

  // 释放文件
  in.close();
}

template <typename T>
LoginSystem<T>::~LoginSystem() {
  // 写回原文件
  std::ofstream out(this->address_.getStr());
  out << this->length_ << std::endl;
  for (int i = 0; i < this->length_; ++i) {
    out << this->head_[i];
  }

  // 释放
  out.close();
  delete[] this->head_;
}

template <typename T>
[[maybe_unused]] bool LoginSystem<T>::login() {
  // 登录欢迎
  OutputTemplate::divideLine();
  OutputTemplate::welcome(OutputTemplate::welcomeState::MainPage);
  OutputTemplate::divideLine();

  // 开始输入
  FixedString id, pw;
  UserMessage userMessage;
  int i = 0;
  bool flag;
  do {
    OutputTemplate::pleaseInput("login account");
    std::cin >> id;
    OutputTemplate::pleaseInput("password");
    std::cin >> pw;
    userMessage = UserMessage(id, pw);
    OutputTemplate::divideLine();

    i++;
    flag = this->hasAccount(userMessage);

    // 没有关系的两个条件，达成一个就退出
    if (i == 3) break;
  } while (!flag);

  // 查看登录情况
  if (flag) {
    // 登录
    OutputTemplate::oneSentence("success");
    return true;
  } else {
    // 报错退出
    OutputTemplate::oneSentence("login fault");
    return false;
  }
}

template <typename T>
bool LoginSystem<T>::hasAccount(T t) {
  for (int i = 0; i < this->length_; ++i) {
    if (this->head_[i] == t) return true;
  }
  return false;
}

#endif  // STORE_SYSTEM_LOGIN_SYSTEM_H
