#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <string>
using namespace std;

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