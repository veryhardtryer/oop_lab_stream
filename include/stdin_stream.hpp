#pragma once
#include "istream.hpp"

namespace lab {

class StdinStream final : public IStream {
 public:

  int Get() override;

};

} // namespace lab