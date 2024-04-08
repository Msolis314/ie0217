#include <iostream>
#include <string>
#include "TiposPaises.hpp"
#include "Tools.hpp"
#include "Continente.hpp"
#include "Planeta.hpp"


Planeta::Planeta(std::string nombre){
    std::cout << std::endl;
    std::cout << " /\\_/\\   " << std::endl;
    std::cout << "( o.o )  " << std::endl;
    std::cout << " > ^ <   " << std::endl;
    std::cout << std::endl;
    std::cout << "Creando planeta " << nombre << std::endl;
    this->nombre = nombre;
    std::cout << "Si ingresa un continente existente, se agregaran paises de primer mundo y en desarrollo automaticamente" << std::endl;
    setNumContinentes();
    setContinentes();
}
void Planeta::setNumContinentes(){
    std::cout << "\nIngrese el numero de continentes: ";
    std::cin >> numContinentes;
    if (numContinentes > MAX_CONTINENTS){
        numContinentes = MAX_CONTINENTS;
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
    for (int i = 0; i < numContinentes; i++){
        if (continentes[i]->countCountriesAirport() > 1){
            std::cout << "En el continente "<< continentes[i]->getNombre() << " puede pasar el avion" << std::endl;
        }
    }
}

void Planeta:: print(){
    std::cout << "Nombre del planeta: " << nombre << std::endl;
    std::cout << "\nPlaneta posee " << numContinentes << " continentes: ";
    for (int i = 0; i < numContinentes; i++){
        std::cout  << continentes[i]->getNombre() << " , ";
    }
    std::cout << std::endl;
    std::cout << "\nInformacion de los continentes: " << std::endl;
    for (int i = 0; i < numContinentes; i++){
        continentes[i]->printGeneralInfo();
    }

    avion();

    std::cout << "\nInformacion de los paises: " << std::endl;
    for (int i = 0; i < numContinentes; i++){
        continentes[i]->print();
    }


}

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
Planeta::~Planeta(){
    for (int i = 0; i < numContinentes; i++){
        delete continentes[i];
    }
}   


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
        std::cout << *(continentes_names +1 ) << std::endl;
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

void Planeta:: eliminarPais(){
    displayContinents();
    std::cout << "Ingrese el continente al que desea eliminar el pais: ";
    std::string continente;
    std::cin >> continente;
    for (int i = 0; i < getNumContinentes(); i++){
        if (continentes[i] -> getNombre() == continente){
            continentes[i] -> deleteCountry();
            return;
        }
    }
}

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