//
// Created by Pedro on 11-05-2020.
//

#ifndef PROJECT_2___SCRABBLE_JUNIOR_WORD_H
#define PROJECT_2___SCRABBLE_JUNIOR_WORD_H

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


#endif //PROJECT_2___SCRABBLE_JUNIOR_WORD_H
