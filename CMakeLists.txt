cmake_minimum_required(VERSION 3.28)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 23)

add_executable(TicTacToe main.cpp
        src/ttt.h
        src/ttt.cpp)
