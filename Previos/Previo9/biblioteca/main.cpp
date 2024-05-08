#include "biblioteca.hpp"

int main() {
    //Crear un objeto de la clase Biblioteca
    Biblioteca biblioteca;

    //Agregar libros al catalogo
    biblioteca.agregarLibro("El Gran Gatsby", "F. Scott Fitzgerald");
    biblioteca.agregarLibro("1984", "George Orwell");

    biblioteca.mostrarCatalogo();

    return 0;
}