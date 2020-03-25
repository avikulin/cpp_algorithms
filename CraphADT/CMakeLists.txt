cmake_minimum_required(VERSION 3.5)

project(CraphADT LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(interfaces)

add_executable(CraphADT main.cpp
                        interfaces/base_vertex.cpp)
