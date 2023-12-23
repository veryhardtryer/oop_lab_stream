#include "frequency.hpp"

#include <limits>

namespace lab {

void Frequency::Calculate(IStream& stream) {
  data_.clear();
  int value;
  while((value = stream.Get()) != std::numeric_limits<int>::min()) {
    if(value >= 0) {
      data_[value]++;
    }
  }
}

std::ostream& operator<<(std::ostream& os,
    const Frequency& frequency) {
  for(auto& pair : frequency.data_) {
    os << '(' << pair.first << " , " << pair.second << ')';
  }
  return os;
}

}