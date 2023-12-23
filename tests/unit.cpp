#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>
#include <limits>
#include <cmath>

#include "file_stream.hpp"
#include "stdin_stream.hpp"
#include "queue_stream.hpp"
#include "frequency.hpp"

using namespace lab;

constexpr const int kfile_data_count = 500;
constexpr const char* filepath = "f.txt";

TEST(Stream, File) {
  try {
    std::fstream out;
    out.open(filepath);
    if(!out.is_open()) {
      throw std::runtime_error("Fail start testing");
    }
    for(int i = 0; i < kfile_data_count; ++i) {
      out << static_cast<int>(std::sin(i) * 100) << ' ';
    }
    out.close();

    FileStream in(filepath);
    for(int i = 0; i < kfile_data_count; ++i) {
      ASSERT_EQ(static_cast<int>(std::sin(i) * 100), in.Get());
    }
    ASSERT_EQ(std::numeric_limits<int>::min(), in.Get());
  } catch(std::exception& e) {
    std::cerr << e.what() << std::endl;
    ASSERT_TRUE(false);
  }
}

TEST(Stream, Stdin) {
  std::cout << "Skipping" << std::endl;
  return;
  try {
    StdinStream in;
    std::vector<int> input;
    int val;
    std::cout << "Enter digits. Enter -1 to stop\n";
    while((val = in.Get()) != -1) {
      input.push_back(val);
    }
    std::cout << "Your input:\n";
    for(size_t i = 0; i < input.size(); ++i) {
      std::cout << input[i] << ' ';
    }
    std::cout << std::endl;
  } catch(std::exception& e) {
    std::cerr << e.what() << std::endl;
    ASSERT_TRUE(false);
  }
}

TEST(Stream, Queue) {
  constexpr const int kcount = 10000;
  try {
    std::vector<int> input(kcount);
    srand(time(0));
    for(size_t i = 0; i < kcount; ++i) {
      input[i] = rand() % kcount;
    }

    QueueStream queue(input.begin(), input.end());
    for(size_t i = 0; i < kcount; ++i) {
      ASSERT_EQ(queue.Get(), input[i]);
    }
    ASSERT_EQ(std::numeric_limits<int>::min(), queue.Get());
  } catch(std::exception& e) {
    std::cerr << e.what() << std::endl;
    ASSERT_TRUE(false);
  }
}

TEST(Math, Frequncies) {
  try {
    FileStream in(filepath);
    Frequency frequency; 
    frequency.Calculate(in);
    std::cout << frequency << std::endl;
  } catch(std::exception& e) {
    std::cerr << e.what() << std::endl;
    ASSERT_TRUE(false);
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
