#ifndef ESTRUCTURA_HPP
#define ESTRUCTURA_HPP

#include <iostream>
#include <string>
using namespace std;


// Definición de la estructura Libro, que contiene los elementos de la librería
struct Libro {
    // 3 miembros tipicos
    string titulo;
    string autor;
    string genero;

    //miembro de un puntero a la estructura Libro
    Libro* siguiente; // Un puntero es un tipo de dato que almacena la dirección de memoria de otra variable
};

#endif // ESTRUCTURA_HPP