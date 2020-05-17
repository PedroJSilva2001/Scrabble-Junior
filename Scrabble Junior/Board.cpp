//
// Created by Pedro on 09-05-2020.
//

#include "Board.h"


Board::Board(int sizeX, int sizeY) {
    std::vector<Tile> column;

    this->sizeX = sizeX;
    this->sizeY = sizeX;

    for (int columnCount = 0;
         columnCount < sizeX; columnCount++) {//vetor de colunas -> tantas colunas quanto existem Xs

        for (int rowCount = 0; rowCount < sizeY; rowCount++) {
            Tile tile;
            column.push_back(tile);
        }
        board.push_back(column); //maisculas sao os Y;  minusculas sao os X   (Aa -> YX)
    }
}

void Board::drawLimits() {
    std::string s = "ABCDEFGHIJKLMNOPQRSTabcdefghijklmnopqrst";
    int vOffset = 5;
    int hOffset = 5;
    for (int i = 0; i < sizeX; i++) {
        int x = hOffset + 3 * i;
        gotoXY(x, 3);
        std::cout << "  " << s[i + 20] << "  ";
        gotoXY(x, 4);
        if (i == 0) {
            std::cout << " ___";
            gotoXY(x, vOffset + sizeY);
            std::cout << "____";
        } else if (i == 19) {
            std::cout << "____ ";
            gotoXY(x, vOffset + sizeY);
            std::cout << "____ ";
        } else {
            std::cout << "___";
            gotoXY(x, vOffset + sizeY/*+2*/);
            std::cout << "___";
        }

    }

    for (int j = 0; j </*=*/ sizeY + 1; j++) {
        int y = vOffset + j;
        gotoXY(1, y);

        if (j != sizeY/*+1*/)
            std::cout << s[j] << "   | ";

        else
            std::cout << ' ' << "   |";

        gotoXY(66, y);
        std::cout << "|";
    }


}

void Board::gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Board::setTile(Tile tile) {
    this->board[tile.getX()][tile.getY()] = tile;

}

std::vector<std::vector<Tile>> &Board::getBoard() {
    return board;
}

void Board::drawBoard() {
    drawLimits();
    for (int x = 0; x < sizeX; x++ ) {
        int x1 = 7 + 3*x;
        for (int y = 0; y < /*=*/ sizeY; y++) {
            int y1 = 5 + y;
            gotoXY(x1, y1);
            //cout << "a ";
            if(board[x][y].getFilledState()
                setColor(RED);
            std::cout << board[x][y].getLetter() << " ";
        }
    }
}

void setColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

}