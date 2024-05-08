#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <complex>
#include "tools.hpp"


using namespace std;

template <class T>
T randomNum(int tipoDato){
    T num;
    
    switch (tipoDato)
    {
    case INT:
        num = rand() % 100 +1; // Numeros random entre 1 y 100
        break;
    case FLOAT:
        num = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100)); // Numeros random entre 0 y 100
        break;
    case DOUBLE:
        num = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/100)); // Numeros random entre 0 y 100
        break;
    
    default:
        break;
    }
}