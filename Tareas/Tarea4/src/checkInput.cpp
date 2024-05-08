/*! @file CheckInput.cpp
 @brief Implementacion de la clase ValidadorDeEntrada
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
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <type_traits>
#include "checkInput.hpp"
using namespace std;


template <class T>
bool ValidadorDeEntrada<T>::validarTipoDato(string input, T *value){
    try {
        //Instancia un objeto de tipo istringstream para convertir el string a un tipo de dato T
        /*
        Esta clase da una manera
        fácil de convertir un string a un tipo de dato T numérico
        */
        istringstream stream(input);

        //Verifica si el string se puede convertir a un tipo de dato T
        /*
        stream >> value: Intenta convertir el string a un tipo de dato T
        si no se puede convertir, es FALSE
        stream >> ws: Verifica si hay espacios en blanco después del string
        stream.eof(): Verifica si se llegó al final del string
        */
        if (!(stream >> *value) || !(stream >> ws).eof()){
            throw invalid_argument("El tipo de dato ingresado no es valido");
        }
        return true;
    }
    catch (invalid_argument &e){
        cout << e.what() << endl;
        return false;
    }
}



template <class T>
bool ValidadorDeEntrada<T>::validarDimensiones(int tamano){
    try {
        // Verifica que el tamaño de la matriz sea mayor a 0
        if (tamano <= 0){
            //Se lanza una excepción si el tamaño de la matriz es menor o igual a 0
            throw invalid_argument("El tamaño de la matriz no puede ser menor o igual a 0");
        }
        return true;
    }
    //Se captura la excepción y se imprime el mensaje de error
    catch (invalid_argument &e){
        cout << e.what() << endl;
        return false;
    }
}