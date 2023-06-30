cmake_minimum_required(VERSION 3.24.2)
    
project(Assignment_3_3_2)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(src)

target_include_directories(${PROJECT_NAME} PUBLIC includes)

target_link_libraries(${PROJECT_NAME} PUBLIC math_functions string_utility)
