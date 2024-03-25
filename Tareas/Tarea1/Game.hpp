#include <string>
using namespace std;
#ifndef GAME_HPP
#define GAME_HPP
struct Game
{
    string wordToGuess;
    string emptyWord;
    string filledWord;
    int tries;
    int maxTries;
};

void guess(Game *game);
bool checkWin(Game *game);
void spacedWord(Game *game);

#endif // GAME_HPP

