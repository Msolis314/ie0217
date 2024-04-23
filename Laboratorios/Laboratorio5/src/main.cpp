#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Libro.hpp"
#include "Biblioteca.hpp"

int main() {
    //Se crea un objeto de tipo Biblioteca
    Biblioteca miBiblioteca;
    
    //Se agregan libros a la biblioteca
    miBiblioteca.agregarLibro({"Cien años de soledad", "Gabriel García Márquez", 1967});
    miBiblioteca.agregarLibro({"1984", "George Orwell", 1949});
    miBiblioteca.agregarLibro({"El señor de los anillos", "J.R.R. Tolkien", 1954});
    miBiblioteca.agregarLibro({"Don Quijote de la Mancha", "Miguel de Cervantes", 1605});
    miBiblioteca.agregarLibro({"La Odisea", "Homero", -800});
    miBiblioteca.agregarLibro({"La Iliada", "Homero", -800});
    miBiblioteca.agregarLibro({"Amor en los tiempos del cólera", "Gabriel García Márquez", 1985});
    miBiblioteca.agregarLibro({"Prohibido suicidarse en primavera", "Alejandro Casona", 1937});
    miBiblioteca.agregarLibro({"El coronel no tiene quien le escriba", "Gabriel García Márquez", 1961});
    miBiblioteca.agregarLibro({"Los hermanos Karamazov", "Fiodor Dostoievski", 1880});

    //Se ordenan los libros por año de publicación
    miBiblioteca.ordenarLibrosPorAnio();

    //Se muestran los libros de la biblioteca ordenados por año de publicación
    miBiblioteca.mostrarLibros();

    //Se busca un libro por titulo
    auto libro = miBiblioteca.buscarLibroPorTitulo("1984");

    //Si el libro se encuentra se imprime el titulo
    //Sino como se devuelve un iterador al final del vector se imprime que no se encontro el libro
    if (libro != miBiblioteca.end()) {
        std::cout << "Libro encontrado: " << libro->titulo << std::endl;
    } else {
        std::cout << "Libro no encontrado." << std::endl;
    }

    return 0;
}