#pragma once

#include <map>
#include <ostream>

#include "istream.hpp"

namespace lab {

class Frequency {
  using counter = size_t;
 public:

  virtual void Calculate(IStream& stream); 

  friend std::ostream& operator<<(std::ostream& os,
    const Frequency& frequency);

 private:
  std::map<counter, int> data_;
};
   
} // namespace lab