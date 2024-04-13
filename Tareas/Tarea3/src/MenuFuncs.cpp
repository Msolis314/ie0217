#include <iostream>
#include <string>
#include "HashTable.hpp"
#include "Struct_Contacto.hpp"
#include "MenuFuncs.hpp"
using namespace std;

void agregarContactoMemoria(HashTable *tabla){
    string nombre;
    int telefono;

    cout << "Ingrese el nombre del contacto: ";
    cin >> nombre;

    cout << "Ingrese el telefono del contacto: ";
    cin >> telefono;
    
    //Se agrega el contacto a la memoria celular
    agregarContacto(nombre, telefono);
    //Se agrega el contacto a la tabla hash
    tabla->insertar(nombre, telefono);

}

void eliminarContacto(HashTable *tabla){
    do{
        cout << "Donde desea eliminar el contacto" << endl;
        cout << "1. Memoria celular" << endl;
        cout << "2. Tabla hash" << endl;
        cout << "3. Ambos" << endl;
        cout << "4. Salir" << endl;
        int opcion;
        cin >> opcion;
        string nombre;
        int telefono;

        switch (opcion){
            case DELETE_IN_MEMORY:
                cout << "Ingrese el nombre del contacto a eliminar: ";
                cin >> nombre;
                if (checkContactosExits(nombre) == -1){
                    cout << "El contacto no existe" << endl;
                    break;
                }
                //Se elimina el contacto de la memoria celular
                deleteContact(nombre);
                break;
            case DELETE_IN_HASH_TABLE:
                cout << "Ingrese el nombre del contacto a eliminar: ";
                cin >> nombre;
                if (tabla->buscar(nombre) == -1){
                    cout << "El contacto no existe" << endl;
                    break;
                }
                telefono = tabla->buscar(nombre);
                //Se elimina el contacto de la tabla hash
                tabla->eliminar(nombre, telefono);
                break;
            case DELETE_IN_BOTH:
                cout << "Ingrese el nombre del contacto a eliminar: ";
                cin >> nombre;
                if (checkContactosExits(nombre) == -1){
                    cout << "El contacto no existe" << endl;
                    break;
                }
                deleteContact(nombre);
                if (tabla->buscar(nombre) == -1){
                    cout << "El contacto no existe" << endl;
                    break;
                }
                telefono = tabla->buscar(nombre);
                tabla->eliminar(nombre, telefono);
                break;
            case DELETE_EXIT:
                return;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    } while (true);
    
}

void imprimirContactosHash(HashTable *tabla){
    cout << "Tabla hash" << endl;
    tabla->print();
}

void imprimirContactosMemoria(){
    cout << "Memoria celular" << endl;
    printContactosAlphabetically();
}