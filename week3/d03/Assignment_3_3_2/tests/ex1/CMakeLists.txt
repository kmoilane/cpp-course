cmake_minimum_required(VERSION 3.24.2)
    
project(Assignment_3_3_2_tests)

add_executable(${PROJECT_NAME} math_functions_tests.cpp)

add_subdirectory(./../../src [binary_dir][EXCLUDE_FROM_ALL])

target_include_directories(${PROJECT_NAME} PUBLIC ../../includes ../../externals [binary_dir][EXCLUDE_FROM_ALL])

target_link_libraries(${PROJECT_NAME} PUBLIC math_functions)
