//
// Created by lilua on 2020/11/24.
//

#include "base_interface.h"

#ifdef DEBUG
#include <iostream>
#endif

BaseInterface::BaseInterface() { this->printLog(); }

void BaseInterface::printLog() const {
#ifdef DEBUG
  std::cout << typeid(*this).name() << " has been called!" << std::endl;
#endif
}
