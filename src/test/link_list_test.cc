//
// Created by lilua on 2020/12/8.
//

#include "data_struct/link_list.h"

#include <iostream>
using namespace std;

int main() {
  auto list = LinkList<int>();
  cout << "print l" << endl;
  list.insert(0, 1).insert(0, 2).insert(1, 3).display();
  cout << "print l" << endl;
  list.insert(0,1).display();
  int v = 3;
  cout << "print l" << endl;
  list.insert(0, v).display();
  int aim = list.search(2);
  cout << "print l" << endl;
  list.remove(aim).display();
  return 0;
}