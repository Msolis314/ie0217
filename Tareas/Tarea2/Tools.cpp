#include <iostream>
#include <string>
#include <cstdlib>
#include "Pais.hpp"
#include "Tools.hpp"

int randomInt (int min, int max){
    return rand() % (max - min + 1) + min;
}