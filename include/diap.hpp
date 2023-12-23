#pragma once

#include "frequency.hpp"

#include <limits>

namespace lab {

class Diap : public Frequency {
 public: 

  Diap();

  void Calculate(IStream& stream) override;

  friend std::ostream& operator<<(std::ostream& os, const Diap& diap);

 private:
  
  void Reset();

 private:
  int positive_max_;
  int positive_min_;
  size_t count_;
};

}