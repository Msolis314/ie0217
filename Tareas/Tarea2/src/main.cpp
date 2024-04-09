/// @file Main del programa
///
/// @brief Main del programa

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


/// @brief Enumeracion de opciones del menu
enum opciones{
    IMPRIMIR_PAISES = 1,
    COMPARAR_PAISES,
    AGREGAR_PAIS,
    ELIMINAR_PAIS,
    SALIR
};

int main(){
    

    std::cout << "Ingrese el nombre del planeta: ";
    std::string nombre;
    std::cin >> nombre;

    Planeta planeta(nombre);//Se crea un planeta

    //Loop del menu
    do {
        std::cout << "Menu: " << std::endl;
        std::cout << "1. Imprimir paises" << std::endl;
        std::cout << "2. Comparar paises" << std::endl;
        std::cout << "3. Agregar pais" << std::endl;
        std::cout << "4. Eliminar pais" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Ingrese una opcion: ";
        int opcion;
        std::cin >> opcion;
        switch (opcion){
            case IMPRIMIR_PAISES:
                planeta.print();
                break;
            case COMPARAR_PAISES:
                planeta.compararPaises();
                break;
            case AGREGAR_PAIS:
                planeta.agregarPais();
                break;
            case ELIMINAR_PAIS:
                planeta.eliminarPais();
                break;
            case SALIR:
                std::cout << "Saliendo..." << std::endl;
                return 0;
            default:
                std::cout << "Opcion invalida" << std::endl;
        }
    } while (true);
    
    return 0;
}