#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP
#include <iostream>
#include <string>
#include "Struct_Contacto.hpp"
#include "LinkedList.hpp"
using namespace std;

unsigned long hashFunction(string nombre, int telefono, int capacidad);

//struct del item de la tabla hash 
typedef struct HashItem
{
    string nombre; //Key del item
    int telefono; //Value del item
} HashItem;

//clase de la tabla hash
class HashTable
{
    private:
        Node **tabla; //Array de punteros a Node
        int capacidad;
        int size;
        int head_index;
    public:
        HashTable(int capacidad);
        ~HashTable();
        void showContactos();
       
        void insertar(string nombre, int telefono);
        void eliminar(string nombre, int telefono);
        int buscar(string nombre);
        void print();
        //void print_search(string nombre);
};  

HashTable* createTable(int capacidad);

//void freeTable(HashTable *tabla);





#endif //HASH_TABLE_HPP