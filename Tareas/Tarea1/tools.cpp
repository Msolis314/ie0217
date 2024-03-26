#include <iostream>
#include <string>
#include <cstdlib>
#include "Game.hpp"
#include "funciones.hpp"
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

    if (game->tries >= game->maxTries) {
        cout << "Numero de intentos excedido\n";
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
    if (filledWord == emptyWord) {
        cout << "Letra incorrecta\n";
        game->tries++;
    } else {
        cout << "Letra correcta\n";
    }
    game->filledWord = filledWord;
    game->emptyWord = filledWord;

}

/// @brief Funcion que revisa si se gano el juego o si se sigue jugando
/// @param game 
/// @return true si se gano, false si se sigue jugando o se perdio
bool checkWin(Game *game) {
    string word = game->wordToGuess;
    string filledWord = game->filledWord;

    if (word == filledWord) {
        cout << "Felicidades, ha ganado\n";
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
        cout << "Game Over\n";
        return true; // No ha ganado
    }

}

string getWord(string wordsDict[],int lenght) {
    int randomIndex = rand() % lenght;
    return wordsDict[randomIndex];
}

void beginGame(Game *game,string wordsDict[],int maxTries,int lenght) {
    game->wordToGuess = getWord(wordsDict,lenght);
    game->maxTries = maxTries;
    spacedWord(game);

    cout << "Bienvenido al juego de ahorcado\n";
    cout << "La palabra a adivinar tiene " << game->wordToGuess.length() << " letras\n";
    cout << "Tiene " << game->maxTries << " intentos\n";
    cout << game->filledWord << endl;

    while (checkWin(game) != true) {
        guess(game);
        cout << game->filledWord << endl;
    }

}