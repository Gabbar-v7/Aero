cmake_minimum_required(VERSION 3.10)
project(AeroRedisServer)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include ASIO headers
include_directories(${CMAKE_SOURCE_DIR}/libs/asio/asio/include)

# Add your source files
set(SOURCES src/main.cpp)

# Add your executable
add_executable(AeroRedisServer ${SOURCES})
