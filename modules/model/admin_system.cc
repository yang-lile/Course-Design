//
// Created by lilua on 2020/12/3.
//

#include "admin_system.h"

#include <model/output_template.h>

#include <fstream>
AdminSystem::AdminSystem(const char* address) : LoginSystem(address) {}
AdminSystem::~AdminSystem() {
  // 写回原文件
  std::ofstream out(this->address_.getString());
  out << this->length_ << std::endl;
  for (int i = 0; i < this->length_; ++i) {
    out << this->head_[i];
  }

  // 释放
  out.close();
  delete[] this->head_;
}
bool AdminSystem::hasAccount(AdminMessage t) {
  for (int i = 0; i < this->length_; ++i) {
    if (this->head_[i] == t) return true;
  }
  return false;
}
bool AdminSystem::login() {  // 登录欢迎
  OutputTemplate::divideLine();
  OutputTemplate::welcome(OutputTemplate::welcomeState::MainPage);
  OutputTemplate::divideLine();

  // 开始输入
  FixedString id, pw;
  AdminMessage adminMessage;
  int i = 0;
  bool flag;
  do {
    OutputTemplate::pleaseInput("login account");
    std::cin >> id;
    OutputTemplate::pleaseInput("password");
    std::cin >> pw;
    adminMessage = AdminMessage(id, pw);
    OutputTemplate::divideLine();

    i++;
    flag = this->hasAccount(adminMessage);

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
