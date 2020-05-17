//
// Created by 35193 on 17/05/2020.
//

#include "Gameplay.h"
Gameplay::Gameplay(int sizeX, int sizeY, std::vector<Word> &words) {
    int x, y;
    char xCh, yCh;
    char position[2];
    bool available;
    std::vector <std::string> positions;

    this->sizeX = sizeX;
    this->sizeY = sizeY;

    for (auto &word: words) {  //comparação com codigo ASCII visto que as letras nesse codigo estão todas seguidas
        x = word.getPosition()[1] -'a';
        y = word.getPosition()[0] - 'A';
        xCh = x + 'a';
        yCh = y + 'A';
        for (int letter = 0; letter < word.getName().size(); letter++)  //percorrer as letras de uma palavra
        {
            available = letter == 0;
            //pôr todas as letras das palavras na tile pool
            if (word.getOrientation() == 'H') {  //na horizantal o que varia é a coordenada x das letras
                x += letter; xCh += letter;
            }
            else {  //orientação vertical - varia a coordenada y das letras
                y += letter; yCh += letter;
            }
            position[0] = yCh; position[1] = xCh;
            if (!binary_search(positions.begin(), positions.end(), position)) {
                tilePool.push_back(word.getName()[letter]);

                Tile tile = Tile(word.getName()[letter], x, y, available);    //nao é necessario impedir a criação de uma peça numa posicao do tabuleiro já com peça porque essas duas peças possuem a mesma informação
                board.setTile(tile);    //pôr os objetos tile no tabuleiro              //porem isto é capaz ser mais efieciente
            }
            positions.emplace_back(position);
        }
    }
}


void Gameplay::startGame() {
    int playerNumber, winner;
    int playedAmount = 0;
    bool gameEnded = false;
    tuple input;

    std::cout << player_num << std::endl;
    std::cin >> playerNumber;

    while (std::cin.fail() || playerNumber < 2 ||
           playerNumber > 4) {
        std::cin.clear();
        std::cin.ignore(20, ' ');
        std::cerr << error_msg << error_msg10 << std::endl;
        std::cerr << retry << std::endl;
        std::cin >> playerNumber;
    }
    board.drawBoard();
    distributeTiles(playerNumber);
    while (!gameEnded) {
        for (int player = 0; player < playerNumber; player++) {
            for (int plays = 1; plays <= 2; plays++) {
                if (tradeNecessity(player) && playedAmount == 0) {
                    tradeTiles(player);
                    break;
                } else if (tradeNecessity(player) /*&& drawAmount == 1*/)
                    break;
                input = playerInputs(player);
                playedAmount++;            //played amount igual a draw amount portanto se ele joga uma vez, ele tira uma vez
                scoring(player, std::get<0>(input),
                        std::get<1>(input));
                board.drawBoard();
            }
            draw(player, playedAmount);      //passa-se como parametro o playedAmount para ver quantas draws sao precisas
            playedAmount = 0;
            gameEnded = getGameState(playerNumber);
        }
    }
    winner = getWinner(playerNumber);
    announceWinner(winner);
}

void Gameplay::distributeTiles(int playerNumber) {
    int tilesPerPlayer;

    shuffleTilePool();

    for (int player = 0; player < playerNumber; player++) {
        tilesPerPlayer = 7;
        while (tilesPerPlayer) {
            players[player].tiles.push_back(tilePool[0]);
            tilePool.erase(tilePool.begin());
            tilesPerPlayer--;
        }
    }
    std::cout << distributed1 <<  playerNumber+1 << distributed2;
    getch(); system("cls");
}

void Gameplay::shuffleTilePool() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    for (int i = 0; i < 2; i++) {    //fazer shuffle duas vezes já que a lista é grande
        std::shuffle(tilePool.begin(), tilePool.end(),
                     std::default_random_engine(seed));
    }
}

bool Gameplay::tradeNecessity(int player) {

    bool needsTrade = false;
    setValidTiles();
    for (auto &letter: players[player].tiles) {
        needsTrade |= std::binary_search(validTiles.begin(),
                                         validTiles.end(), letter);
    }

    if (needsTrade && tilePool.empty()) {
        std::cout << empty_pool << skipped;
        needsTrade = false;
    }
    return needsTrade;
}

void Gameplay::setValidTiles() {

    for (std::vector<Tile> &column: board.getBoard()) {
        for (Tile &tile: column) {
            if (!tile.getFilledState() && tile.getLetter() != ' ')
                validTiles.push_back(tile.getLetter());
        }
    }
}


void Gameplay::tradeTiles(int player) {
    char removedLetter = 'A';
    bool validTrade = false;
    int tradeAmount = 2;
    bool tradedOne = false;

    if (tilePool.size() == 1)
        tradeAmount = 1;
    else if (tilePool.empty())
        tradeAmount = 0;

    while (tradeAmount)
    {
        showPlayerInfo(player, true);
        if (!tradedOne)
            std::cout << player_str << player+1 << no_valid << trade_give;
        else
            std::cout << trade_give2;

        while (!validTrade) {
            std::cin >> removedLetter;
            validTrade = validateTrade(player, removedLetter);
        }
        tradeAmount--;
        players[player].tiles.push_back(tilePool[0]); //o jogador recebe as letras da pool
        std::cout << tilePool[0] << added << std::endl;
        tilePool.erase(tilePool.begin());
        std::cout << removedLetter << removed << std::endl;
        players[player].tiles.erase(
                std::find(players[player].tiles.begin(), players[player].tiles.end(), removedLetter));
        tilePool.push_back(removedLetter);     //a pool recebe a letra que o jogador escolhe
        tradedOne = true;

    }

    std::cout << player_str << player+1 << skipped << std::endl;
}

void Gameplay::showPlayerInfo(int player, bool trade) {
    if(!trade)
        std::cout << player_str << player+1<< player_tiles;
    for (char &tile: players[player].tiles) {
        std::cout << ' ' << tile;
    }
    std::cout << std::endl;

    if (!trade)
        std::cout << player_str << player+1<< points1 <<
                  players[player].score << points2;
}


bool Gameplay::validateTrade(int player, char letter) {
    bool validTrade = false;

    if (!std::binary_search(players[player].tiles.begin(),
                            players[player].tiles.end(), letter)){
        std::cerr << error_msg << error_msg2 << std::endl;
        std::cerr << retry << std::endl;
    } else
        validTrade = true;

    return validTrade;
}





std::tuple<int, int> Gameplay::playerInputs(int player) {
    std::string boardPosition;
    char pickedLetter;
    bool validInput = false;
    int x, y;

    std::cout << input_format << std::endl;
    getch();
    system("cls");
    showPlayerInfo(player, false);
    std::cout << player_str << player+1 << player_input1;

    while (!validInput) {
        std::cin >> pickedLetter >> boardPosition;
        std::cin.ignore(10, ' ');
        validInput |= validateInput(player, boardPosition, pickedLetter, x, y);   //sao passados como referencia para nao ter que converter a string para x e y duas vezes
    }

    tuple coordinates(x, y);
    players[player].tiles.erase(std::find(players[player].tiles.begin(),
                                          players[player].tiles.end(), pickedLetter));
    board.getBoard()[x][y].setFilledState(true);
    board.getBoard()[x][y].setAvailable(false);
    return coordinates;
}




bool Gameplay::validateInput(int player, std::string position, char letter, int &x, int &y) {
    bool validInput = false;

    if (position.length() != 2)     //format is Aa - 2 char
        std::cerr << error_msg << error_msg1 << std::endl;

    if (!std::binary_search(players[player].tiles.begin(), players[player].tiles.end(), letter))  //algorithm to check if the player has that letter with him
        std::cerr << error_msg << error_msg2 << std::endl;

    if (position.length() == 2) {

        if (!isalpha(position[0]) || !isalpha(position[1]))             //algorithm to check if they only use letters
            std::cerr << error_msg << error_msg3 << std::endl;

        if (islower(position[0]) || isupper(position[1]))     //checking if the first letter is upper and second letter is lower
            std::cerr << error_msg << error_msg4 << std::endl;

        else {
            x = position[1] - 'a';  //comparação com codigo ASCII visto que as letras nesse codigo estão todas seguidas
            y = position[0] - 'A';    // a partir deste codigo é suposto as inputs estarem na forma "Aa" portanto é so ver a logica das tiles

            if (x > sizeX - 1 || y > sizeY - 1) {
                //x < 0 || y < 0  seria preciso ver estes casos mas isso nao aconteceria  com as condicoes todas anteriores, que os filtram
                std::cerr << error_msg << error_msg5_1;
                std::cerr << error_msg5_2 << char('A'+sizeY-1) << error_msg5_3 << char('a'+sizeX-1)
                          << error_msg5_4 << std::endl;
            }

            else if (board.getBoard()[x][y].getEmptyState())
                std::cerr << error_msg6 << std::endl;

            else if (board.getBoard()[x][y].getFilledState())
                std::cerr << error_msg7 << std::endl;

            else if (!board.getBoard()[x][y].getAvailable())//aqui tmb seria necessário fazer && !getEmptystate porque todas as tiles vazias estao not available mas isso é filtrado pelo antepenultimo else if a este
                std::cerr << error_msg8 << std::endl;

            else if (board.getBoard()[x][y].getLetter() != letter)
                std::cerr << error_msg9 << std::endl;

            else
                validInput = true;
        }
    }
    if (!validInput)
        std::cerr << retry << std::endl;

    return validInput;
}




void Gameplay::scoring(int player, int x, int y) {
    bool vertical = true;
    int points = 0;
    for(int orientation = 0; orientation < 2; orientation++) {  //trocar de orientacoes
        if (nextTilePlayed(x, y, vertical)) {
            if (vertical) {
                if (nextTileEmpty(x + 1, y, vertical)) {
                    points++;
                    vertical = false;
                    break;
                }
                if (nextTileUnplayed(x + 1, y, vertical))
                    board.getBoard()[x + 2][y].setAvailable(true);
            } else {
                if (nextTileEmpty(x, y + 1, vertical)) {
                    points++;
                    vertical = false;
                    break;
                }
                if (nextTileUnplayed(x, y + 1, vertical))
                    board.getBoard()[x][y + 2].setAvailable(true);
            }
        }

        if (nextTileEmpty(x, y, vertical)) {
            if (previousTilePlayed(x, y, vertical)) {
                points++;
                vertical = false;
                break;
            }
        }

        if (nextTileUnplayed(x, y, vertical)) {
            if (previousTilePlayed(x, y, vertical) || previousTileEmpty(x, y, vertical)) {
                if (vertical)
                    board.getBoard()[x+1][y].setAvailable(true);
                else
                    board.getBoard()[x][y+1].setAvailable(true);
            }
        }
        vertical = false;
    }
    std::cout << player_str << player+1 << gained_points_1 <<
              points <<  gained_points_2 << std::endl;
    players[player].score += points;
}




bool Gameplay::nextTilePlayed(int x, int y, bool vertical) {
    if (vertical) {
        if (x == sizeY-1)   //rows
            return false;
        else
            x++;
    }
    else {
        if (y == sizeX-1)
            return false;
        else
            y++;
    }

    return board.getBoard()[x][y].getFilledState();
}

bool Gameplay::nextTileUnplayed(int x, int y, bool vertical) {
    if (vertical){
        if (x == sizeY - 1)
            return false;
        else
            x++;
    }
    else {
        if (y == sizeX - 1)
            return false;
        else
            y++;
    }
    return !board.getBoard()[x][y].getFilledState() && !board.getBoard()[x][y].getAvailable() && !board.getBoard()[x][y].getEmptyState() ;
}

bool Gameplay::nextTileEmpty(int x, int y, bool vertical) {
    if (vertical) {
        if (x == sizeY - 1)
            return true;
        else
            x++;
    }
    else {
        if (y == sizeX - 1)
            return true;
        else
            y++;
    }
    return board.getBoard()[x][y].getEmptyState();
}

bool Gameplay::previousTilePlayed(int x, int y, bool vertical) {
    if (vertical) {
        if (x == 0)
            return false;
        else
            x--;
    }
    else {
        if (y == 0)
            return false;
        else
            y--;
    }

    return board.getBoard()[x][y].getFilledState();
}


bool Gameplay::previousTileEmpty(int x, int y, bool vertical) {
    if (vertical) {
        if (x == 0)
            return true;
        else
            x--;
    }
    else {
        if (y == 0)
            return true;
        else
            y--;
    }
    return board.getBoard()[x][y].getEmptyState();
}


void Gameplay::draw(int player, int drawAmount) {

    if (!tilePool.empty())
        std::cout << pool_empty << std::endl;

    while (!tilePool.empty() && drawAmount) {
        drawAmount--;
        players[player].tiles.push_back(tilePool[0]);
        std::cout << player_str << player << tilePool[0] << added << std::endl;
        tilePool.erase(tilePool.begin());
    }
}


bool Gameplay::getGameState(int playerNumber) {
    bool gameEnded = true;
    for (int i = 0; i < playerNumber; i++) {
        gameEnded &= players[i].tiles.empty();
    }
    if (gameEnded)
        std::cout << gameEnded;
    return gameEnded;
}


int Gameplay::getWinner(int playerNumber) {
    int winner = 0;
    for (int player = 1; player < playerNumber; player++) {
        if (players[player].score > players[winner].score) {
            winner = player;
        }
    }
    return winner;
}

void Gameplay::announceWinner(int winner) {
    std::cout << player_str << winner + 1<< win;
}