#ifndef STRUCT_CONTACTO_HPP
#define STRUCT_CONTACTO_HPP

#include <iostream>
#include <string>
using namespace std;
#define MAX_CONTACTOS 1000

typedef struct Contacto Contacto;
//Lista de punteros a contactos


//Estructura de un contacto
struct Contacto{
    string nombre;
    int telefono;  
};


void agregarContacto(string nombre, int telefono);

int checkContactosExits(string nombre);

void printContactosAlphabetically();

void freeMemory();

void deleteContact(string nombre);

void lowerCasetoUpper(string str);

void swapValues(int *i, int *j);

#endif //STRUCT_CONTACTO_HPP