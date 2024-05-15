/*! @file main.cpp
 @brief Funcion principal del programa
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
#include "validador.hpp"

/// @brief Enumeracion de las opciones del menu
enum Menu{
    INGRESAR_EMAIL = 1,
    SALIR = 2
};

int main(){
    int opcion;
    do {
        std::string email;
        std::cout << "1) Ingresar email\n2) Salir" << std::endl;
        while (!(std::cin >> opcion) || opcion < 1 || opcion > 2){
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cout << "Opcion invalida, intente de nuevo" << std::endl;}
        ValidadorEmail validador; 
        bool valido = false;
        switch (opcion)
        {
            case INGRESAR_EMAIL:
                std::cout << "Ingrese su email: ";
                std::cin >> email;
                std::cout << "Validando correo..." << std::endl;
                validador.validarCorreo(email,valido); 
                break;
            case SALIR:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "\nOpcion invalida" << std::endl;
                break;
        }
    } while (opcion != SALIR);
    
    return 0;
}