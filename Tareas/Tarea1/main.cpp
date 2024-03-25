#include <iostream>
#include <string>
#include "Game.hpp"
using namespace std;

int main(){
    Game game;
    game.wordToGuess = "hello";
    spacedWord(&game);
    cout << game.emptyWord << endl;
    guess(&game);
    cout << game.filledWord << endl;
    return 0;
    
}

