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