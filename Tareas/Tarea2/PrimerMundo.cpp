#include <iostream>
#include <string>
#include "Tools.hpp"
#include "TiposPaises.hpp"
#include "Pais.hpp"

PrimerMundo:: PrimerMundo(std::string nombre) : Pais(PRIMER_MUNDO, nombre){
    this->workingPopulation = calculateWorkingPopulation();
    this->hasInvestigationCenter = investigationCenter();
    this -> G5 = setG5();
    this->id = generateId();
}

int PrimerMundo::calculateWorkingPopulation() const{
    double percent = randomInt(50, 70)/100.0;
    return habitantes * percent;
}

bool PrimerMundo::investigationCenter(){
    int hasCenter = randomInt(0, 1);
    if (hasCenter == 1){
        return true;
    } else {
        return false;
    }
}

bool PrimerMundo::setG5(){
    if (workingPopulation > 100000 && hasInvestigationCenter){
        G5 = true;
    } else {
        G5 = false;
    }
}

void PrimerMundo::getWorkingPopulation(){
    std::cout << "Poblacion trabajadora: " << workingPopulation << std::endl;
}

int PrimerMundo::generateId() const{
    while (true){
        int id = randomInt(2, MAX_COUNTRIES);
        if (checkPrime(id) && !checkIdInList(id, id_list)){
            id_list[id] = id;
            return id;
        }   
    }
}
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

