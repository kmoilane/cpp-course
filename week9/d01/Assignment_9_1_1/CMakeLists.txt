cmake_minimum_required(VERSION 3.24.2)
    
project(calculator)

add_executable(ex1 ex1.cpp)
add_executable(${PROJECT_NAME} ex2.cpp)

add_subdirectory(src)

target_include_directories(ex1 PUBLIC includes)
target_include_directories(${PROJECT_NAME} PUBLIC includes)

target_link_libraries(ex1 PUBLIC math)
target_link_libraries(${PROJECT_NAME} PUBLIC math)
