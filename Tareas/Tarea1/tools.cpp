#include <iostream>
#include <string>
#include "Game.hpp"
using namespace std;

void spacedWord(Game *game) {
    string word = game-> wordToGuess;
    string spacedWord = "";
    for (int i = 0; i < word.length();i++){
        spacedWord.append("_");
    }
    game->emptyWord = spacedWord;
    game->filledWord = spacedWord;

}


/// @brief Funcion para pedir ingresar una letra y compararla con la palabra a adivinar
///
/// @param game Puntero a la estructura Game
/// @return void 
void guess(Game *game) {
    string word = game->wordToGuess;
    string emptyWord = game->emptyWord;
    string filledWord = game->filledWord;

    string guessLetter;
    cout << "Digite una letra: ";
    cin >> guessLetter;

    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] == guessLetter[i])
        {
            filledWord[i] = guessLetter[i];
        }
        
    }
    game->filledWord = filledWord;

}

/// @brief Funcion que revisa si se gano el juego o si se sigue jugando
/// @param game 
/// @return true si se gano, false si se sigue jugando o se perdio
bool checkWin(Game *game) {
    string word = game->wordToGuess;
    string filledWord = game->filledWord;

    if (word == filledWord) {
        return true; // Gano
    } else if (game->tries == game->maxTries) { // Si llega al numero maximo de intentos
        cout << "Numero de intentos excedido\n";
        cout << "Intente adivinar la palabra por completo\n";
        cin >> filledWord;
        game->filledWord = filledWord;
        game->tries++; // Esto es para que no se encicle en la recursividad
        checkWin(game); // Llamada recursiva
        return false;
    } else if (game->tries < game->maxTries) {
        game->tries++;
        return false; // No ha ganado
    }else {
        cout << "Game Over\n";
        return false; // No ha ganado
    }

}