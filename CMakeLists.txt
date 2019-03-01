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
        morsecode/config.json
        LICENSE
        morsecode/Makefile
        morsecode/module.json
        README.md)

include_directories(morsecode/yotta_modules/mbed-classic/targets/hal/TARGET_NORDIC/TARGET_MCU_NRF51822/TARGET_NRF51_MICROBIT
        morsecode/yotta_modules/mbed-classic/api
        morsecode/yotta_modules/microbit/inc
        morsecode/yotta_modules/microbit-dal/inc/bluetooth
        morsecode/yotta_modules/microbit-dal/inc/core
        morsecode/yotta_modules/microbit-dal/inc/drivers
        morsecode/yotta_modules/microbit-dal/inc/platform
        morsecode/yotta_modules/microbit-dal/inc/types
        morsecode/yotta_modules/microbit-dal/source/asm
        morsecode/yotta_modules/microbit-dal/source/bluetooth
        morsecode/yotta_modules/microbit-dal/source/core
        morsecode/yotta_modules/microbit-dal/source/drivers
        morsecode/yotta_modules/microbit-dal/source/types
        morsecode/yotta_modules/ble)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "build")

add_executable(iotmorsecode ${sources} morsecode/source/main.cpp morsecode/source/defs.h morsecode/source/Cipher.cpp morsecode/source/Cipher.h)