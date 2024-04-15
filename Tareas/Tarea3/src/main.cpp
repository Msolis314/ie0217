#include <iostream>
#include <string>
#include "Struct_Contacto.hpp"
#include "HashTable.hpp"
#include "MenuFuncs.hpp"
using namespace std;

int main(){
    cout << "Agenda telefonica" << endl;
    cout << "-----------------" << endl;
    printArt();
    cout << "-----------------" << endl;
    cout << "\nIngrese la capacidad de la tabla hash: ";
    int capacidad;
    int opcion;
    cin >> capacidad;
    HashTable *tabla = createTable(capacidad);
    do{
        cout << "1. Agregar contacto" << endl;
        cout << "2. Eliminar contacto" << endl;
        cout << "3. Imprimir contactos" << endl;
        cout << "4. Imprimir contactos ordenados alfabeticamente" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion){
            case AGREGAR_CONTACTO:
                agregarContactoMemoria(tabla);
                break;
            case ELIMINAR_CONTACTO:
                eliminarContacto(tabla);
                break;
            case IMPRIMIR_CONTACTOS:
                imprimirContactosHash(tabla);
                break;
            case IMPRIMIR_CONTACTOS_ALPHABETICALLY:
                imprimirContactosMemoria();
                break;
            case SALIR:
                cout << "Saliendo de la agenda telefonica" << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        } 
    } while (opcion != SALIR);
    return 0;

}