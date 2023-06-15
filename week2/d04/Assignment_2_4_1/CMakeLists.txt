cmake_minimum_required(VERSION 3.24.2)

project(fileguy)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(src externals/cxxopts)

target_include_directories(${PROJECT_NAME} PUBLIC includes external/cxxopts/include)

target_link_libraries(${PROJECT_NAME} PUBLIC print_file line_count word_count char_count dir_size)
