/*! @file LinkedList.hpp
 @brief Definicion de la estructura de un nodo
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


#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <string>
using namespace std;

/// @brief Estructura de un nodo
///
/// @details Estructura de un nodo de una lista enlazada que contiene un nombre, un telefono y un puntero al siguiente nodo
/// @note Estructura de un nodo de una lista enlazada
typedef struct Node{
    string nombre;
    int telefono;
    Node *next;
    Node (string name, int telefono){
        this->next = nullptr;
        this->nombre = name;
        this->telefono = telefono;
    }
} Node;





#endif //LINKED_LIST_HPP