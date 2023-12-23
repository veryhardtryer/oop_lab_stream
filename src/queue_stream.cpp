#include "queue_stream.hpp"

#include <limits>

namespace lab {

int QueueStream::Get() {
  if(pos_ == buff_.size()) {
    return std::numeric_limits<int>::min();
  }
  return buff_[pos_++];
}

}