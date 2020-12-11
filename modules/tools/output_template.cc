//
// Created by lilua on 2020/12/2.
//

#include "output_template.h"

#include <cstring>
#include <iostream>

void OutputTemplate::enter() { std::cout << std::endl; }

void OutputTemplate::divideLine(char mark,int length) {
  for (int i = 0; i < length; ++i) {
    std::cout.put(mark);
  }
  enter();
}

void OutputTemplate::divideLine() {
  divideLine('=',35);
}

void OutputTemplate::oneSentence(const char *sentence) {
  std::cout << sentence << std::endl;
}

void OutputTemplate::listItem(int index, const char *item) {
  std::cout << " " << index << ") " << item << std::endl;
}

void OutputTemplate::welcome(OutputTemplate::welcomeState state) {
  divideLine('*',23);
  // 欢迎
  oneSentence("**  WELCOME  TO  USE **");
  // 具体的内容
  switch (state) {
    case MainPage:
      oneSentence("**   STORE  SYSTEM   **");
      break;
    case Admin:
      oneSentence("**   ADMIN  SYSTEM   **");
      break;
    case Shopkeeper:
      oneSentence("** SHOPKEEPER SYSTEM **");
      break;
    case Seller:
      oneSentence("**   SELLER SYSTEM   **");
      break;
  }
  divideLine('*',23);

  // 按任意键继续
//  system("pause");
}

void OutputTemplate::exitItem(OutputTemplate::exitState state) {
  listItem(0, state == Exit ? "exit Store System." : "Back to previous.");
}

void OutputTemplate::selectWarning(int top) {
  std::cout << "You can only selected [0 - " << top << "]." << std::endl;
}

void OutputTemplate::pleaseInput(const char *keyWord, const char *note) {
  if (strlen(note) != 0) {
    std::cout << "[NOTE] " << note << " [NOTE]" << std::endl;
  }
  std::cout << "Please input " << keyWord << ":";
}

void OutputTemplate::userSelect() {
  divideLine();
  oneSentence("Please select your login identity.");
  enter();

  // 定义三个选项
  const char *selects[3] = {
      "login by Administrator.",
      "login by Shopkeeper.",
      "login by Seller.",
  };
  for (int i = 0; i < 3; ++i) {
    listItem(i + 1, selects[i]);
  }
  std::cout << std::endl;

  // 退出
  exitItem(Exit);

  // 提示输入
  pleaseInput("[0 ~ 3]");
}

void OutputTemplate::login() { oneSentence("Now"); }

void OutputTemplate::exit() { oneSentence("Thank you for your use!"); }
