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
    std::cout << "5G: ";
    if (G5){
        std::cout << "Si" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}