cmake_minimum_required(VERSION 3.22.1)

project(infinity-code)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "~/.local/bin")

add_executable(infinity src/infinity.c)
target_link_libraries(infinity ${CURSES_LIBRARIES})

