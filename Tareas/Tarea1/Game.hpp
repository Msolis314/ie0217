#include <string>
using namespace std;
#ifndef GAME_HPP
#define GAME_HPP
struct Game
{
    string wordToGuess;
    string emptyWord;
    string filledWord;
    int tries =0;
    int maxTries;
};


#endif // GAME_HPP

