cmake_minimum_required(VERSION 3.10)
project(AeroRedisServer)

# Required for lsp support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include ASIO headers
include_directories(${CMAKE_SOURCE_DIR}/libs/asio/asio/include)

# Add your source files
set(SOURCES src/main.cpp)

# Add your executable
add_executable(AeroRedisServer ${SOURCES})
