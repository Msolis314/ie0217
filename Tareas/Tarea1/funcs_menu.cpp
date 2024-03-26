#include <iostream>
#include <string>
#include "Game.hpp"
#include "menu.hpp"
using namespace std;

void showWords(Menu *menu){
    for (int i = 0; i < menu ->numWords; i++) {
        cout << menu->palabrasrandom[i] << endl;
    }
}

void choseDifficulty(Menu *menu,Game *game){

    do {
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

void addWord(Menu *menu){
    string newWord;
    cout << "Digite la nueva palabra: ";
    cin >> newWord;
    menu->palabrasrandom[menu->numWords] = newWord;
    menu->numWords++;
}