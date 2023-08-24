add_executable(tests heap_array_tests.cpp)
target_include_directories(tests PUBLIC ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tests/includes/doctest)
