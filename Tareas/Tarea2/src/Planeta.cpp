/// @file Definicion de la clase Planeta
///
/// @brief Clase que representa un planeta.

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
#include "TiposPaises.hpp"
#include "Tools.hpp"
#include "Continente.hpp"
#include "Planeta.hpp"


Planeta::Planeta(std::string nombre){
    //ASCII ART
    std::cout << std::endl;
    std::cout << " /\\_/\\   " << std::endl;
    std::cout << "( o.o )  " << std::endl;
    std::cout << " > ^ <   " << std::endl;
    std::cout << std::endl;
    std::cout << "Creando planeta " << nombre << std::endl;
    this->nombre = nombre;
    std::cout << "Si ingresa un continente existente, se agregaran paises de primer mundo y en desarrollo automaticamente" << std::endl;
    setNumContinentes();//Se establece el numero de continentes
    setContinentes();//Se establecen los continentes
}
void Planeta::setNumContinentes(){
    std::cout << "\nIngrese el numero de continentes: ";
    std::cin >> numContinentes;

    if (numContinentes > MAX_CONTINENTS){
        std::cout << "Numero de continentes excede el maximo permitido" << std::endl;
        std::cout << "Se establece el numero de continentes en " << MAX_CONTINENTS << std::endl;
        numContinentes = MAX_CONTINENTS;//Se establece el maximo de continentes
    }
}
void Planeta::setContinentes(){

    for (int i = 0; i < numContinentes; i++){
        std::string nombre ;
        std::cout << "\nIngrese el nombre del continente " << i + 1 << ": ";
        std::cin >> nombre;
        continentes[i] = new Continente(nombre);
    }
}

/// @note Un avion puede pasar por un continente si este tiene mas de un pais con aeropuerto.
void Planeta::avion(){
    if (numContinentes == 0){
        std::cout << "No hay continentes" << std::endl;
        return;
    } 
    //Impresion de los continentes por los que puede pasar el avion
    for (int i = 0; i < numContinentes; i++){
        if (continentes[i]->countCountriesAirport() > 1){
            std::cout << "En el continente "<< continentes[i]->getNombre() << " puede pasar el avion" << std::endl;
        }
    }
}

void Planeta:: print(){
    //Impresion de la informacion del planeta
    std::cout << "\nNombre del planeta: " << nombre << std::endl;
    std::cout << "\nPlaneta posee " << numContinentes << " continentes: ";
    for (int i = 0; i < numContinentes; i++){
        std::cout  << continentes[i]->getNombre() << " , ";
    }
    std::cout << std::endl;
    std::cout << "\nInformacion de los continentes: " << std::endl;
    for (int i = 0; i < numContinentes; i++){
        std::cout << std::endl;
        continentes[i]->printGeneralInfo();
    }
    //Se determina si el avion puede pasar por un continente
    std::cout << "\nDeterminando si el avion puede pasar por un continente" << std::endl;
    avion();

    //Impresion de la informacion de los paises por continente
    std::cout << "\nInformacion de los paises: " << std::endl;
    for (int i = 0; i < numContinentes; i++){
        std::cout << std::endl;
        continentes[i]->print();
    }


}

/// @note Se muestran los nombres de los continentes almacenados en el arreglo de continentes.
void Planeta::displayContinents(){
    for (int i = 0; i < numContinentes; i++){
        std::cout << continentes[i]->getNombre() << std::endl;
    }
}

int Planeta::getNumContinentes(){
    return numContinentes;
}

std::string* Planeta::getArrayNames(){
    std::string* nombres = new std::string[numContinentes];
    for (int i = 0; i < numContinentes; i++){
        nombres[i] = continentes[i]->getNombre();
    }
    return nombres;
}

Continente* Planeta::getContinentes(){
    return *continentes;
}

/// @note Se solicita al usuario el nombre del continente y se agrega un pais a este es un metodo para el menu

void Planeta:: agregarPais(){
    //Primero se muestran los continentes
    displayContinents();
    std::cout << "Ingrese el continente al que desea agregar el pais: ";
    std::string continente;
    std::cin >> continente;

    bool continenteEncontrado = false;

    int numContinentes = getNumContinentes();

    std::string *continentes_names = getArrayNames();
    //Se busca el continente
    for (int i = 0; i < numContinentes; ++i){
        //Si se encuentra el continente se agrega el pais
        if (*(continentes_names + i) == continente){
            std::cout << "Nombre del pais: ";
            std::string nombre;
            std::cin >> nombre;
            std::cout << "Tipo de pais: 1: Primer mundo, 0: Desarrollo" << std::endl;
            int tipo;
            std::cin >> tipo;

            //Metodo de la clase Continente para agregar un pais
            continentes[i]->addCountry(tipo, nombre);
            continenteEncontrado = true;
            break;
        }
        continue;
    }
    //Si no se encuentra el continente se muestra un mensaje
    if (!continenteEncontrado){
        std::cout << "Continente no encontrado" << std::endl;
    }
}


/// @note Se solicita al usuario el nombre del continente y se elimina un pais de este es un metodo para el menu
void Planeta:: eliminarPais(){
    displayContinents();
    std::cout << "Ingrese el continente al que desea eliminar el pais: ";
    std::string continente;
    std::cin >> continente;

    //Se busca el continente y se elimina el pais
    for (int i = 0; i < getNumContinentes(); i++){
        if (continentes[i] -> getNombre() == continente){
            continentes[i] -> deleteCountry();
            return;
        }
    }
}


/// @note Metodo para comparar paises , se utiliza en el menu
void Planeta:: compararPaises(){
    //Primero se muestran los continentes
    displayContinents();
    std::cout << "Ingrese el continente al que desea comparar los paises: ";
    std::string continente;
    std::cin >> continente;

    //Se busca el continente
    for (int i = 0; i < getNumContinentes(); i++){
        if (continentes[i] -> getNombre() == continente){
            continentes[i] ->printCountries();
            std::cout << "Ingrese el nombre del primer pais: ";
            std::string pais1;
            std::cin >> pais1;
            std::cout << "Ingrese el nombre del segundo pais: ";
            std::string pais2;
            std::cin >> pais2;
            
            //Metodo de la clase Continente para comparar paises
            continentes[i]->compareCountries(pais1, pais2);
            return;
        }
    }
}

/// @note Destructor de la clase Planeta para liberar memoria
Planeta::~Planeta(){
    for (int i = 0; i < numContinentes; i++){
        delete continentes[i];
    }
}   