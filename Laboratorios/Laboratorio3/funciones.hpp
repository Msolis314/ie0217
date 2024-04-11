#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include <iostream>
#include <string>
#include "estructura.hpp"

// Se este mandando la  referencia de una variable de tipo Libro puntero
// En esta función se agrega un libro a la lista de libros
void agregarLibro(Libro *&lista);

// En esta función se muestran los libros de la lista
//Se itera hasta encontrar un puntero nulo
void mostrarLibros(Libro *lista);

// En esta función se libera la memoria de la lista de libros
void liberarMemoria(Libro *&lista);

#endif // FUNCIONES_HPP