cmake_minimum_required(VERSION 3.24)

project(assignment8_3_1 LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(exec_name main)

add_compile_options(-Wall -Wextra -Wextra)

#add_executable(${exec_name} main.cpp)
#target_include_directories(${exec_name} PUBLIC ${CMAKE_SOURCE_DIR}/include)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(tests)
