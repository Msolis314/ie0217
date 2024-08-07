/*! @file HashTable.hpp
 @brief Declaracion de la clase HashTable
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

#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP
#include <iostream>
#include <string>
#include "Struct_Contacto.hpp"
#include "LinkedList.hpp"
using namespace std;

/// @brief Funcion para calcular el hash de un contacto
/// @param nombre Nombre del contacto
/// @param telefono Telefono del contacto
/// @param capacidad Capacidad de la tabla hash
/// @return Indice del hash
unsigned long hashFunction(string nombre, int telefono, int capacidad);

//struct del item de la tabla hash 
typedef struct HashItem
{
    string nombre; //Key del item
    int telefono; //Value del item
} HashItem;

/// @brief Clase de la tabla hash
///
/// @details Clase de la tabla hash que contiene un array de punteros a Node
class HashTable
{
    private:
        Node **tabla; //Array de punteros a Node
        int capacidad;
        int size;
        int head_index;
    public:
        /// @brief Constructor de la tabla hash
        /// @param capacidad Capacidad de la tabla hash
        /// @return Objeto de la tabla hash
        HashTable(int capacidad);

        /// @brief Destructor de la tabla hash
        /// 
        /// Libera la memoria de la tabla hash
        ~HashTable();

        /// @brief Funcion que muestra los contactos de la tabla hash
        void showContactos();

        /// @brief Funcion que inserta un contacto en la tabla hash
        /// @param nombre Nombre del contacto
        /// @param telefono Telefono del contacto
        /// Se encarga de insertar un contacto en la tabla hash
        void insertar(string nombre, int telefono);

        /// @brief Funcion que elimina un contacto especifico de la tabla hash
        /// @param nombre Nombre del contacto
        /// @param telefono Telefono del contacto
        /// Se encarga de eliminar un contacto especifico de la tabla hash por nombre y telefono
        void eliminar(string nombre, int telefono);

        /// @brief Funcion que busca un contacto en la tabla hash
        /// @param nombre 
        /// @return -1 si no se encontro el contacto, 0 si se encontro
        int buscar(string nombre);

        /// @brief Funcion que imprime los contactos de la tabla hash
        void print();
        //void print_search(string nombre);
};  

/// @brief Funcion para asignar memoria a la tabla hash
/// @param capacidad tamaño de la tabla hash establecido por el usuario
/// @return Objeto de la tabla hash
HashTable* createTable(int capacidad);

//void freeTable(HashTable *tabla);





#endif //HASH_TABLE_HPP