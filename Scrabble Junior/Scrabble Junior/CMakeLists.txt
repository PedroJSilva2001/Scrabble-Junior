cmake_minimum_required(VERSION 3.15)
project(Scrabble_Junior)

set(CMAKE_CXX_STANDARD 17)

add_executable(Scrabble_Junior main.cpp Board.cpp Board.h "Game Text.h" Gameplay.cpp Gameplay.h Player.h Tile.cpp Tile.h Word.cpp Word.h Menu.cpp Menu.h)