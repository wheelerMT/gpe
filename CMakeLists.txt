cmake_minimum_required(VERSION 3.20)
project(gpe)

set(CMAKE_CXX_STANDARD 17)
set(SOURCES src/main.cpp src/grid.cpp)
set(INCLUDES include/constants.h include/grid.h)
SET(FFTW_PATH C:/dev/cpp/libs/fftw-3.3.5-dll64)

include_directories(${FFTW_PATH} include/)
link_directories(${FFTW_PATH})

add_executable(gpe ${SOURCES} ${INCLUDES})

target_link_libraries(${PROJECT_NAME} libfftw3-3.lib)
