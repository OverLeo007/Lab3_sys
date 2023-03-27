cmake_minimum_required(VERSION 3.24)
project(Lab3 C)

set(CMAKE_C_STANDARD 99)

add_executable(Lab3 main.c list_src.c list_src.h country_src.h country_src.c inp_funcs.c inp_funcs.h ui_funcs.h ui_funcs.c ui_funcs.c)
