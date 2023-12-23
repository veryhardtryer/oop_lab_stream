#pragma once

#include "istream.hpp"

#include <vector>

namespace lab {

class QueueStream final : public IStream {
 public:
  template <typename Iterator>
  QueueStream(const Iterator& begin, const Iterator& end);

  int Get() override;

 private:
  std::vector<int> buff_;
  size_t pos_;
};

template <typename Iterator>
QueueStream::QueueStream(const Iterator& begin, const Iterator& end) : 
  buff_(begin, end), pos_(buff_.size()) {}

} 