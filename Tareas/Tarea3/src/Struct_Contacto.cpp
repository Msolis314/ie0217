/*! @file Struct_Contacto.cpp
 @brief Implementacion de las funciones de la estructura de un contacto
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
using namespace std;

/// Diferencia entre mayusculas y minusculas en ASCII
#define DIFFERENCE_UPPER_LOWER_CASE 32

// Variables globales
Contacto **contactos = (Contacto**)malloc(MAX_CONTACTOS * sizeof(Contacto*)); //Se asigna memoria para un arreglo de punteros a contactos con malloc

int numContactos = 0;

//Funciones

/// @note En esta funcion se agrega un contacto a la memoria celular
/// @note En caso de que el contacto ya exista, se pregunta si se desea sobreescribir
void agregarContacto(string nombre, int telefono){

    if (numContactos == MAX_CONTACTOS){
        cout << "Memoria llena" << endl;
        return;
    }

    Contacto *newContacto;
    //Asignar memoria al nuevo contacto
    newContacto = new Contacto();
    if (newContacto == nullptr){
        cout << "No hay memoria disponible" << endl;
        return;
    }
    newContacto->nombre = nombre;
    newContacto->telefono = telefono;
    

    if (numContactos == 0){
        cout << "No hay contactos" << endl;
        cout << "\nAgregando contacto" << endl;
        contactos[numContactos] = newContacto;
        numContactos++;
        return;
    }

    if (checkContactosExits(nombre) != -1){
        cout << "El nombre del contacto ya existe en la memoria celular" << endl;
        cout << "Desea sobreescribir el contacto (s/n)" << endl;
        char opcion;
        cin >> opcion;
        if (opcion == 'n'){
            delete newContacto;
            return;
        }
        contactos[checkContactosExits(nombre)]->telefono = telefono;
        return;
    }
   

    contactos[numContactos] = newContacto;
    numContactos++;
    
}


/// @note En esta funcion se verifica si un contacto existe en la memoria celular
int checkContactosExits(string nombre){
    for (int i = 0; i < numContactos; i++){
        if (contactos[i] -> nombre == nombre){
            cout << "El contacto existe" << endl;
            return i;
        }
    }
    return -1;
}

/// @note En esta funcion se imprimen los contactos en orden alfabetico utilizando un algoritmo de ordenamiento tipo burbuja
void printContactosAlphabetically(){
    bool swap;
    //Ordenar los contactos en orden alfabetico
    for (int i = 0; i < numContactos - 1; i++){
        swap = false;
        //Comparar los nombres de los contactos
        for (int j = 0; j < numContactos - i - 1; j++){
            //Si el nombre del contacto actual es mayor al siguiente, intercambiar los valores
            if (contactos[j]->nombre > contactos[j + 1]->nombre){
                swapValues(&contactos[j], &contactos[j + 1]);
                swap = true;
            }
        }
        //Si no se hicieron intercambios, el arreglo esta ordenado
        if (!swap){
            break;
        }
    }
    //Imprimir los contactos en orden alfabetico
    for (int i = 0; i < numContactos; i++){
        cout << "Nombre: " << contactos[i]->nombre << ", Telefono: " << contactos[i]->telefono << endl;
    }
}

/// @note En esta funcion se intercambian los valores de dos punteros a contactos
void swapValues(Contacto **i, Contacto **j){
    Contacto *temp = *i;
    *i = *j;
    *j = temp;
}

void showContactos(){
    cout << "Contactos en la memoria celular:" << endl;
    for (int i = 0; i < numContactos; i++){
        cout << "Nombre: " << contactos[i]->nombre << endl;
    }
}
void lowerCasetoUpper(string str){
    for (int i = 0; i < str.length(); i++){
        //Si el caracter es una letra minuscula, convertirlo a mayuscula
        if (str[i] >= 'a' && str[i] <= 'z'){
            //Diferencia entre mayusculas y minusculas en ASCII
            str[i] = str[i] - DIFFERENCE_UPPER_LOWER_CASE; 
        }
    }
}

/// @note En esta funcion se elimina un contacto de la memoria celular, se libera la memoria del contacto y se reorganiza el arreglo de contactos
void deleteContact(string nombre){
    int index = checkContactosExits(nombre);
    if (index == -1){
        cout << "El contacto no existe" << endl;
        return;
    }
    delete contactos[index];
    contactos[index] = nullptr;
    numContactos--;
    //Reorganizar el arreglo de contactos
    for (int i = index; i < numContactos; i++){
        contactos[i] = contactos[i + 1];
    }
   
}

/// @note En esta funcion se libera la memoria de los contactos para evitar memory leaks
void freeMemory(){
    for (int i = 0; i < numContactos; i++){
        delete contactos[i];
    }
}

