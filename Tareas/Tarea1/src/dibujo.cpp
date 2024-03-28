/// \file dibujo.cpp
/// @brief Funciones para dibujar el ahorcado

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

/// Con esta funcion se dibuja al ahorcado cuando se pierde un intento
/// 
/// Dependiendo de la dificultad, se dibuja el ahorcado
void dibujarAhorcado(Game *game){
    // Si es facil, se dibuja el ahorcado con 7 intentos
    if (game-> maxTries == FACIL) {
        switch (game->tries) {
            case 1:
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |      " << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << "_|_" << endl;
            break;
        case 2:
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |      " << endl;
            cout << " |" << endl;
            cout << "_|_" << endl;
            break;
        case 3:
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |     |" << endl;
            cout << " |" << endl;
            cout << "_|_" << endl;
            break;
        case 4:
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |    /|" << endl;
            cout << " |" << endl;
            cout << "_|_" << endl;
            break;
        case 5:
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |    /|\\" << endl;
            cout << " |     " << endl;
            cout << "_|_" << endl;
            break;
        case 6:
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |    /|\\" << endl;
            cout << " |    /  " << endl;
            cout << "_|_" << endl;
            break;
        case 7:
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |    /|\\" << endl;
            cout << " |    / \\" << endl;
            cout << "_|_" << endl;
            break;
        default:
            cout << "Error: Intentos fallidos excedidos." << endl;
            break;
        }
    } else if (game -> maxTries == INTERMEDIO) {
        // Si es intermedio, se dibuja el ahorcado con 5 intentos
        switch (game->tries) {
            case 1:
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << "_|_" << endl;
            break;
        case 2:
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |     |" << endl;
            cout << " |" << endl;
            cout << "_|_" << endl;
            break;
        case 3:
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |    /|\\" << endl;
            cout << " |" << endl;
            cout << "_|_" << endl;
            break;
        case 4:
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |    /|\\" << endl;
            cout << " |    /  "  << endl;
            cout << "_|_" << endl;
            break;
        case 5:
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |    /|\\" << endl;
            cout << " |    / \\" << endl;
            cout << "_|_" << endl;
            break;
        
        default:
            cout << "Error: Intentos fallidos excedidos." << endl;
            break;
        }
    } else if (game -> maxTries == DIFICIL) {
        // Si es dificil, se dibuja el ahorcado con 3 intentos
        switch (game->tries) {
            case 1:
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |      " << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << "_|_" << endl;
            break;
        case 2:
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |    /|\\" << endl;
            cout << " |" << endl;
            cout << "_|_" << endl;
            break;
        case 3:
            cout << " _______" << endl;
            cout << " |     |" << endl;
            cout << " |     O" << endl;
            cout << " |    /|\\" << endl;
            cout << " |    / \\" << endl;
            cout << "_|_" << endl;
            break;
        default:
            cout << "Error: Intentos fallidos excedidos." << endl;
            break;
        }
    }
}

void dibujarPersonaFeliz(){
    cout << "  O" << endl;
    cout << " ~|~" << endl;
    cout << " / \\" << endl;
    cout << "Felicidades, ha ganado!!!" << endl;
}
