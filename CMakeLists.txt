cmake_minimum_required(VERSION 3.22)
project(queue_compare LANGUAGES CXX)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(googletest)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set compiler flags after including external dependencies.
string(APPEND CMAKE_CXX_FLAGS " ${PROJECT_CXX_FLAGS}")

add_library(two_stack_queue two_stack_queue.h)
target_include_directories(two_stack_queue INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(two_stack_queue PROPERTIES LINKER_LANGUAGE CXX)

enable_testing()

add_executable(queue_test queue_test.cpp)
target_link_libraries(queue_test two_stack_queue gtest gmock gtest_main)
gtest_discover_tests(queue_test)
