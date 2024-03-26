#include <iostream>
#include <string>
#include "Game.hpp"
#include "funciones.hpp"
using namespace std;

int main(){
    Game game;
    
    string wordsDict[] = {"hello","world","c++","programming","language"};
    beginGame(&game,wordsDict,5,5);
    return 0;
    
}

