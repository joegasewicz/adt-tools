cmake_minimum_required(VERSION 3.23)
project(libadttools C)

set(CMAKE_C_STANDARD 11)

add_library(libadttools adt_tools.h linked_list.c stack.c)
