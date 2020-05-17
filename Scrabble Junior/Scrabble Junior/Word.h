//
// Created by 35193 on 17/05/2020.
//

#ifndef SCRABBLE_JUNIOR_WORD_H
#define SCRABBLE_JUNIOR_WORD_H


#include "Game Text.h"

class Word
{
public:
    Word();
    Word(std::string name, std::string position, char orientation);
    std::string getName() const;
    std::string getPosition() const;
    char getOrientation() const;

private:
    std::string name;
    std::string position;
    char orientation;

};


#endif //SCRABBLE_JUNIOR_WORD_H
