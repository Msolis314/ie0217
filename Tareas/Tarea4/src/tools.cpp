/*! @file tools.cpp
 @brief Implementacion de las funciones de la clase Tools
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
   
    srand(time(0));
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