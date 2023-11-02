cmake_minimum_required(VERSION 3.12)

project(UnboundedInteger)

set(CMAKE_CXX_STANDARD 20)

add_executable(tests ./FIPS.cpp)

enable_testing()
add_test(NAME tests COMMAND tests)
