//
// Created by lilua on 2020/12/2.
//

#include <fstream>

#include "model/administrator.h"

namespace fileOperations {

// 管理员文件的读写
void readAdmin(Administrator& administrator) {
  std::ifstream in;
  in.open("./resource/Admin.txt");
  in >> administrator;
  std::cout << administrator;
}

}  // namespace fileOperations