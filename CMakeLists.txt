cmake_minimum_required(VERSION 3.24)

project(monopoly_board)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main main.cpp)
add_executable(test tests/circular_list_test.cpp)
