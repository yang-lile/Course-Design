//
// Created by lilua on 2020/12/1.
//

#include "tools/assist.cc"
#include "tools/output_template.cc"

enum LoginResult {
  EXIT = 0,
  ADMINISTRATOR,
  SHOPKEEPER,
  SELLER,
};

LoginResult userSelect() {
  // 设置状态
  int result = 0;

  // 初次选择
  outputTemplate::login();
  std::cin >> result;

  // 不符合条件则提示出错并重输
  while (!assist::hasSelect(result, 3)) {
    outputTemplate::login();
    outputTemplate::selectWarning(3);
    std::cin >> result;
  }
  return static_cast<LoginResult>(result);
}