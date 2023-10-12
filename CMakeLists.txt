cmake_minimum_required(VERSION 3.26)
project(ASSIGNMENTBAG)

set(CMAKE_CXX_STANDARD 17)

add_executable(ASSIGNMENTBAG main.cpp
        BagInterface.h
        PlainBag.cpp
        PlainBag.h
        MagicChangeBag.cpp
        MagicChangeBag.h)
