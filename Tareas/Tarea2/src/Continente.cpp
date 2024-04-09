/// @file Contiene las definiciones de los métodos de la clase Continente.
/// @brief Clase que representa un continente y contiene los métodos para agregar, eliminar y comparar paises.
/// @note es una clase compuesta por objetos de la clase Pais.

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
#include "Pais.hpp"
#include "TiposPaises.hpp"
#include "Continente.hpp"

/// @note Si el continente existe, se agregan paises de primer mundo y en desarrollo automaticamente.
Continente::Continente(std::string nombre){
    std::cout << "Creando continente: " << nombre << std::endl;
    this->nombre = nombre;
    this->numPaisesPrimerMundo = 4;
    this->numPaisesDesarrollo = 4;
    setPaisesPrimerMundo();
    setPaisesDesarrollo();
}

void Continente::setPaisesPrimerMundo(){

    if (!checkContinent(nombre)){
        // Si el continente no existe, se le pregunta al usuario si desea agregar paises de primer mundo manualmente
        std::cout << "Continente no encontrado" << std::endl;
        std::cout << "Desea agregar paises de primer mundo manualmente? 1: Si, 0: No" << std::endl;
        int choice;
        std::cin >> choice;
        if (choice == 1){
            std::cout << "Nombre del pais: ";
            std::string nombre;
            std::cin >> nombre;
            paisesPrimerMundo[0] = new PrimerMundo(nombre);
            numPaisesPrimerMundo = 1;
        } else {
            numPaisesPrimerMundo = 0;
            return;
        }
    }

    // Se agregan paises de primer mundo por defecto
    struct defaultCountries defaultCountries;
    if (nombre == "America"){
        for (int i = 0; i < numPaisesPrimerMundo; i++){
            paisesPrimerMundo[i] = new PrimerMundo(defaultCountries.americaPrimerMundo[i]);
        }
    } else if (nombre == "Asia"){
        for (int i = 0; i < numPaisesPrimerMundo; i++){
            paisesPrimerMundo[i] = new PrimerMundo(defaultCountries.asiaPrimerMundo[i]);
        }
    } else if (nombre == "Africa"){
        for (int i = 0; i < numPaisesPrimerMundo; i++){
            paisesPrimerMundo[i] = new PrimerMundo(defaultCountries.africaPrimerMundo[i]);
        }
    } else if (nombre == "Europa"){
        for (int i = 0; i < numPaisesPrimerMundo; i++){
            paisesPrimerMundo[i] = new PrimerMundo(defaultCountries.europePrimerMundo[i]);
        }
    } else if (nombre == "Oceania"){
        for (int i = 0; i < 2; i++){
            paisesPrimerMundo[i] = new PrimerMundo(defaultCountries.oceaniaPrimerMundo[i]);
        }
        numPaisesPrimerMundo = 2;
    } 
    
}

void Continente::setPaisesDesarrollo(){
    if (!checkContinent(nombre)){
        // Si el continente no existe, se le pregunta al usuario si desea agregar paises en desarrollo manualmente
        std::cout << "Desea agregar paises en desarrollo manualmente? 1: Si, 0: No" << std::endl;
        int choice;
        std::cin >> choice;
        if (choice == 1){
            std::cout << "Nombre del pais: ";
            std::string nombre;
            std::cin >> nombre;
            paisesDesarrollo[0] = new Desarrollo(nombre);
            numPaisesDesarrollo = 1; // Como no habia paises en desarrollo, se agrega uno
        } else {
            numPaisesDesarrollo = 0;
            return;
        }
    }
    struct defaultCountries defaultCountries;
    // Se agregan paises en desarrollo por defecto
    if (nombre == "America"){
        for (int i = 0; i < numPaisesDesarrollo; i++){
            paisesDesarrollo[i] = new Desarrollo(defaultCountries.americaDesarrollo[i]);
        }
    } else if (nombre == "Asia"){
        for (int i = 0; i < numPaisesDesarrollo; i++){
            paisesDesarrollo[i] = new Desarrollo(defaultCountries.asiaDesarrollo[i]);
        }
    } else if (nombre == "Africa"){
        for (int i = 0; i < numPaisesDesarrollo; i++){
            paisesDesarrollo[i] = new Desarrollo(defaultCountries.africaDesarrollo[i]);
        }
    } else if (nombre == "Europa"){
        for (int i = 0; i < numPaisesDesarrollo; i++){
            paisesDesarrollo[i] = new Desarrollo(defaultCountries.europeDesarrollo[i]);
        }
    } else if (nombre == "Oceania"){
        for (int i = 0; i < 2; i++){
            paisesDesarrollo[i] = new Desarrollo(defaultCountries.oceaniaDesarrollo[i]);
        }
        numPaisesDesarrollo = 2;
    } 
}


void Continente::addCountry(int typeCountry, std::string nombre){
    if (typeCountry == PRIMER_MUNDO){
        paisesPrimerMundo[numPaisesPrimerMundo] = new PrimerMundo(nombre);//Se crea un nuevo pais de primer mundo en el heap
        numPaisesPrimerMundo++;
    } else if (typeCountry == DESARROLLO){
        paisesDesarrollo[numPaisesDesarrollo] = new Desarrollo(nombre);//Se crea un nuevo pais en desarrollo en el heap
        numPaisesDesarrollo++;
    }
}

void Continente::printGeneralInfo(){
    std::cout << nombre << " posee " << numPaisesPrimerMundo + numPaisesDesarrollo << " paises " << ", de los cuales " << numPaisesPrimerMundo << " son de primer mundo y " << numPaisesDesarrollo << " estan en desarrollo" << std::endl;
    

}

/// @note Se muestra el nombre del continente y la cantidad de paises del primer mundo y en desarrollo.
void Continente::print(){
    if (numPaisesPrimerMundo == 0 && numPaisesDesarrollo == 0){
        std::cout << "No hay paises en el continente: "<< nombre << std::endl;
        return;
    }
    std::cout << "Nombre del continente: " << nombre << std::endl;
    std::cout << "\nPaises de primer mundo: " << std::endl;
    for (int i = 0; i < numPaisesPrimerMundo; i++){
        paisesPrimerMundo[i]->print();
    }
    std::cout << "\nPaises en desarrollo: " << std::endl;
    for (int i = 0; i < numPaisesDesarrollo; i++){
        paisesDesarrollo[i]->print();
        std::cout << std::endl;
    }
}

/// @note Un avion puede pasar por un continente si este tiene mas de un pais con aeropuerto.
/// @return cantidad de paises con aeropuerto
int Continente::countCountriesAirport(){
    int count = 0;

    // Contar los paises con aeropuerto en paisesPrimerMundo y paisesDesarrollo

    for (int i = 0; i < numPaisesPrimerMundo; i++){
        if (paisesPrimerMundo[i]->getAirport()){
            count++;
        }
    }
    for (int i = 0; i < numPaisesDesarrollo; i++){
        if (paisesDesarrollo[i]->getAirport()){
            count++;
        }
    }

    return count;
}


std::string Continente::getNombre(){
    return nombre;
}

void Continente::printCountries(){
    for (int i = 0; i < numPaisesPrimerMundo; i++){
        std::cout << paisesPrimerMundo[i]->getNombre() << std::endl;
    }
    for (int i = 0; i < numPaisesDesarrollo; i++){
        std::cout << paisesDesarrollo[i]->getNombre() << std::endl;
    }
}

void Continente::deleteCountry(){

    // Si no hay paises en el continente no se puede eliminar
    if (numPaisesPrimerMundo == 0 && numPaisesDesarrollo == 0){
        std::cout << "No hay paises en el continente" << std::endl;
        return;
    }
    // Mostrar los paises del continente
    printCountries();
    
    // Solicitar el nombre del pais a eliminar
    std::cout << "Ingrese el nombre del pais que desea eliminar: ";
    std::string nombre;
    std::cin >> nombre;

    // Buscar el pais en paisesPrimerMundo
    for (int i = 0; i < numPaisesPrimerMundo; i++){
        if (paisesPrimerMundo[i]->getNombre() == nombre){
            // Eliminar el pais
            delete paisesPrimerMundo[i];
            // Mover los paises restantes
            for (int j = i; j < numPaisesPrimerMundo - 1; j++){
                paisesPrimerMundo[j] = paisesPrimerMundo[j + 1];
            }
            // Decrementar el contador
            numPaisesPrimerMundo--;
            return;
        }
    }
    // Buscar el pais en paisesDesarrollo
    for (int i = 0; i < numPaisesDesarrollo; i++){
        if (paisesDesarrollo[i]->getNombre() == nombre){
            // Eliminar el pais
            delete paisesDesarrollo[i];
            // Mover los paises restantes
            for (int j = i; j < numPaisesDesarrollo - 1; j++){
                paisesDesarrollo[j] = paisesDesarrollo[j + 1];
            }
            // Decrementar el contador
            numPaisesDesarrollo--;
            return;
        }
    }

}

void Continente::compareCountries(std::string nombre1, std::string nombre2){
    // Buscar los paises en paisesPrimerMundo
    for (int i = 0; i < numPaisesPrimerMundo; i++){
        if (paisesPrimerMundo[i]->getNombre() == nombre1){
            // Buscar el segundo pais en paisesPrimerMundo
            for (int j = 0; j < numPaisesPrimerMundo; j++){
                if (paisesPrimerMundo[j]->getNombre() == nombre2){
                    // Comparar los paises
                    *paisesPrimerMundo[i] == *paisesPrimerMundo[j];
                    return;
                }
            }
            // Buscar el segundo pais en paisesDesarrollo
            for (int j = 0; j < numPaisesDesarrollo; j++){
                if (paisesDesarrollo[j]->getNombre() == nombre2){
                    // Comparar los paises
                    *paisesPrimerMundo[i] == *paisesDesarrollo[j];
                    return;
                }
            }
        }
    }
    // Buscar los paises en paisesDesarrollo primero
    for (int i = 0; i < numPaisesDesarrollo; i++){
        //Buscar el primer pais en paisesDesarrollo
        if (paisesDesarrollo[i]->getNombre() == nombre1){
            for (int j = 0; j < numPaisesDesarrollo; j++){
                if (paisesDesarrollo[j]->getNombre() == nombre2){
                    // Comparar los paises
                    *paisesDesarrollo[i] == *paisesDesarrollo[j];
                    return;
                }
            }
            // Buscar el segundo pais en paisesPrimerMundo
            for (int j = 0; j < numPaisesPrimerMundo; j++){
                if (paisesPrimerMundo[j]->getNombre() == nombre2){
                    *paisesDesarrollo[i] == *paisesPrimerMundo[j];
                    return;
                }
            }
        }
    }
}

/// @note Para evitar memory leaks, se eliminan los objetos paises del heap.
Continente::~Continente(){
    for (int i = 0; i < numPaisesPrimerMundo; i++){
        delete paisesPrimerMundo[i];
    }
    for (int i = 0; i < numPaisesDesarrollo; i++){
        delete paisesDesarrollo[i];
    }
}