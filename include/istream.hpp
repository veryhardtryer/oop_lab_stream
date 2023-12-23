#pragma once

namespace lab {

class IStream {
 public:
  virtual int Get() = 0;
  virtual ~IStream() {}
};

}