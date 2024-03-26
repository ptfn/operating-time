cmake_minimum_required(VERSION 3.22.1)
project(status)

ADD_LIBRARY(STATUSLib STATIC status.c)

SET(APP status)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "~/.local/bin/")

ADD_EXECUTABLE(${APP} main.c) 

TARGET_LINK_LIBRARIES(${APP} STATUSLib)
