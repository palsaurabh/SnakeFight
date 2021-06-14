# Game SnakeFight (Multiplayer)

This repository contains the extended version of Snake Game as provided by Udacity for Final project in the CPP Nanodegree program.
![image](https://user-images.githubusercontent.com/5771813/121066724-d59ad900-c7e7-11eb-8fa4-a1728ff1831b.png)

# Dependencies:
1. SDL2 library
    Install SDL2 library using apt: 
    $ sudo apt install libsdl2-dev
2. CMake
    Cmake Minimum version required is 3.19.0
    Install from apt or download from official cmake website: https://cmake.org/download/
    or
    $sudo apt install cmake

# Build Instructions
1. Linux
    a. This project can be built and run on Ubuntu Linux.
    b. After installing the dedpendencies follow the following steps:
        1. create diectory 'build' in the project folder.
        2. cd build
        3. cmake ../
        4. cd /build/output/bin/
        5. ./SnakeFight (Will launch the game)

# Controls
1. Player 1 plays with arrow keys 
2. Player 2 plays with 'w', 'a', 's', 'd' keys

# Modes
1. Eating Mode: Food catching competition. The more food is eaten, the faster the snake.
2. Fight Mode: Each snake can eat/cut-off the portions of other snake and earn the points. Snake with the highest points at the end of countdown wins.
