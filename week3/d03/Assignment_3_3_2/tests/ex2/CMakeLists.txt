cmake_minimum_required(VERSION 3.24.2)
    
project(Assignment_3_3_2_tests)

add_executable(${PROJECT_NAME} string_utility_tests.cpp)

add_subdirectory(./../../src [binary_dir][EXCLUDE_FROM_ALL])

target_include_directories(${PROJECT_NAME} PUBLIC ../../includes ../includes [binary_dir][EXCLUDE_FROM_ALL])

target_link_libraries(${PROJECT_NAME} PUBLIC string_utility)
