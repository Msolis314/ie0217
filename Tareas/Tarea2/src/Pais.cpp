/// @file Definicion de la clase Pais
/// @brief Clase que representa un pais.

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
#include "Tools.hpp"

/// @brief Enum con valores para determinar el PIB per capita de un pais.
enum PIB{
    LOWEST_PIB = 240,// PIB mas bajo de un pais
    GLOBAL_AVERAGE_PIB = 12000, // PIB promedio de un pais
    HIGHEST_PIB = 145000 // PIB mas alto de un pais
};

/// @brief Enum con valores para determinar la poblacion de un pais.
enum Population{
    LOWEST_POPULATION = 518000, 
    HIGHEST_POPULATION = 1428627663 //India
};

 
Pais::Pais(int typeCountry, std::string nombre){
    this->typeCountry = typeCountry;
    this->nombre = nombre;
    this->PIB = calculatePIB(typeCountry);
    this->habitantes = generateHabitantes();
    this->airport = hasAirport();
   
}

/// @note dos paises son iguales si tienen el mismo aeropuerto, el mismo tipo de pais y ambos tienen 5G
Pais Pais::operator==(const Pais& p){
    if (this->airport == p.airport && this->G5 == p.G5 && this->typeCountry == p.typeCountry){
        std::cout << "Los paises son iguales" << std::endl;
        return *this;
    } else {
        std::cout << "Los paises son diferentes" << std::endl;
        return *this;
    }
}

/// @note El PIB de un pais en desarrollo es menor al promedio global y el PIB de un pais de primer mundo es mayor al promedio global
double Pais::calculatePIB(int typeCountry) const{
    if (typeCountry == DESARROLLO){
        // PIB de un pais en desarrollo
        // Se genera un numero aleatorio entre el PIB mas bajo y el promedio global
        return randomInt(LOWEST_PIB, GLOBAL_AVERAGE_PIB);
    } else if (typeCountry == PRIMER_MUNDO){
        // PIB de un pais de primer mundo
        // Se genera un numero aleatorio entre el promedio global y el PIB mas alto
        return randomInt(GLOBAL_AVERAGE_PIB, HIGHEST_PIB);
    }
    return 0;
}

/// @note La cantidad de habitantes de un pais se genera aleatoriamente
/// @return cantidad de habitantes de forma aleatoria
double Pais::generateHabitantes() const{
    return randomInt(LOWEST_POPULATION, HIGHEST_POPULATION);
}

int Pais::getId(){
    return id;
}

std::string Pais::getNombre(){
    return nombre;
}

bool Pais::getG5(){
    return G5;
}

double Pais::getPIB(){
    return PIB;
}

bool Pais::hasAirport(){
    std::cout << "El pais " << nombre << " tiene aeropuerto? 1: Si, 0: No" << std::endl;
    int choice;
    std::cin >> choice;
    // Validar la entrada
    // Si la entrada no es 1 o 0, pedir al usuario que ingrese de nuevo
    //Se encicla si hay un error en la entrada
    while (choice != 1 && choice != 0){
        std::cout << "Opcion invalida, intente de nuevo" << std::endl;
        std::cin >> choice;
    }
    if (choice == 1){
        return true;
    } else {
        return false;
    }
}

bool Pais::getAirport(){
    return airport;
}




