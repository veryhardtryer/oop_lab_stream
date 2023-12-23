#include "diap.hpp"

#include <string>

namespace lab {

Diap::Diap() {
  Reset();
}

void Diap::Calculate(IStream& stream) {
  int value;
  while((value = stream.Get()) != std::numeric_limits<int>::min()) {
    if(value < 0) {
      continue;
    }
    if(value > positive_max_) {
      positive_max_ = value;
    }
    if(value < positive_min_) {
      positive_min_ = value;
    }
  }
}

std::ostream& operator<<(std::ostream& os, const Diap& diap) {
  std::string max = diap.positive_max_ == std::numeric_limits<int>::min() ?
    "undefined" : std::to_string(diap.positive_max_);
  std::string min = diap.positive_min_ == std::numeric_limits<int>::max() ?
    "undefined" : std::to_string(diap.positive_min_);

  os << max << ' ' << min << ' ' << diap.count_;
  return os;
}

void Diap::Reset() {
  positive_max_ = std::numeric_limits<int>::min();
  positive_min_ = std::numeric_limits<int>::max();
  count_ = 0;
}

} // namespace lab