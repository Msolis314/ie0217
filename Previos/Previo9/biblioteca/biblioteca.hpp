#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <vector>
#include "libro.hpp"

class Biblioteca {
public:
    // Agrega un libro al catalogo
    void agregarLibro(
        const std::string& titulo, 
        const std::string& autor
    );
    // Muestra el catalogo de libros
    void mostrarCatalogo();
private:
    //Vector de objetos de la clase Libro
    std::vector<Libro> catalogo;
};

#endif // BIBLIOTECA_HPP