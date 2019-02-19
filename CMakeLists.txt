cmake_minimum_required(VERSION 3.9.6)
project(iot-challenge-two)

set(CMAKE_CXX_STANDARD 11)
cmake_policy(SET CMP0054 OLD)

file(GLOB_RECURSE sources
        /morsecode/source/*.h
        /morsecode/source/*.cpp)

file(GLOB_RECURSE project
        .gitignore
        morsecode/.yotta.json
        config.json
        LICENSE
        morsecode/Makefile
        morsecode/module.json
        README.md)

include_directories(yotta_modules/microbit/inc
        yotta_modules/microbit-dal/inc/bluetooth
        yotta_modules/microbit-dal/inc/core
        yotta_modules/microbit-dal/inc/drivers
        yotta_modules/microbit-dal/inc/platform
        yotta_modules/microbit-dal/inc/types
        yotta_modules/microbit-dal/source/asm
        yotta_modules/microbit-dal/source/bluetooth
        yotta_modules/microbit-dal/source/core
        yotta_modules/microbit-dal/source/drivers
        yotta_modules/microbit-dal/source/types
        yotta_modules/ble)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "build")

add_executable(iotmorsecode ${sources} morsecode/source/main.cpp)