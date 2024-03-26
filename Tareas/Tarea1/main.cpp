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

