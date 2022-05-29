cmake_minimum_required(VERSION 2.8)

project(test)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(myprog main.cpp my_lib.cpp my_lib_bye.cpp)