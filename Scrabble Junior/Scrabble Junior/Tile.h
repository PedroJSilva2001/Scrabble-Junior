//
// Created by 35193 on 17/05/2020.
//

#ifndef SCRABBLE_JUNIOR_TILE_H
#define SCRABBLE_JUNIOR_TILE_H


#include "Game Text.h"
class Tile
{
public:
    Tile();
    Tile(char letter, int x, int y, bool available);
    bool getFilledState() const;
    void setFilledState(bool filled);
    char getLetter() const;
    int getX() const;
    int getY() const;
    bool getAvailable();
    void setAvailable(bool available);
    bool getEmptyState() const;
private:
    int x{};
    int y{};
    bool filled = false;
    char letter = ' ';
    bool available = false;

};


#endif //SCRABBLE_JUNIOR_TILE_H
