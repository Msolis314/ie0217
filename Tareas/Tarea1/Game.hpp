#include <string>
using namespace std;
#ifndef GAME_HPP
#define GAME_HPP
#define MAX_WORDS 100

struct Game
{
    string wordToGuess;
    string emptyWord;
    string filledWord;
    int tries =0;
    int maxTries;
};

struct Menu {
    string palabrasrandom[MAX_WORDS]={"hola","mundo","c++","programacion","lenguaje"};
    int numWords = 5;
    int dificultad = 7;
};


#endif // GAME_HPP

