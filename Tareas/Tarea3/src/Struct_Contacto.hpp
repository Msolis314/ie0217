

/*! @file Struct_Contacto.hpp
 @brief Definicion de la estructura de un contacto
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

#ifndef STRUCT_CONTACTO_HPP
#define STRUCT_CONTACTO_HPP

#include <iostream>
#include <string>
using namespace std;
#define MAX_CONTACTOS 1000


/// @brief Estructura de un contacto
///
/// @note Estructura de un contacto en la memoria celular
typedef struct Contacto Contacto;

//Variables globales
extern int numContactos;

//extern Contacto *contactos[MAX_CONTACTOS];
extern Contacto **contactos;

//Lista de punteros a contactos


/// @brief Estructura de un contacto
///
/// Contiene el nombre y el telefono de un contacto
struct Contacto{
    string nombre;
    int telefono;  
};

/// @brief Agrega un contacto a la memoria celular
///
/// @param nombre Nombre del contacto
/// @param telefono Telefono del contacto
void agregarContacto(string nombre, int telefono);

/// @brief Verifica si un contacto existe en la memoria celular
///
/// @param nombre Nombre del contacto a verificar
int checkContactosExits(string nombre);

/// @brief Imprime los contactos en orden alfabetico
///
/// Imprime los contactos en orden alfabetico de la memoria celular
void printContactosAlphabetically();

/// @brief Libera la memoria de los contactos
///
/// Libera la memoria de los contactos de la memoria celular
void freeMemory();

/// @brief Elimina un contacto de la memoria celular
///
/// @param nombre Nombre del contacto a eliminar
void deleteContact(string nombre);


/// @brief Convierte un string de minusculas a mayusculas
void lowerCasetoUpper(string str);

/// @brief Muestra los contactos de la memoria celular
///
/// Muestra los contactos de la memoria celular 
/// @note Se muestra el nombre es para el menu
void showContactos();

/// @brief Intercambia los valores de dos punteros a contactos
void swapValues(Contacto **i, Contacto **j);

#endif //STRUCT_CONTACTO_HPP