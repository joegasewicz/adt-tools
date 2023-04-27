cmake_minimum_required(VERSION 3.23)
project(adt_tools C)

set(CMAKE_C_STANDARD 99)

add_library(
        adt_tools
        adt_tools.h
        linked_list.c
        stack.c
)
