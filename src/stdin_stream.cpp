#include "stdin_stream.hpp"

#include <iostream>
#include <limits>

namespace lab {

int StdinStream::Get() {
  int result;
  std::cin >> result;
  if(std::cin.fail()) {
    return std::numeric_limits<int>::min();
  }
  return result;
}

}