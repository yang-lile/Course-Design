//
// Created by lilua on 2020/12/8.
//

#include "data_struct/link_list.h"

#include <iostream>
//#include <vector>
using namespace std;

int main() {

  auto list = LinkList<int>();
  cout << "print l" << endl;
  try {
    list.insert(0, 1)
        .insert(list.getLength(), 2)
        .insert(1, 3)
        .insert(list.getLength(), list.getLength())
        .display();
  } catch (std::out_of_range &e) {
    cout << e.what() << endl;
    list.insert(0, 1).insert(1, 2).insert(1, 3).display();
  }

  cout << "print l" << endl;
  list.insert(0, 1).display();
  int v = 3;
  cout << "print l" << endl;
  list.insert(0, v).display();
  int aim = list.search(2);
  cout << "print l" << endl;
  list.remove(aim).display();
  return 0;
}