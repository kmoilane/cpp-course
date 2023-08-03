cmake_minimum_required(VERSION 3.24)

project(Heap_array LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(exec_name main)

add_compile_options(-Wall -Wextra -Wextra)
add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(tests)
