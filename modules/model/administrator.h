//
// Created by lilua on 2020/12/2.
//

#ifndef ADMINISTRATOR_ADMINISTRATOR_H
#define ADMINISTRATOR_ADMINISTRATOR_H

#include "data_struct/fixed_string.h"

class Administrator {
 public:
  Administrator();

  friend std::istream& operator>>(std::istream&, Administrator&);
  friend std::ostream& operator<<(std::ostream&, Administrator&);

 private:
  FixedString id_, passwd_;
};

#endif  // ADMINISTRATOR_ADMINISTRATOR_H
