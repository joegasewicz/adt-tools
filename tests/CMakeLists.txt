cmake_minimum_required(VERSION 3.23)
project(tests C)

set(CMAKE_C_STANDARD 11)
set(CHECK_INSTALL_DIR "/opt/homebrew/Cellar/check/0.15.2")
#set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/check/0.15.2")
#set(Check_DIR "/opt/homebrew/Cellar/check/0.15.2")
#set(CMAKE_INSTALL_PREFIX /opt/homebrew/Cellar)
#set(CMAKE_PREFIX_PATH /opt/homebrew/Cellar)

find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})
link_directories(${CHECK_LIBRARY_DIRS})

add_executable(adt_tools_test.c)

add_library(tests library.c)

target_link_libraries(tests ${CHECK_LIBRARIES})