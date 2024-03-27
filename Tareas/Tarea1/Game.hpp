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

