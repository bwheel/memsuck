cmake_minimum_required(VERSION 3.10)

project(memsuck)
set(CMAKE_BUILD_TYPE Debug)

find_package(cxxopts CONFIG REQUIRED)

add_executable(memsuck main.cpp)

target_link_libraries(memsuck PRIVATE cxxopts::cxxopts)