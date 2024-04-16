/*! @file main.cpp
 @brief Main del programa
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
    free(contactos);
    return 0;

}