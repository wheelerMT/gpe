cmake_minimum_required(VERSION 3.20)
project(gpe)

set(CMAKE_CXX_STANDARD 17)
set(SOURCES src/main.cpp src/grid.cpp)
set(INCLUDES include/constants.h include/grid.h)

include_directories(include/)

add_executable(gpe ${SOURCES} ${INCLUDES})
