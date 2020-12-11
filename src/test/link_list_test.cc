//
// Created by lilua on 2020/12/8.
//

#include "data_struct/link_list.h"
#include <iostream>
using namespace std;

int main() {
  auto list=LinkList<int>();
  cout << "print l" << endl;
  list.insert(0,1);
  list.display();
  int v = 3;
  list.insert(0, v);
  return 0;
}