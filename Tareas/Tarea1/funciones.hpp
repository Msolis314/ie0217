#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <string>
#include "Game.hpp"

/// @brief Funcion para pedir ingresar una letra y compararla con la palabra a adivinar
///
/// @param game Puntero a la estructura Game
/// @return void 
void guess(Game *game);

/// @brief Funcion que revisa si se gano el juego o si se sigue jugando
/// @param game 
/// @return true si se gano, false si se sigue jugando o se perdio
bool checkWin(Game *game);

/// @brief Funcion para crear una palabra con espacios en blanco
///
/// Se crea una palabra con espacios en blanco dependiendo de la longitud de la palabra a adivinar
/// Debe ser llamada al incio del juego
/// @param game Puntero a la estructura Game
/// @return void
void spacedWord(Game *game);

/// @brief Funcion para iniciar el juego
///
/// @param game Puntero a la estructura Game
/// @param wordsDict Arreglo de palabras
/// @param maxTries Numero de intentos maximos
/// @param lenghtWordArray Longitud del arreglo de palabras
void beginGame(Game *game,string wordsDict[],int maxTries,int lenghtWordArray);

/// @brief Funcion para obtener una palabra aleatoria
///
/// @param wordsDict Arreglo de palabras
/// @param lenghtWordArray Longitud del arreglo de palabras
/// @return string Palabra aleatoria
std::string getWord(std::string wordsDict[],int lenghtWordArray);

#endif // FUNCIONES_H