cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Snake)

string(APPEND CMAKE_CXX_FLAGS " -Wall -Werror")

add_executable(main src/main.cpp src/Snake.cpp)

target_include_directories(main PUBLIC include src)