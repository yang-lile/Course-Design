//
// Created by lilua on 2020/12/2.
//

#include "administrator.h"

#include <fstream>

Administrator::Administrator() : id_(), passwd_() {}

std::istream &operator>>(std::istream &input, Administrator &administrator) {
  input >> administrator.id_;
  input >> administrator.passwd_;
  return input;
}

std::ostream &operator<<(std::ostream &output, Administrator &administrator) {
  output << "[" << administrator.id_ << "]" << std::endl
         << "[" << administrator.passwd_ << "]" << std::endl;
  return output;
}
