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