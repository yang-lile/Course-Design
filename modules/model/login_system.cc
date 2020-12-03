//
// Created by lilua on 2020/12/2.
//

#include "login_system.h"

#include <fstream>

#include "output_template.h"

LoginSystem::LoginSystem(const char* address)
    : address_(address), length_(0), head_(nullptr) {
  std::ifstream in(this->address_.getString());

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

LoginSystem::~LoginSystem() {
  std::ofstream out(this->address_.getString());

  out << this->length_ << std::endl;
  for (int i = 0; i < this->length_; ++i) {
    out << this->head_[i];
  }

  // 释放
  out.close();
  delete[] this->head_;
}

bool LoginSystem::hasAccount(UserMessage userMessage) {
  for (int i = 0; i < this->length_; ++i) {
    if (this->head_[i] == userMessage) return true;
  }
  return false;
}

void LoginSystem::login() {
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
  } else {
    // 报错退出
    OutputTemplate::oneSentence("login fault");
    return;
  }
}
