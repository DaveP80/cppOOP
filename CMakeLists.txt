cmake_minimum_required(VERSION 3.18.4)
project(CMakeTutorial
    VERSION 1.0
    DESCRIPTION "A CMake Tutorial"
    LANGUAGES CXX)

set(CMAKE_CXX_FLAGS -pthread)

file(GLOB MAIN "src/*")
find_package(Threads REQUIRED)
add_executable(executable ${MAIN})