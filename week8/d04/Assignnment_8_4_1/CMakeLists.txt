cmake_minimum_required(VERSION 3.24)
project(MyProject)

# Set C++ standard to C++20 or higher
set(CMAKE_CXX_STANDARD 20)

# Add include directories
include_directories(include)

# Add the main executable
add_executable(${PROJECT_NAME} main.cpp)

# Set the output directory for the main executable
set_target_properties(main_executable PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Add the test executable
add_executable(test_executable tests/test.cpp)

# Set the output directory for the test executable
set_target_properties(test_executable PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
)


# Add the include directories for the test executable
target_include_directories(test_executable PRIVATE test/includes)

# Download and include doctest.h
include(FetchContent)
FetchContent_Declare(
    doctest
    GIT_REPOSITORY https://github.com/onqtam/doctest.git
    GIT_TAG master
)
FetchContent_MakeAvailable(doctest)
    
#add_link_options(-fsanitize=address)
    
#add_compile_options(-fsanitize=address)
    
    
    