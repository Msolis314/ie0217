/// @file Definicion de la clase PrimerMundo
/// @brief Esta clase hereda de la clase Pais y representa un país del primer mundo.

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
#include "Tools.hpp"
#include "TiposPaises.hpp"
#include "Pais.hpp"

PrimerMundo:: PrimerMundo(std::string nombre) : Pais(PRIMER_MUNDO, nombre){
    this->workingPopulation = calculateWorkingPopulation(); //Calcula la poblacion trabajadora
    this->hasInvestigationCenter = investigationCenter(); //Determina si tiene centro de investigacion
    this -> G5 = setG5();//Determina si tiene 5G
    this->id = generateId();//Genera el id primo
}

/// @note La proporcion de la poblacion trabajadora en un pais del primer mundo es de 50% a 70%, lo que se calcula con un numero aleatorio.
int PrimerMundo::calculateWorkingPopulation() const{
    double percent = randomInt(50, 70)/100.0;
    return habitantes * percent;
}


/// @note Un pais del primer mundo tiene un centro de investigacion con una probabilidad del 50%.
bool PrimerMundo::investigationCenter(){
    int hasCenter = randomInt(0, 1);// Probabilidad de tener centro de investigacion
    if (hasCenter == 1){
        return true;
    } else {
        return false;
    }
}

/// @note Un pais del primer mundo tiene 5G si tiene mas de 100,000 habitantes y un centro de investigacion.
/// @note Este criterio es arbitrario.
bool PrimerMundo::setG5(){
    if (workingPopulation > 100000 && hasInvestigationCenter){
        G5 = true;
    } else {
        G5 = false;
    }
    return G5;
}

void PrimerMundo::getWorkingPopulation(){
    std::cout << "Poblacion trabajadora: " << workingPopulation << std::endl;
}

int PrimerMundo::generateId() const{
    while (true){
        int id = randomInt(2, MAX_COUNTRIES);
        if (checkPrime(id) && !checkIdInList(id, id_list)){ //Verifica si el id es primo y si no esta en la lista
            id_list[id] = id;//Agrega el id a la lista
            return id;
        }   
    }
}

/// @note Imprime los datos del pais del primer mundo.Algunos datos son especificos de este tipo de pais.
void PrimerMundo :: print(){
    std::cout << std::endl;
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "PIB: " << PIB << std::endl;
    std::cout << "Habitantes: " << habitantes << std::endl;
    std::cout << "Poblacion trabajadora: " << workingPopulation << std::endl;
    std::cout << "Aeropuerto: ";
    if (airport){
        std::cout << "Si" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    std::cout << "Centros de investigacion: ";
    if (hasInvestigationCenter){
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

