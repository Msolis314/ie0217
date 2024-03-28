/// @file Game.hpp
/// @brief Contiene la estructura del juego y el menu

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

#include <string>
using namespace std;

#ifndef GAME_HPP
#define GAME_HPP

#define MAX_WORDS 100
#define DIFICULTAD_INICIAL 7

/// @brief Estructura para el juego
///
/// @param wordToGuess Palabra a adivinar elegida aleatoriamente
/// @param emptyWord Palabra con guiones bajos como control para verificar si se adivino la letra
/// @param filledWord Palabra con las letras adivinadas hasta el momento
/// @param tries Intentos
/// @param maxTries Intentos maximos
struct Game
{
    string wordToGuess;
    string emptyWord;
    string filledWord;
    int tries =0;
    int maxTries = DIFICULTAD_INICIAL;
};

/// @brief Estructura para el menu
///
/// @param palabrasrandom Arreglo de palabras con 5 palabras inicialices
/// @param numWords Numero de palabras
/// @param dificultad Dificultad del juego incializada en Facil
struct Menu {
    string palabrasrandom[MAX_WORDS]={"hola","mundo","c++","programacion","lenguaje"};
    int numWords = 5;
    int dificultad = DIFICULTAD_INICIAL;
};


#endif // GAME_HPP

