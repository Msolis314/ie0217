#include <iostream>
#include "libro.hpp"

Libro:: Libro(
    const std::string& titulo, const std::string& autor
) : titulo(titulo), autor(autor){}

void Libro::mostrarInfo(){
    std::cout << "Titulo: " << titulo;
    std::cout << ", Autor: " << autor << std::endl;
}