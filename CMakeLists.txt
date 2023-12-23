cmake_minimum_required(VERSION 3.25)

include(cmake/CompileOptions.cmake)
include(cmake/Werror.cmake)
include(cmake/Sanitize.cmake)

project(stream_lab)

set(HEADERS
  include/istream.hpp
  include/file_stream.hpp
  include/stdin_stream.hpp
  include/queue_stream.hpp
)

set(SOURCES
  src/istream.cpp
  src/file_stream.cpp
  src/stdin_stream.cpp
  src/queue_stream.cpp
)

add_library(${CMAKE_PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

add_subdirectory(external)
add_subdirectory(tests)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)