cmake_minimum_required(VERSION 3.24.2)
    
project(TaggedUnion)

add_executable(${PROJECT_NAME} main.cpp)

add_compile_options(-Wall -Wextra -Werror -Wpedantic)

add_subdirectory(src)

target_include_directories(${PROJECT_NAME} PUBLIC includes)

target_link_libraries(${PROJECT_NAME} PUBLIC entity)
    
