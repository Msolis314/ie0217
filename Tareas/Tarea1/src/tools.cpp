/// @file tools.cpp
/// @brief Contiene las funciones para el juego de ahorcado

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


#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Game.hpp"
#include "menu.hpp"
#include "funciones.hpp"
using namespace std;



/// @note Esta funcion se encarga de crear una palabra con guiones bajos
/// @attention Debe ser llamada al inicio del juego
/// @note Setea la palabra vacia y la palabra con las letras adivinadas a guiones bajos
void spacedWord(Game *game) {

    string word = game-> wordToGuess; // Palabra a adivinar
    string spacedWord = "";

    for (int i = 0; i < word.length();i++){
        spacedWord.append("_");
    }

    game->emptyWord = spacedWord;
    game->filledWord = spacedWord;

}

/// @note Esta funcion se encarga de pedir una letra y compararla con la palabra a adivinar
/// @note Si la letra es correcta, se actualiza la palabra con las letras adivinadas
void guess(Game *game) {
    string word = game->wordToGuess;
    string emptyWord = game->filledWord;
    string filledWord = game->filledWord;
    /// Si el numero de intentos es igual al maximo de intentos, no debe seguir jugando
    if (game->tries >= game->maxTries) {
        return;
    }

    char guessLetter;
    cout << "Digite una letra: ";
    cin >> guessLetter;

    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] == guessLetter)
        {
            filledWord[i] = guessLetter;
        }
        
    }

    /// @note Si la nueva palabra es igual a la anterior, la letra adivinada fue incorrecta
    if (filledWord == emptyWord) {
        cout << "Letra incorrecta\n";
        game->tries++; // Se aumenta el numero de intentos
        dibujarAhorcado(game);
    } else {
        cout << "Letra correcta\n";
    }

    game->filledWord = filledWord;
    

}


// Se encarga de verificar si se gano el juego dependiendo del caso
bool checkWin(Game *game) {

    string word = game->wordToGuess;
    string filledWord = game->filledWord;

    if (word == filledWord) {
        cout << endl;
        dibujarPersonaFeliz();
        return true; // Gano
    } else if (game->tries == game->maxTries && word != filledWord) { // Si llega al numero maximo de intentos
        cout << "Numero de intentos excedido\n";
        cout << "Intente adivinar la palabra por completo\n";
        cin >> filledWord;
        game->filledWord = filledWord;
        game->tries++; // Esto es para que no se encicle el juego
        return false;
    } else if (game->tries < game->maxTries && word != filledWord) {
        //game->tries++;
        return false; // No ha ganado
    }else {
        cout << endl;
        cout << "La palabra era: " << word << "\n"; // Si no se gana, se muestra la palabra y se imprime "Game Over"
        cout << "Game Over\n";
        return true; // No ha ganado
    }

}

// Obtiene una palabra aleatoria
string getWord(string wordsDict[],int lenghtWordArray) {
    srand(time(NULL));
    int randomIndex = rand() % lenghtWordArray;
    return wordsDict[randomIndex];
}

void beginGame(Game *game,string wordsDict[],int maxTries,int lenghtWordArray) {
    game->wordToGuess = getWord(wordsDict,lenghtWordArray);
    
    spacedWord(game);
    cout << endl;
    cout << "Bienvenido al juego de ahorcado\n";
    cout << "La palabra a adivinar tiene " << game->wordToGuess.length() << " letras\n";
    cout << "Tiene " << game->maxTries << " intentos\n";
    cout << game->filledWord << endl;

    while (checkWin(game) != true) {
        guess(game);
        if (game->tries <= game->maxTries){
            cout << "Intentos restantes: " << game->maxTries - game->tries << endl;
            cout << game->filledWord << endl;
        }
        
    }
    game->tries = 0;

}