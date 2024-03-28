/// @brief Main de ejecucion
/// @file main.cpp


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
#include "funciones.hpp"
#include "menu.hpp"
using namespace std;

enum opciones{
    DIFICULTAD = 1,
    JUGAR,
    NUEVA_PALABRA,
    VER_PALABRAS,
    SALIR
};

int main(){
    Game game;
    Menu menu;
    
    int choice;
    do {
        cout << endl;
        cout << "Menu\n";
        cout << "1. Elegir dificultad\n";
        cout << "2. Jugar\n";
        cout << "3. Nueva palabra\n";
        cout << "4. Ver palabras\n";
        cout << "5. Salir\n";
        cout << "Digite una opcion: ";
        cin >> choice;
        switch (choice) {
            case DIFICULTAD:
                choseDifficulty(&menu,&game);
                break;
            case JUGAR:
                beginGame(&game,menu.palabrasrandom,menu.numWords,game.maxTries);
                break;
            case NUEVA_PALABRA:
                addWord(&menu);
                break;
            case VER_PALABRAS:
                showWords(&menu);
                break;
            case SALIR:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida\n";
                break;
        }
    } while (choice != SALIR);
    return 0;
    
}

