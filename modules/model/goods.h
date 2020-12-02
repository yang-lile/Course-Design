//
// Created by lilua on 2020/11/25.
//

#ifndef STORE_SYSTEM_GOODS_H
#define STORE_SYSTEM_GOODS_H

#include "data_struct/fixed_string.h"

class Goods {
 public:
  Goods();

  // 重载输入输出函数
  friend std::istream& operator>>(std::istream&, Goods&);
  friend std::ostream& operator<<(std::ostream&, Goods&);



 private:
  FixedString name_;
  FixedString code_;
  FixedString producer_;
  float price_;
};

#endif  // STORE_SYSTEM_GOODS_H
