//
// Created by lilua on 2020/11/25.
//

#include "goods.h"

Goods::Goods() : name_(), code_(10), producer_(), price_(0) {}

std::ostream &PrintMessage(){

}

std::istream &operator>>(std::istream &input, Goods &goods) {
  std::cout << "Please input goods";
  input >> goods.name_ >> goods.code_ >> goods.producer_ >> goods.price_;
  return input;
}

std::ostream &operator<<(std::ostream &output, Goods &goods) {
  output << goods.name_ << std::endl
         << goods.code_ << std::endl
         << goods.producer_ << std::endl
         << goods.price_ << std::endl;
  return output;
}

