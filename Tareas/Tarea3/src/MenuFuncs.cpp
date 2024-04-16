/*! @file MenuFuncs.cpp
 @brief Implementacion de las funciones del menu
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
#include "HashTable.hpp"
#include "Struct_Contacto.hpp"
#include "MenuFuncs.hpp"
using namespace std;

//Global variables
extern int numContactos;
extern Contacto **contactos;

/// @note Se agrega el contacto simultaneamente a la memoria celular y a la tabla hash
void agregarContactoMemoria(HashTable *tabla){
    string nombre;
    int telefono;

    cout << "Ingrese el nombre del contacto: ";
    cin >> nombre;

    cout << "Ingrese el telefono del contacto: ";
    cin >> telefono;
    //Se investigo como verificar si el input es un numero
    //https://stackoverflow.com/questions/18728754/checking-whether-an-input-is-an-integer
    if (cin.fail()){
        cin.clear();
        cin.ignore();
        cout << "Telefono invalido" << endl;
        return;
    }
    
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