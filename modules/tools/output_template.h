//
// Created by lilua on 2020/12/2.
//

#ifndef STORE_SYSTEM_OUTPUT_TEMPLATE_H
#define STORE_SYSTEM_OUTPUT_TEMPLATE_H

class OutputTemplate {
 public:
  // 换行符
  static void enter();

  // 分割线
  static void divideLine(char mark,int length);
  static void divideLine();

  // 用来打印一条语句
  static void oneSentence(const char* sentence);

  // 用于打印列表
  static void listItem(int index, const char* item);

  // 打印欢迎语句
  enum welcomeState {MainPage,Admin,Shopkeeper,Seller};
  static void welcome(welcomeState state);

  // 打印退出项语句
  enum exitState { Return [[maybe_unused]] = 0, Exit = 1 };
  static void exitItem(exitState state);

  // 选择出错的提示
  static void selectWarning(int top);

  // 提示需要输入一个关键字的值，note表示注意事项
  static void pleaseInput(const char* keyWord, const char* note = "");

  // 打印登录提示
  static void userSelect();

  // 登录提示
  static void login();

  static void exit();
};

#endif  // STORE_SYSTEM_OUTPUT_TEMPLATE_H
