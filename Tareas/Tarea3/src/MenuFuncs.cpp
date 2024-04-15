#include <iostream>
#include <string>
#include "HashTable.hpp"
#include "Struct_Contacto.hpp"
#include "MenuFuncs.hpp"
using namespace std;

//Global variables
extern int numContactos;
extern Contacto *contactos[MAX_CONTACTOS];

/// @note Se agrega el contacto simultaneamente a la memoria celular y a la tabla hash
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


/// @note Se elimina el contacto de la memoria celular y de la tabla hash dando la opcion al usuario de elegir
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
                showContactos();
                cout << "Ingrese el nombre del contacto a eliminar: ";
                cin >> nombre;
                //Se verifica si el contacto existe
                if (checkContactosExits(nombre) == -1){
                    cout << "El contacto no existe" << endl;
                    break;
                }
                //Se elimina el contacto de la memoria celular
                deleteContact(nombre);
                return;
            case DELETE_IN_HASH_TABLE:
                tabla->showContactos();
                cout << "Ingrese el nombre del contacto a eliminar: ";
                cin >> nombre;
                //Se verifica si el contacto existe
                if (tabla->buscar(nombre) == -1){
                    cout << "El contacto no existe" << endl;
                    return;
                }
                telefono = tabla->buscar(nombre);
                //Se elimina el contacto de la tabla hash
                tabla->eliminar(nombre, telefono);

                return;
            case DELETE_IN_BOTH:
                //Se muestra los nombres de los contactos que estan en la memoria celular y en la tabla hash
                printNamesBoth(tabla);
                cout << "Ingrese el nombre del contacto a eliminar: ";
                cin >> nombre;

                //Se verifica si el contacto existe
                if (checkContactosExits(nombre) == -1){
                    cout << "El contacto no existe" << endl;
                    break;
                }
                deleteContact(nombre);

                //Se verifica si el contacto existe
                if (tabla->buscar(nombre) == -1){
                    cout << "El contacto no existe" << endl;
                    break;
                }
                telefono = tabla->buscar(nombre);
                tabla->eliminar(nombre, telefono);
                return;
            case DELETE_EXIT:
                return;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    } while (true);
    
}

/// @note Se imprimen los nombres de los contactos que estan en la memoria celular y en la tabla hash para que el usuario pueda verlos
void printNamesBoth(HashTable *tabla){
    cout << "Contactos en memoria celular y en la tabla hash" << endl;
    //Imprimir los nombres de los contactos que estan en la memoria celular y en la tabla hash
    for (int i = 0; i < numContactos; i++){
        if (tabla->buscar(contactos[i]->nombre) != -1){
            cout << "Nombre: " << contactos[i]->nombre << endl;
        }
    }
}

/// @note Se imprimen los contactos de la tabla hash, para ordenar la llamada a la funcion print de la tabla hash en el main
void imprimirContactosHash(HashTable *tabla){
    cout << "Tabla hash" << endl;
    tabla->print();
}

/// @note Se imprimen los contactos de la memoria celular, para ordenar la llamada a la funcion print de la memoria celular en el main
void imprimirContactosMemoria(){
    cout << "Memoria celular" << endl;
    printContactosAlphabetically();
}

void printArt(){
    std::cout << "  o   o   o  " << std::endl;
    std::cout << " /|\\ /|\\ /|\\ " << std::endl;
    std::cout << " ( ) ( ) ( )" << std::endl;
   
}