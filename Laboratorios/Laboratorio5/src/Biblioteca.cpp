#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Libro.hpp"
#include "Biblioteca.hpp"

//Funcion para agregar un libro a la biblioteca
//Se agrega un libro al final del vector
//Se pasa un objeto de tipo Libro
void Biblioteca::agregarLibro(const Libro& libro) {
    //Se agrega un libro al final del vector
    libros.push_back(libro);
}

//Funcion para mostrar los libros de la biblioteca
void Biblioteca::mostrarLibros() {
    //Se utilize auto para deducir el tipo de variable en este caso Libro
    //Se itera sobre el vector de libros
    for (const auto& libro : libros) {
        //Se accede a los atributos del objeto Libro
        std::cout << libro.titulo << ", " << libro.autor << ", " << libro.anioPublicacion << std::endl;
    }
}

//Funcion para ordenar los libros por año de publicación
void Biblioteca::ordenarLibrosPorAnio() {
    //Se utiliza la funcion sort de la libreria algorithm
    //Se pasa el inicio y el final del vector
    std::sort(libros.begin(), libros.end());
    //Se ordenan en la memoria los libros por año de publicación
    //Se utiliza el operador < sobrecargado en la clase Libro
}

std::vector<Libro>::iterator Biblioteca::buscarLibroPorTitulo(const std::string& titulo) {
    /*LA funcion find_if recibe 3 parametros
    1. El inicio del vector
    2. El final del vector
    3. Una funcion lambda que recibe un libro y compara el titulo del libro con el titulo pasado como parametro
    Esta funcion devuelve un iterador al libro encontrado o al final del vector si no se encuentra el libro
    */
    //Se utiliza la funcion find_if de la libreria algorithm
    //para buscar un libro por titulo
    return std::find_if(libros.begin(), libros.end(), [&titulo](const Libro& l) {
        //Se compara el titulo de un libro de la iteracion con el titulo pasado como parametro
        return l.titulo == titulo;
    });
}

//Funcion para obtener el iterador al final del vector de libros
//Se necesita porque es un atributo privado
std::vector<Libro>::iterator Biblioteca::end() {
    return libros.end();
}