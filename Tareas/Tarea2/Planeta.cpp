#include <iostream>
#include <string>
#include "TiposPaises.hpp"
#include "Tools.hpp"
#include "Continente.hpp"
#include "Planeta.hpp"

Planeta::Planeta(std::string nombre){
    this->nombre = nombre;
    setNumContinentes();
    setContinentes();
}
void Planeta::setNumContinentes(){
    std::cout << "Ingrese el numero de continentes: ";
    std::cin >> numContinentes;
    if (numContinentes > MAX_CONTINENTS){
        numContinentes = MAX_CONTINENTS;
    }
}
void Planeta::setContinentes(){

    for (int i = 0; i < numContinentes; i++){
        std::string nombre ;
        std::cout << "Ingrese el nombre del continente " << i << ": ";
        std::cin >> nombre;
        continentes[i] = new Continente(nombre);
    }
}

void Planeta::avion(){
    if (numContinentes == 0){
        std::cout << "No hay continentes" << std::endl;
        return;
    } 
    for (int i = 0; i < numContinentes; i++){
        if (continentes[i]->countCountriesAirport() > 1){
            std::cout << "En el continente "<< continentes[i]->getNombre() << " puede pasar el avion" << std::endl;
        }
    }
}

void Planeta:: print(){
    std::cout << "Planeta posee " << numContinentes << " continentes: ";
    for (int i = 0; i < numContinentes; i++){
        std::cout  << continentes[i]->getNombre() << " ";
    }
    std::cout << std::endl;
    std::cout << "Informacion de los continentes: " << std::endl;
    for (int i = 0; i < numContinentes; i++){
        continentes[i]->printGeneralInfo();
    }

    //avion();

    std::cout << "Informacion de los paises: " << std::endl;
    for (int i = 0; i < numContinentes; i++){
        continentes[i]->print();
    }


}

Planeta::~Planeta(){
    for (int i = 0; i < numContinentes; i++){
        delete continentes[i];
    }
}   