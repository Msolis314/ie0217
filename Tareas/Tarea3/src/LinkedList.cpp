#include "LinkedList.hpp"

void allocateNode(Node *node, string nombre, int telefono){
    node->nombre = nombre;
    node->telefono = telefono;
    node->next = NULL;
}