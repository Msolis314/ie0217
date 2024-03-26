#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <string>
#include "Game.hpp"

void guess(Game *game);
bool checkWin(Game *game);
void spacedWord(Game *game);
void beginGame(Game *game,string wordsDict[],int maxTries,int lenght);
std::string getWord(std::string wordsDict[],int lenght);
#endif // FUNCIONES_H