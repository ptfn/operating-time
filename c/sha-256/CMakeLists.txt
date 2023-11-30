cmake_minimum_required(VERSION 3.22.1)
project(sha256)

ADD_LIBRARY(SHA256Lib STATIC sha256.c)

SET(APP main)

ADD_EXECUTABLE(${APP} main.c) 

TARGET_LINK_LIBRARIES(${APP} SHA256Lib)