cmake_minimum_required(VERSION 3.26)
project(AssBag)

set(CMAKE_CXX_STANDARD 17)

add_executable(AssBag main.cpp
        BagInterface.h
        PlainBag.cpp
        PlainBag.h
        MagicChangeBag.cpp
        MagicChangeBag.h)
