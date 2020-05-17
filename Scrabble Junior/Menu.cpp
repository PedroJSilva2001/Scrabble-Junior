//
// Created by Pedro on 17-05-2020.
//

#include "Menu.h"

void readFile(bool tradeBoard){
    std::string filePath;
    int fileWord = 0;
    char dataRow[21];
    std::ifstream data;
    std::vector<std::string> positions;
    std::vector<char> orientations;
    std::vector<std::string> names;
    int sizeX = 0, sizeY = 0;
    std::vector <Word> words;

    if(!tradeBoard)
        std::cout << welcome << std::endl;
    std::cout << file << std::endl;
    std::getline(std::cin, filePath);
    data.open(filePath + ".txt");
    while (!data.is_open()) {
        std::cerr << error_msg << error_msg_file << std::endl;
        std::cerr << retry << std::endl;
        getline(std::cin, filePath);
    }
    while (!data.eof()) {
        data >> dataRow;
        if (fileWord < 3) {
            if (fileWord == 0)
                sizeX = dataRow[0] - '0';
            else if (fileWord == 2)
                sizeY = dataRow[0] - '0';
        } else {
            if (fileWord % 3 == 0)
                positions.emplace_back(dataRow);
            else if (fileWord % 3 == 1)
                orientations.push_back(dataRow[0]);
            else if (fileWord % 3 == 2)
                names.emplace_back(dataRow);
        }
        fileWord++;
    }
    for (int i = 0; i < names.size(); i++)   //set words_
    {
        Word word = Word(names[i], positions[i], orientations[i]);
        words.push_back(word);
    }
    scrabbleMenu(sizeX, sizeY, words);

}

/*void f(){

    Word word1 = Word("LAST", "Aa", 'H');
    Word word2 = Word("SAVE", "Cb", 'H');
    Word word3 = Word("HELL", "Eb", 'H');
    Word word4 = Word("ASS", "Ab", 'V');
    Word word5 = Word("AVE", "Cc", 'V');
    Word word6 = Word("BELL", "Be", 'V');
    std::vector<Word> words;
    words.resize(50);
    words.push_back(word1);
    words.push_back(word2);
    words.push_back(word3);
    words.push_back(word4);
    words.push_back(word5);
    words.push_back(word6);

    scrabbleMenu(5,5,words);

}*/

void scrabbleMenu(int sizeX, int sizeY, std::vector <Word> &words) {
    bool gameIsRunning = true;
    int continueGame = 1;
    int changeBoard = 1;
    bool tradeBoard = true;

    while(gameIsRunning) {
        Gameplay game = Gameplay(sizeX, sizeY, words);
        game.startGame();
        std::cout << play_again << std::endl;
        std::cin >> continueGame;
        while(std::cin.fail() || continueGame < 0  || continueGame > 1)
        {
            //if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10, ' ');
            //}
            std::cout << error_msg << error_msg11 << std::endl;
            std::cin >> continueGame;
        }

        if (!continueGame) {
            std::cout << end_msg;
            break;
        }

        else {
            std::cout << change_board << std::endl;
            std::cin>>changeBoard;

            while(std::cin.fail() || changeBoard <0 || changeBoard > 1) {
                //if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(10, ' ');
                //}
                std::cout << error_msg << error_msg12 << std::endl;
                std::cin >> changeBoard;
            }

            if(changeBoard)
               readFile(tradeBoard);
        }
    }
}