cmake_minimum_required(VERSION 3.15)
project(Assignment3GPS C)

set(CMAKE_C_STANDARD 99)

add_executable(Assignment3GPS dcgps.c gps-utils.c gpsprint.c)