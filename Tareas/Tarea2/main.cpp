#include <iostream>
#include <string>
#include "TiposPaises.hpp"
#include "Tools.hpp"
#include "menu.hpp"
#include "Continente.hpp"
#include "Planeta.hpp"

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

    Planeta planeta(nombre);
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
                compararPaises(planeta);
                break;
            case AGREGAR_PAIS:
                agregarPais(planeta);
                break;
            case ELIMINAR_PAIS:
                eliminarPais(planeta);
                break;
            case SALIR:
                return 0;
            default:
                std::cout << "Opcion invalida" << std::endl;
        }
    } while (true);
    
    return 0;
}