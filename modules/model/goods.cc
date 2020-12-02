//
// Created by lilua on 2020/11/25.
//

#include "goods.h"

#include "tools/output_template.cc"

Goods::Goods() : name_(), code_(10), producer_(), price_(0) {}

std::istream &operator>>(std::istream &input, Goods &goods) {
  outputTemplate::pleaseInput("goods.name");
  input >> goods.name_;
  outputTemplate::pleaseInput("goods.code", "this need a code length by 10!");
  input >> goods.code_;
  outputTemplate::pleaseInput("goods.producer");
  input >> goods.producer_;
  outputTemplate::pleaseInput("goods.price");
  input >> goods.price_;
  return input;
}

std::ostream &operator<<(std::ostream &output, Goods &goods) {
  output << goods.name_ << std::endl
         << goods.code_ << std::endl
         << goods.producer_ << std::endl
         << goods.price_ << std::endl;
  return output;
}
