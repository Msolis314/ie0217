///@brief Header file para funciones
///
/// Este archivo contiene las funciones necesarias para el juego del ahorcado
///
/// @file funciones.hpp

/*!
MIT License

Copyright (c) 2024 Msolis314

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


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

/// @brief Funcion para dibujar el ahorcado
///
/// @param game Puntero a la estructura Game
void dibujarAhorcado(Game *game);

/// @brief Funcion para dibujar una persona feliz cuando se gana el juego
void dibujarPersonaFeliz();

/// @brief revisa si la nueva letra ya estaba en la lista de letras adivinadas
/// @param c letra a revisar
/// @param game puntero a la estructura Game
/// @return True si la letra ya estaba en la lista de letras adivinadas, False si no
bool checkChar(char c, Game *game);

#endif // FUNCIONES_H