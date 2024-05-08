#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <complex>
#include "tools.hpp"


using namespace std;
/// @note Se utiliza rand para generar numeros random
/// @note Se utiliza static_cast para convertir el tipo de dato de rand a float o double
template <class T>
T randomNum(int tipoDato){
    T num;
    
    switch (tipoDato)
    {
    case INT:
        //Si es un numero entero
        //Se genera un numero random entre 1 y 100 
        //simplemente se hace un modulo 100 y se suma 1
        num = rand() % 100 +1; // Numeros random entre 1 y 100
        break;
    case FLOAT:
        //si es un numero flotante
        //Se genera un numero random entre 0 y 100
        //Se divide el numero random entre RAND_MAX y se multiplica por 100
        //se castea a float
        num = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.0f)); // Numeros random entre 0 y 100
        break;
    case DOUBLE:
        //si es un numero double
        //Se genera un numero random entre 0 y 100
        //Se divide el numero random entre RAND_MAX y se multiplica por 100
        //se castea a double
        num = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/100.0)); // Numeros random entre 0 y 100
        break;
    
    default:
        break;
    }
    return num;
}