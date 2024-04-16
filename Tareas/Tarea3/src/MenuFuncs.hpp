/*! @file MenuFuncs.hpp
 @brief Declaracion de las funciones del menu
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


#ifndef MENU_FUNCS_HPP
#define MENU_FUNCS_HPP

#include <iostream>
#include <string>
#include "Struct_Contacto.hpp"
#include "HashTable.hpp"
using namespace std;


/// @brief Enumeracion de las opciones del menu
enum MenuOptions{
    AGREGAR_CONTACTO = 1,
    ELIMINAR_CONTACTO,
    IMPRIMIR_CONTACTOS,
    IMPRIMIR_CONTACTOS_ALPHABETICALLY,
    SALIR
};

/// @brief Enumeracion de las opciones de eliminacion
enum DeleteOptions{
    DELETE_IN_MEMORY = 1,
    DELETE_IN_HASH_TABLE,
    DELETE_IN_BOTH,
    DELETE_EXIT
};

/// @brief Funcion que agrega un contacto a la memoria celular y a la tabla hash
/// @param tabla objeto de la tabla hash
void agregarContactoMemoria(HashTable *tabla);

/// @brief Funcion que elimina un contacto de la memoria celular y de la tabla hash
///
/// Pregunta al usuario si desea eliminar el contacto de la memoria celular, de la tabla hash o de ambos
void eliminarContacto(HashTable *tabla);

/// @brief Funcion que imprime los contactos de la tabla hash
void imprimirContactosHash(HashTable *tabla);

/// @brief Funcion que imprime los contactos de la memoria celular
void imprimirContactosMemoria();

/// @brief Funcion que imprime los nombres de los contactos que estan en la memoria celular y en la tabla hash
/// @param tabla objeto de la tabla hash
void printNamesBoth(HashTable *tabla);

/// @brief Funcion que imprime un dibujo ASCII
void printArt();
#endif //MENU_FUNCS_HPP