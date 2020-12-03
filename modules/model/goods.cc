//
// Created by lilua on 2020/11/25.
//

#include "goods.h"

#include "model/output_template.h"

Goods::Goods() : name_(), code_(10), producer_(), price_(0) {}

std::istream &operator>>(std::istream &input, Goods &goods) {
  OutputTemplate::pleaseInput("goods.name");
  input >> goods.name_;
  OutputTemplate::pleaseInput("goods.code", "this need a code length by 10!");
  input >> goods.code_;
  OutputTemplate::pleaseInput("goods.producer");
  input >> goods.producer_;
  OutputTemplate::pleaseInput("goods.price");
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
