#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP
#include <string>
#include <vector>
#include <algorithm>
#include "Libro.hpp"

class Biblioteca {
private:
    std::vector<Libro> libros;

public:
    void agregarLibro(const Libro& libro);

    void mostrarLibros();

    void ordenarLibrosPorAnio();

    std::vector<Libro>::iterator buscarLibroPorTitulo(const std::string& titulo);

    std::vector<Libro>::iterator end();
};
#endif // BIBLIOTECA_HPP