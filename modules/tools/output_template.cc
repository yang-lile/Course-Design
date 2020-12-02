//
// Created by lilua on 2020/12/1.
//
#include <cstring>
#include <iostream>

namespace outputTemplate {

// 换行符
void enter() { std::cout << std::endl; }

// 分割线
void divideLine() {
  char mark = '=';
  for (int i = 0; i < 35; ++i) {
    std::cout.put(mark);
  }
  enter();
}

// 用来打印一条语句
void oneSentence(const char* sentence) { std::cout << sentence << std::endl; }

// 用于打印列表
void listItem(int index, const char* item) {
  std::cout << " " << index << ") " << item << std::endl;
}

// 打印欢迎语句
void welcome() { oneSentence(">>>WELCOME TO STORE SYSTEM<<<"); }

// 打印退出项语句
enum exitState { Return [[maybe_unused]] = 0, Exit = 1 };
void exitItem(exitState state) {
  listItem(0, state == Exit ? "exit Store System." : "Back to previous.");
}

// 选择出错的提示
void selectWarning(int top) {
  std::cout << "You can only selected [0 - " << top << "]." << std::endl;
}

// 提示输入
void pleaseInput(const char* prompt, const char* note = "") {
  if (strlen(note) != 0) {
    std::cout << "[NOTE] " << note << " [NOTE]" << std::endl;
  }
  std::cout << "Please input " << prompt << ":";
}

// 打印登录提示
void login() {
  divideLine();
  oneSentence("Please select your login identity.");
  enter();

  // 定义三个选项
  const char* selects[3] = {
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

[[maybe_unused]] void exit() { oneSentence("Thank you for your use!"); }

};  // namespace outputTemplate