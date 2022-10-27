cmake_minimum_required(VERSION 3.23)
project(anna)

set(CMAKE_CXX_STANDARD 14)




add_subdirectory(lib/gtest)
add_subdirectory(test)
add_executable(anna main.cpp)
