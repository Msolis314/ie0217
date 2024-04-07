#include <iostream>
#include <string>
#include "menu.hpp"

void agregarPais(Planeta &planeta){
    planeta.displayContinents();
    std::cout << "Ingrese el continente al que desea agregar el pais: ";
    std::string continente;
    std::cin >> continente;
    for (int i = 0; i < planeta.getNumContinentes(); i++){
        if (planeta.getContinentes()[i].getNombre() == continente){
            std::cout << "Nombre del pais: ";
            std::string nombre;
            std::cin >> nombre;
            std::cout << "Tipo de pais: 1: Primer mundo, 0: Desarrollo" << std::endl;
            int tipo;
            std::cin >> tipo;
            planeta.getContinentes()[i].addCountry(tipo, nombre);
            return;
        }
    }
}

void eliminarPais(Planeta &planeta){
    planeta.displayContinents();
    std::cout << "Ingrese el continente al que desea eliminar el pais: ";
    std::string continente;
    std::cin >> continente;
    for (int i = 0; i < planeta.getNumContinentes(); i++){
        if (planeta.getContinentes()[i].getNombre() == continente){
            planeta.getContinentes()[i].deleteCountry();
            return;
        }
    }
}

void compararPaises(Planeta &planeta){
    planeta.displayContinents();
    std::cout << "Ingrese el continente al que desea comparar los paises: ";
    std::string continente;
    std::cin >> continente;
    for (int i = 0; i < planeta.getNumContinentes(); i++){
        if (planeta.getContinentes()[i].getNombre() == continente){
            planeta.getContinentes()[i].printCountries();
            std::cout << "Ingrese el nombre del primer pais: ";
            std::string pais1;
            std::cin >> pais1;
            std::cout << "Ingrese el nombre del segundo pais: ";
            std::string pais2;
            std::cin >> pais2;
            planeta.getContinentes()[i].compareCountries(pais1, pais2);
            return;
        }
    }
}