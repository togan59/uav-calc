cmake_minimum_required(VERSION 3.27)
project(uav_calc)

set(CMAKE_CXX_STANDARD 17)

add_executable(uav_calc test.cpp
        src/lib/atmosphere/air_properties.cpp
        src/lib/atmosphere/air_properties.h
)
