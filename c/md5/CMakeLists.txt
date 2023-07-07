cmake_minimum_required(VERSION 3.22.1)
project(md5)

ADD_LIBRARY(MD5Lib STATIC md5.c)

SET(APP main)

ADD_EXECUTABLE(${APP} main.c) 

TARGET_LINK_LIBRARIES(${APP} MD5Lib)