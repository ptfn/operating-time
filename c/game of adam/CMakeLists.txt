cmake_minimum_required(VERSION 3.22.1)

project(adam)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "~/.local/bin")
add_executable(adam src/main.c)

target_link_libraries(adam ${SDL2_LIBRARIES})
