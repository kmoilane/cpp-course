cmake_minimum_required(VERSION 3.24.2)
    
project(bank_wallet_tests)

add_executable(${PROJECT_NAME} bank_wallet_tests.cpp)

add_subdirectory(../src [binary_dir][EXCLUDE_FROM_ALL])

target_include_directories(${PROJECT_NAME} PUBLIC includes ../includes [binary_dir][EXCLUDE_FROM_ALL])

target_link_libraries(${PROJECT_NAME} PUBLIC utils transactions)
