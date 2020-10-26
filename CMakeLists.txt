cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_FLAGS "-pedantic -Wall -Wextra -Werror")

set(CMAKE_CXX_STANDART 17)

project(oop_lab3)

add_executable(oop_exercise_03 vertex.cpp hexagon.cpp octagon.cpp triangle.cpp main.cpp)