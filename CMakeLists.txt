cmake_minimum_required(VERSION 3.17)
project(Module3 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Module3
        BmpProcessor.c
        BmpProcessor.h
        main.c
        PixelProcessor.c
        PixelProcessor.h
        PpmProcessor.c
        PpmProcessor.h)
