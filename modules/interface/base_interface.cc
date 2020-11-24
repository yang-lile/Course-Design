//
// Created by lilua on 2020/11/24.
//

#include "base_interface.h"

#include <iostream>

BaseInterface::BaseInterface() { this->_printLog(); }

void BaseInterface::_printLog() const {
  std::cout << typeid(*this).name() << " has been called!" << std::endl;
}
