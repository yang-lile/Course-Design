//
// Created by lilua on 2020/12/8.
//

#include "data_struct/link_list.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  auto *list=new LinkList<int>();
//  search(,);
  vector<int> s;

  cout << "print l" << endl;
  list->display();
  int v = 3;
  list->insert(0, v);
  return 0;
}