#ifndef MENU_HPP
#define MENU_HPP
#include <string>
#include "Game.hpp"

using namespace std;

/// @brief Enum para el menu
enum dificultades{
    FACIL = 7,
    INTERMEDIO = 5,
    DIFICIL = 3
};

/// @brief Funcion para mostrar las palabras del arreglo
/// @param menu 
void showWords(Menu *menu);

/// @brief Funcion para elegir la dificultad del juego
/// @param menu puntero a la estructura Menu
/// @param game puntero a la estructura Game
void choseDifficulty(Menu *menu,Game *game);

/// @brief Funcion para agregar una palabra al arreglo
/// @param menu puntero a la estructura Menu
void addWord(Menu *menu);

#endif // MENU_HPP