/// @file Definicion de la clase Desarrollo
///
/// @brief Clase que representa un país en desarrollo.

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
#include "Pais.hpp"
#include "TiposPaises.hpp"

Desarrollo::Desarrollo(std::string nombre) : Pais(DESARROLLO, nombre){
    /// @note Los paises en desarrollo nunca tienen 5G.
    this->G5 = false;
    this->id = generateId();
}


/// @note Los ids de los paises en desarrollo son numeros pares.
int Desarrollo::generateId() const{
    while (true){
        int id = randomInt(1, MAX_COUNTRIES);
        if (!checkPrime(id) && !checkIdInList(id, id_list)){
            id_list[id] = id;
            return id;
        }   
    }
}

void Desarrollo::print(){
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "PIB: " << PIB << std::endl;
    std::cout << "Habitantes: " << habitantes << std::endl;
    std::cout << "Aeropuerto: ";
    if (airport){
        std::cout << "Si" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    std::cout << "5G: ";
    if (G5){
        std::cout << "Si" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}