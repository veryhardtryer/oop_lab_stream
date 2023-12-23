#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>

#include "file_stream.hpp"
#include "stdin_stream.hpp"
#include "queue_stream.hpp"

using namespace lab;


TEST(IO, FileStream) {
  constexpr const int kfile_data_count = 20;
  constexpr const char* filepath = "f.txt";
  try {
    std::fstream out;
    out.open(filepath);
    if(!out.is_open()) {
      throw std::runtime_error("Fail start testing");
    }
    for(int i = 0; i < kfile_data_count; ++i) {
      out << i << ' ';
    }

    FileStream in(filepath);
    for(int i = 0; i < kfile_data_count; ++i) {
      ASSERT_EQ(i, in.Get());
    }
  } catch(std::exception& e) {
    std::cerr << e.what() << std::endl;
    ASSERT_TRUE(false);
  }
}


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
