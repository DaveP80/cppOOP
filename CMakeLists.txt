cmake_minimum_required(VERSION 3.18.4)
project(CMakeTutorial
    VERSION 1.0
    DESCRIPTION "A CMake Tutorial"
    LANGUAGES CXX)

file(GLOB MAIN "leet/lettercombination.cpp")

add_executable(executable ${MAIN})