#ifndef MENU_HPP
#define MENU_HPP
#include <string>
#include "Game.hpp"
using namespace std;
enum dificultades{
    FACIL = 7,
    INTERMEDIO = 5,
    DIFICIL = 3
};
void showWords(Menu *menu);
void choseDifficulty(Menu *menu,Game *game);
void addWord(Menu *menu);

#endif // MENU_HPP