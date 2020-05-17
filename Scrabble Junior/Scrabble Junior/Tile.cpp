//
// Created by Pedro on 07-05-2020.
//

#include "Tile.h"

Tile::Tile() = default;

Tile::Tile(char letter, int x, int y, bool available) {
    this -> letter = letter;
    this -> x = x;
    this -> y = y;
    this -> available = available;
}

char Tile::getLetter() const {
    return letter;
}

int Tile::getX() const {
    return x;
}

int Tile::getY() const {
    return y;
}

void Tile::setFilledState(bool filled) {
    this -> filled = filled;
}

bool Tile::getFilledState() const {
    return filled;
}

bool Tile::getAvailable() {
    return available;
}

void Tile::setAvailable(bool available) {
    this -> available = available;
}

bool Tile::getEmptyState() const{
    return letter == ' ';
}

