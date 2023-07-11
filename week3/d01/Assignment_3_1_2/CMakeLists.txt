cmake_minimum_required(VERSION 3.24.2)
    
project(sweater_weather)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(src)

target_include_directories(${PROJECT_NAME} PUBLIC includes)

target_link_libraries(${PROJECT_NAME} PUBLIC generate_data utils weather_checks)
