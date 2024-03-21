#include <iostream>
#include "Contacto.hpp"
#include "Funciones.hpp"
/*Un define define variables
que cambian en tiempo de precompilacion
*/
#define MAX_CONTACTOS 100 

enum Opciones {
    AGREGAR = 1,
    MOSTRAR,
    BUSCAR,
    SALIR

};

int main() {
    /*Por ahora lo que tiene adentro
    Es info basura
    */
    Contacto listaContactos[MAX_CONTACTOS];

    int numContactos = 0;
    int opcion;

    do {
        std::cout << "\nMenu: \n";
        std::cout << "1. Agregar contacto\n";
        std::cout << "2. Mostrar contacto\n";
        std::cout << "3. Buscar contacto\n";
        std::cout << "4. Salir\n";
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;


        switch (opcion){
            case AGREGAR:
                /*A la hora de pasar parametros
                3 tipos 
                - Por valor
                - Por referencia
                - Por puntero
                */
                agregarContacto(listaContactos, numContactos); //Aqui es por referencia

                break;
            case MOSTRAR:
                mostrarContactos(listaContactos, numContactos);
                break;
            case BUSCAR:
                buscarContacto(listaContactos, numContactos);
                break;
            case SALIR:
                std::cout << "Saliendo del programa....\n";
                break;
        
            default:
                //Vamos a hacer una acto de fe 
                //El usuario no va a meter un caracter o algo raro
                std::cout << "Opcion no valida.Intente de nuevo\n";
                break;
        }
    } while( opcion != SALIR);

    return 0;
}