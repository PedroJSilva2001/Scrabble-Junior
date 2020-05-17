//
// Created by Pedro on 09-05-2020.
//

#ifndef PROJECT_2___SCRABBLE_JUNIOR_BOARD_H
#define PROJECT_2___SCRABBLE_JUNIOR_BOARD_H

#include "Game Text.h"
#include "Tile.h"
#include "Word.h"

class Board
{
public:
    Board(int sizeX, int sizeY);/*const std::vector<Word> &words*/
    void drawBoard();
    void setTile(Tile tile);
    std::vector<std::vector<Tile>> &getBoard();

private:
    int sizeX, sizeY;
    std::vector <std::vector <Tile>> board;
    void drawLimits();
    void gotoXY(int x, int y);
    void setColor(int color);

};


#endif //PROJECT_2___SCRABBLE_JUNIOR_BOARD_H
