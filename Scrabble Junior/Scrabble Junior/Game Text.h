//
// Created by Pedro on 30-04-2020.
//

#ifndef PROJECT_2___SCRABBLE_JUNIOR_GAME_TEXT_H
#define PROJECT_2___SCRABBLE_JUNIOR_GAME_TEXT_H

#include <string>
#include <vector>
#include <iostream>
#include <windows.h>   //gotoxy
#include <cstdio>    //system cls
#include <conio.h>   //getch
#include <algorithm>   //std::find; std::shuffle ; std::binary_search
#include <random>      // std::default_random_engine
#include <chrono>       //std::chrono::system_clock
#include <cctype>            //is lower is upper
#include <fstream>   //read file
#include <tuple>












#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14






typedef std::tuple<int, int> tuple;
#define input_format "The input format for the position in the board should be the following: Aa (column in uppercase and line in lowercase)"
#define player_str "Player "
#define player_input1 ", choose the letter you want to place in the board and the position you want to play it in."
#define win " won!"
#define error_msg "Error: "
#define error_msg1 "Input needs to be two letters long."
#define error_msg2 "You don't possess that letter with you."
#define error_msg3 "You may only use letters from the latin alphabet."
#define error_msg4 "The first and second letter need to be upper cased and lower cased, respectively."
#define error_msg5_1 "Incorrect dimensions. "
#define error_msg5_2 "You may only use letters from A to "
#define error_msg5_3 " and letters from a to "
#define error_msg5_4 "."
#define error_msg6 "There is no letter on that tile."
#define error_msg7 "That tile has already been filled."
#define error_msg8 "That tile is not yet available to be filled."
#define error_msg9 "Your letter does not match with the tile's letter"
#define error_msg10 "Number of players must be an integer from 2 to 4."
#define error_msg11 "Once again, press 1 to play again, 0 to end."
#define error_msg12 "Once again, press 1 to change board, 0 to keep using the same board."
#define error_msg_file "That's not a valid file."
#define invalid_trade "You can't choose those tiles."
#define player_tiles " you have the following letters:"
#define player_num "How many players will be playing? (pick a number from 2 to 4)"
#define retry "Try again."
#define trade_give " choose a piece you want to put in the tile pool:"
#define file "Type the name of the file where the game board you want to play is, no extension needed:"
#define added " has been added to your hand."
#define and_msg " and "
#define removed " has been removed from your hand."
#define pool_empty "You can't draw anymore, the pool has no more tiles"
#define points1 " you have "
#define points2 " points"
#define empty_pool "You needed to trade but the tile pool is empty."
#define skipped " Your turn will now be skipped!"
#define gained_points_1 "You have gained "
#define gained_points_2 " this turn."
#define welcome "Welcome to scrabble jr programmed in C++!"
#define play_again "Do you want to play again? Press 1 for yes, 0 for no."
#define change_board "Now, if you want to use another board press 1, if you want to play with the same board press 0."
#define distributed1 "7 tiles have been distributed for all "
#define distributed2 " players."
#define end_msg "Thanks for playing the game. I hope I get a full mark on this one!! :))"
#endif //PROJECT_2___SCRABBLE_JUNIOR_GAME_TEXT_H
