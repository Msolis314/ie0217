#include <iostream>
#include <vector>
#include <string>
#include "Libro.hpp"

// Constructor
Libro::Libro(std::string t, std::string a, int anio) : titulo(t), autor(a), anioPublicacion(anio) {}

// Sobrecarga del operador < para poder ordenar los libros por año de publicación
bool Libro::operator<(const Libro& l) const {
    return anioPublicacion < l.anioPublicacion;
}