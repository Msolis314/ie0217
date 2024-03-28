///@brief Funciones para el menu
///@file menu.hpp

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

#include <iostream>
#include <string>
#include "Game.hpp"
#include "menu.hpp"
using namespace std;

//Muestra las palabra incluidas en el arreglo dentro del struct
void showWords(Menu *menu){
    cout << endl;
    cout << "Palabras\n";
    cout << "--------\n";
    for (int i = 0; i < menu ->numWords; i++) {
        cout << menu->palabrasrandom[i] << endl;
        cout << "~~~~~~~~\n";
    }
}

//Elige la dificultad del juego
void choseDifficulty(Menu *menu,Game *game){

    do {
        cout << endl;
        cout << "Elija una dificultad\n";
        cout << "1. Facil\n";
        cout << "2. Intermedio\n";
        cout << "3. Dificil\n";
        cout << "Digite una opcion: ";
        cin >> menu->dificultad;

        switch (menu->dificultad) {
            case 1:
                game->maxTries = FACIL;

                break;
            case 2:
                game->maxTries = INTERMEDIO;
                break;
            case 3:
                game->maxTries = DIFICIL;
                break;
            default:
                cout << "Opcion invalida\n";
                break;
        }
    } while (menu->dificultad < 1 || menu->dificultad > 3);
    
}

//Agrega una palabra al arreglo dentro del struct
void addWord(Menu *menu){
    string newWord;
    cout << endl;
    cout << "Digite la nueva palabra: ";
    cin >> newWord;
    //Si el arreglo esta lleno, no se pueden agregar mas palabras
    //Esto xq debe crearse con un tamaño fijo
    if (menu->numWords == MAX_WORDS) {
        cout << "No se pueden agregar mas palabras\n";
        return;
    }
    menu->palabrasrandom[menu->numWords] = newWord;
    menu->numWords++;
}