cmake_minimum_required(VERSION 3.10)
project(AeroRedisServer)

# Include ASIO from the submodule directory
add_subdirectory(libs/asio)

# Add your source files
set(SOURCES
    src/main.cpp
)

# Add your executable
add_executable(AeroRedisServer ${SOURCES})

# Link ASIO
target_link_libraries(AeroRedisServer PRIVATE asio)
