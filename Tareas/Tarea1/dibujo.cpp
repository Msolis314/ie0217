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
