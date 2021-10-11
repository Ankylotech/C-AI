cmake_minimum_required(VERSION 3.20)
project(C_AI C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(C_AI main.c game_type.c game_type.h tic_tac_toe.c tic_tac_toe.h ai.c ai.h)
