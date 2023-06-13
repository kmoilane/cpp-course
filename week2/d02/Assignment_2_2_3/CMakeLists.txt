cmake_minimum_required(VERSION 3.24.2)

project(Adventure420)

add_subdirectory(src)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC includes)

target_link_libraries(${PROJECT_NAME} PUBLIC utils player board) # Lisää tiedostot
