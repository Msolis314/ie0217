#include <iostream>
#include <string>
#include "Pais.hpp"
#include "Tools.hpp"
enum PIB{
    LOWEST_PIB = 240,
    GLOBAL_AVERAGE_PIB = 12000,
    HIGHEST_PIB = 145000 
};

enum Population{
    LOWEST_POPULATION = 518,//El Vaticano
    HIGHEST_POPULATION = 1428627663 //India
};

Pais::Pais(int typeCountry, std::string nombre){
    this->typeCountry = typeCountry;
    this->nombre = nombre;
    this->PIB = calculatePIB(typeCountry);
    this->habitantes = generateHabitantes();
    this->airport = hasAirport();
}
double Pais::calculatePIB(int typeCountry) const{
    if (typeCountry == DESARROLLO){
        return randomInt(LOWEST_PIB, GLOBAL_AVERAGE_PIB);
    } else if (typeCountry == PRIMER_MUNDO){
        return randomInt(GLOBAL_AVERAGE_PIB, HIGHEST_PIB);
    }
}
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
    int hasAirport = randomInt(0, 1);
    if (hasAirport == 1){
        return true;
    } else {
        return false;
    }
}


