//
// Created by Pedro on 26-04-2020.
//

#ifndef PROJECT_2___SCRABBLE_JUNIOR_GAMEPLAY_H
#define PROJECT_2___SCRABBLE_JUNIOR_GAMEPLAY_H


#include "Game Text.h"
#include "Board.h"
#include "Player.h"
#include "Tile.h"


class Gameplay
{
public:
    Gameplay(int sizeX, int sizeY, std::vector<Word> &words);
    void startGame();

private:
    std::vector <char> tilePool;
    int sizeX, sizeY;
    std::vector <char> validTiles;
    Player player1, player2, player3, player4;
    Player players[4] = {player1, player2, player3, player4};   //const
    Board board = Board(sizeX, sizeY);
    int getWinner(int playerNumber);
    bool getGameState(int playerNumber);
    static void announceWinner(int winner);
    bool validateInput(int player, std::string position, char letter, int &x, int &y);
    void scoring(int player, int x, int y);
    std::tuple<int, int> playerInputs(int player);
    void distributeTiles(int playerNumber);
    void shuffleTilePool();
    void showPlayerInfo(int player, bool trade);
    void tradeTiles(int player);
    bool tradeNecessity(int player);
    void draw(int player, int maxDrawAmount);
    bool validateTrade(int player, char letter);
    void setValidTiles();
    bool nextTilePlayed(int x, int y, bool vertical);
    bool nextTileUnplayed(int x, int y, bool vertical);
    bool nextTileEmpty(int x, int y, bool vertical);
    bool previousTilePlayed(int x, int y, bool vertical);
    //bool previousTileUnplayed(int x, int y, bool vertical);
    bool previousTileEmpty(int x, int y, bool vertical);


};


#endif //PROJECT_2___SCRABBLE_JUNIOR_GAMEPLAY_H
