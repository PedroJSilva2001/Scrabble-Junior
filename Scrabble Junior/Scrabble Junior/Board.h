//
// Created by 35193 on 17/05/2020.
//

#ifndef SCRABBLE_JUNIOR_BOARD_H
#define SCRABBLE_JUNIOR_BOARD_H

#include "Game Text.h"
#include "Tile.h"
#include "Word.h"

class Board
{
public:
    Board();
    Board(int sizeX, int sizeY);/*const std::vector<Word> &words*/
    void drawBoard();
    void setTile(Tile tile);
    std::vector<std::vector<Tile>> &getBoard();
    void setBoardDimensions(int sizeX, int sizeY);
    int getSizeX();
    int getSizeY();

private:
    int sizeX, sizeY;
    std::vector <std::vector <Tile>> board_;
    void drawLimits();
    void gotoXY(int x, int y);
    void setColor(int color);

};
#endif //SCRABBLE_JUNIOR_BOARD_H
