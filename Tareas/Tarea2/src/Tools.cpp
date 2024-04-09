/// @file Herramientas para la generacion de numeros aleatorios y validaciones

/*!
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
#include <cstdlib>
#include <ctime>
#include "Pais.hpp"
#include "Tools.hpp"

int id_list[MAX_COUNTRIES] = {0};


int randomInt (int min, int max){
    // Semilla para generar numeros aleatorios
    srand(time(0));
    return rand() % (max - min + 1) + min;
}

bool checkPrime(int n){
    // Caso base, un numero negativo o 0 no es primo
    if (n <= 1){
        return false;
    }
    // Iteramos desde 2 hasta n-1
    //Un numero primo solo es divisible por 1 y por si mismo
    for (int i = 2; i < n; i++){
        // Si n es divisible por i, entonces no es primo
        if (n % i == 0){
            return false;
        }
    }
    // Si no se encontro un divisor, entonces es primo
    return true;
}

bool checkIdInList(int id, int id_list[]){

    // Se itera sobre la lista de ids para verificar si el id ya existe
    for (int i = 0; i < MAX_COUNTRIES; i++){
        if (id_list[i] == id){
            return true;
        }
    }
    return false;
}

// Funcion para comprobar si un continente es real
bool checkContinent(std::string continent){
    if (continent == "Africa" || continent == "America" || continent == "Asia" || continent == "Europe" || continent == "Oceania"){
        return true;
    }
    return false;
}

