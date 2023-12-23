#include "file_stream.hpp"

#include <stdexcept>
#include <limits> 

namespace lab {

FileStream::FileStream(const std::string& filepath) {
  fd_.open(filepath, std::ios_base::in);
  if(!fd_.is_open()) {
    throw std::invalid_argument("Failed tot open " + filepath);
  }
}

int FileStream::Get() {
  int result;
  fd_ >> result;
  if(fd_.fail()) {
    return std::numeric_limits<int>::min();
  }
  return result;
}

}