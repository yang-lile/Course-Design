//
// Created by lilua on 2020/12/1.
//

#include "data_struct/fixed_string.h"

using namespace std;

int main() {
  FixedString fixedString(3);

  cin >> fixedString;
  FixedString fixedString1 = fixedString;
  cout << fixedString1;
  return 0;
}