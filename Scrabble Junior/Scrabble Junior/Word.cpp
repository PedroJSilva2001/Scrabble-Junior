//
// Created by 35193 on 17/05/2020.
//

#include "Word.h"
Word::Word() = default;

Word::Word(std::string name, std::string position, char orientation)
{
    this->name = std::move(name);
    this->position = std::move(position);
    this->orientation = orientation;
}

std::string Word::getName() const
{
    return name;
}

std::string Word::getPosition() const
{
    return position;
}

char Word::getOrientation() const
{
    return orientation;
}