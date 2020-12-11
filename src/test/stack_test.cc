//
// Created by lilua on 2020/12/10.
//

#include <iostream>

#include "interface/stack_interface.h"

int main() {
  StackInterface<int> stackInterface;
  std::cout << stackInterface.isEmpty();
  return 0;
}