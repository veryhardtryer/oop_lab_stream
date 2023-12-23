#include "queue_stream.hpp"

#include <limits>

namespace lab {

int QueueStream::Get() {
  if(pos_ == 0) {
    return std::numeric_limits<int>::min();
  }
  return buff_[pos_--];
}

}