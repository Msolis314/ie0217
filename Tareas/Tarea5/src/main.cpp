#include <iostream>
#include <string>
#include "validador.hpp"

enum Menu{
    INGRESAR_EMAIL = 1,
    SALIR
};

int main(){
    int opcion;
    do {
        std::string email;
        std::cout << "1) Ingresar email\n2) Salir" << std::endl;
        std::cin >> opcion;
        ValidadorEmail validador; 
        switch (opcion)
        {
            case INGRESAR_EMAIL:
                std::cout << "Ingrese su email: ";
                std::cin >> email;
                validador.validarCorreo(email); 
                break;
            case SALIR:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida" << std::endl;
                break;
        }
    } while (opcion != SALIR);
    
    return 0;
}