cmake_minimum_required(VERSION 3.22.1)
project(sha256)

add_compile_options(-Wall -Werror)
ADD_LIBRARY(sha2lib STATIC sha256.c)

SET(APP main)

ADD_EXECUTABLE(${APP} main.c) 

TARGET_LINK_LIBRARIES(${APP} sha2lib)