#include <iostream>
#include <string>
#include "Pais.hpp"
#include "TiposPaises.hpp"
#include "Continente.hpp"

struct defaultCountries
{
    std::string asiaPrimerMundo[4] = {"China","Kores del Sur","Japon","Singapur"};
    std::string africaPrimerMundo[4] = {"Sudafrica","Egipto","Nigeria","Kenia"};
    std::string europePrimerMundo[4] = {"Alemania","Francia","Reino Unido","Italia"};
    std::string americaPrimerMundo[4] = {"Estados Unidos","Canada","Brasil","Argentina"};
    std::string oceaniaPrimerMundo[4] = {"Australia","Nueva Zelanda"};

    std::string asiaDesarrollo[4] = {"India","Indonesia","Pakistán","Bangladesh"};
    std::string africaDesarrollo[4] = {"Etiopía","Ginea","Somalia","Congo"};
    std::string europeDesarrollo[4] = {"Ucrania","Grecia","Serbia","Rumania"};
    std::string americaDesarrollo[4] = {"Costa Rica","Salvador","México","Colombia"};
    std::string oceaniaDesarrollo[2] = {"Fiyi","Samoa"};
    
};
Continente::Continente(std::string nombre){
    std::cout << "Creando continente: " << nombre << std::endl;
    this->nombre = nombre;
    this->numPaisesPrimerMundo = 4;
    this->numPaisesDesarrollo = 4;
    setPaisesPrimerMundo();
    setPaisesDesarrollo();
}

void Continente::setPaisesPrimerMundo(){
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
        for (int i = 0; i < 4; i++){
            paisesPrimerMundo[i] = new PrimerMundo(defaultCountries.oceaniaPrimerMundo[i]);
        }
    } else {
        numPaisesPrimerMundo = 0;
        std::cout << "Continente no encontrado" << std::endl;
        std::cout << "Agregar paises de primer mundo manualmente" << std::endl;
        std::cout << "Nombre del pais: ";
        std::string nombre;
        std::cin >> nombre;
        addCountry(PRIMER_MUNDO, nombre);
    }
    
}

void Continente::setPaisesDesarrollo(){
    struct defaultCountries defaultCountries;
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
    } else {
        numPaisesDesarrollo = 0;
        std::cout << "Continente no encontrado" << std::endl;
        std::cout << "Agregar paises  en desarrollo manualmente" << std::endl;
        std::cout << "Nombre del pais: ";
        std::string nombre;
        std::cin >> nombre;
        addCountry(DESARROLLO, nombre);
    }
}

void Continente::addCountry(int typeCountry, std::string nombre){
    if (typeCountry == PRIMER_MUNDO){
        paisesPrimerMundo[numPaisesPrimerMundo] = new PrimerMundo(nombre);
        numPaisesPrimerMundo++;
    } else if (typeCountry == DESARROLLO){
        paisesDesarrollo[numPaisesDesarrollo] = new Desarrollo(nombre);
        numPaisesDesarrollo++;
    }
}

void Continente::printGeneralInfo(){
    std::cout << nombre << " posee " << numPaisesPrimerMundo + numPaisesDesarrollo << " paises " << ", de los cuales" << numPaisesPrimerMundo << " son de primer mundo y " << numPaisesDesarrollo << " estan en desarrollo" << std::endl;
    

}

void Continente::print(){
    std::cout << "Nombre del continente: " << nombre << std::endl;
    std::cout << "Paises de primer mundo: " << std::endl;
    for (int i = 0; i < numPaisesPrimerMundo; i++){
        paisesPrimerMundo[i]->print();
    }
    std::cout << "Paises en desarrollo: " << std::endl;
    for (int i = 0; i < numPaisesDesarrollo; i++){
        paisesDesarrollo[i]->print();
    }
}

int Continente::countCountriesAirport(){
    int count = 0;
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
Continente::~Continente(){
    for (int i = 0; i < numPaisesPrimerMundo; i++){
        delete paisesPrimerMundo[i];
    }
    for (int i = 0; i < numPaisesDesarrollo; i++){
        delete paisesDesarrollo[i];
    }
}