cmake_minimum_required(VERSION 3.23)
project(C_FAMTREE C)

set(CMAKE_C_STANDARD 23)

include_directories(inc)

add_executable(C_FAMTREE
        inc/clearbuffer.c
        inc/clearbuffer.h
        main.c)
