cmake_minimum_required(VERSION 3.25)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled1 main.c)
#set(INTERN_BUILD_ATEN_OPS OFF)
set (CMAKE_C_FLAGS "-march=native -mavx2")