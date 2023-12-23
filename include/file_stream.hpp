#pragma once
#include "istream.hpp"

#include <string>
#include <fstream>

namespace lab {

class FileStream final : public IStream {
 public:

  explicit FileStream(const std::string& filepath);

  int Get() override;

 private:
  std::fstream fd_;
};

} // namespace lab