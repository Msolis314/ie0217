#include <iostream>
#include <string>
#include "HashTable.hpp"
#include "Struct_Contacto.hpp"
using namespace std;

unsigned long hashFunction(string nombre, int telefono, int capacidad){
    unsigned long hash = 5381;
    int c;
    //Concatenar nombre y telefono para obtener la key
    string key = nombre + to_string(telefono);

    //Iterar sobre la key y calcular el hash
    for (int i = 0; i < key.length(); i++){
        c = key[i];
        hash = ((hash << 5) + hash) + c;
    }

    //Retornar el hash mod la capacidad de la tabla para obtener el indice
    return hash % capacidad;
}

//Constructor de la tabla hash
HashTable::HashTable(int capacidad):capacidad(capacidad){
    //Inicializar la tabla como un array de punteros a Node
    tabla = new Node*[capacidad]();
}

//Insertar un item en la tabla hash
void HashTable::insertar(string nombre,int telefono){
    //Calcular el indice del item-llave
    unsigned long index = hashFunction(nombre,telefono,capacidad);
    //cout << "Index: " << index << endl;
    //Crear un nuevo item
    Node *newNode = new Node(nombre,telefono);
    if (newNode == nullptr){
        cout << "No hay memoria disponible" << endl;
        return;
    }

    if (tabla[index] == nullptr){
        //Si la posicion en la tabla esta vacia, insertar el item
        //no hay colision
        cout << "Se inserto el item" << endl;
        tabla[index] = newNode;
        size++;
        return;
    } else {
        //Si la posicion no esta vacia hubo colision
        Node *temp = tabla[index];
        //Iterar sobre la lista enlazada de la posicion
        while (temp->next != nullptr){
            temp = temp->next;
        }
        //Insertar el item al final de la lista
        temp->next = newNode;
        cout << "Se inserto el item" << endl;
        //asi se resuelve la colision
        //nada se sobreescribe
    }
}

//Eliminar un item de la tabla hash
void HashTable::eliminar(string nombre,int telefono){
    //Calcular el indice del item-llave
    unsigned long index = hashFunction(nombre,telefono,capacidad);

    //Si la posicion en la tabla esta vacia, no hay item que eliminar
    if (tabla[index] == nullptr){
        cout << "No se encontro el item" << endl;
        return;
    }

    //Si la posicion no esta vacia, iterar sobre la lista enlazada
    Node *temp = tabla[index]; //node actual
    Node *prev = nullptr;//node anterior

    //Iterar sobre la lista enlazada
    while (temp != nullptr){
        //Eliminar el item si se encuentra
        if (temp->nombre == nombre && temp-> telefono == telefono){
            if ( prev == nullptr){
                //Si el nodo es el primero en la lista
                //Se actualiza el puntero de la tabla
                tabla[index] = temp->next;
                //Se libera la memoria del item
                delete temp;
            } else {
                //Si el nodo esta en el medio 
                //Se actualiza el puntero del nodo anterior
                prev->next = temp->next;
                //Se libera la memoria del item
                delete temp;
            }
            size--;
            return;
            
        }
    }
   
    cout << "No se encontro el item" << endl;
}

//Printear la tabla hash
void HashTable:: print() {
        for (int i = 0; i < capacidad; ++i) {
           
            Node* current = tabla[i];
            if (current == nullptr) {
                continue;
            }
            cout << "Nodo: " << i << endl;
            while (current != nullptr) {
                cout << "Nombre: " << current->nombre << ", Telefono: " << current->telefono << endl;
                current = current->next;
            }
        }
}

//Buscar un item en la tabla hash
int HashTable::buscar(string nombre){
    //Iterar sobre la tabla hash
    for (int i = 0; i < capacidad; i++){
        //Si la posicion en la tabla esta vacia, no hay item que buscar
        if (tabla[i] == nullptr){
            continue;
        }
        //Si la posicion no esta vacia, iterar sobre la lista enlazada
        Node *temp = tabla[i];
        while (temp != nullptr){
            //Retornar el item si se encuentra
            if (temp->nombre == nombre){
                return temp->telefono;
            }
            temp = temp->next;
        }
    }
    //Retornar -1 si no se encuentra el item
    return -1;
}


//Destructor de la tabla hash
HashTable::~HashTable(){
    for (int i = 0; i < capacidad; i++){
        if (tabla[i] != nullptr){
            Node *temp = tabla[i];
            while (temp != nullptr){
                Node *aux = temp;
                temp = temp->next;
                delete aux;
            }
        }
    }
    delete[] tabla;
}

HashTable* createTable(int capacidad){
    return new HashTable(capacidad);
}