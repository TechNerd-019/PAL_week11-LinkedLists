cmake_minimum_required(VERSION 3.23)
project(PAL_week11_LinkedLists C)

set(CMAKE_C_STANDARD 11)

include_directories(LinkedLists)

add_executable(PAL_week11_LinkedLists
        LinkedLists/McDonalds.h
        LinkedLists/Source.c)
