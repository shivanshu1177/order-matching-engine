cmake_minimum_required(VERSION 3.10)
project(OrderMatchingEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Sources
file(GLOB SOURCES "src/*.cpp")

# Executable
add_executable(OrderMatchingEngine ${SOURCES})
