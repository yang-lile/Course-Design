//
// Created by lilua on 2020/12/2.
//

#include "model/administrator.h"

#include <iostream>

#include "tools/file_operations.cc"

int main() {
  Administrator administrator;
  fileOperations::readAdmin(administrator);
  std::cout << administrator;
  return 0;
}