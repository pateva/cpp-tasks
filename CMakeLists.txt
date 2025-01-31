cmake_minimum_required(VERSION 3.10)
project(CppTasks)  

# Enable testing in CMake
enable_testing() 

# Add GoogleTest using FetchContent
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2  # Update this to the latest stable version
)
FetchContent_MakeAvailable(googletest)

# Add an executable target
add_executable(MainExecutable src/main.cpp)
target_link_libraries(MainExecutable PRIVATE gtest_main)

#include directories
target_include_directories(MainExecutable PRIVATE include/)

# Find all test files in the tests/ directory
file(GLOB TEST_SOURCES tests/data_structures/basics/*.cpp)

# Find all source files from the src/ directory
file(GLOB_RECURSE SRC_FILES src/**/*.cpp)

# Add a test executable
add_executable(AllTests ${TEST_SOURCES} ${SRC_FILES})

# Include GoogleTest headers
target_include_directories(AllTests PRIVATE ${googletest_SOURCE_DIR}/googletest/include)

# Include directories for the test executable
target_include_directories(AllTests PRIVATE include/)

# Link GoogleTest to the test executable
target_link_libraries(AllTests PRIVATE gtest_main)

# Register the tests with CTest
add_test(NAME RunAllTests COMMAND AllTests)


