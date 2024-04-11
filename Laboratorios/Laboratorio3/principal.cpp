#include <iostream>
#include <string>
#include "estructura.hpp"
#include "funciones.hpp"
#include "enum.hpp"
using namespace std;

// Este es un programa que simula una libreria

int main(){
    // Es una variable de tipo puntero
    // listaLibros --> nullptr en el incio
    Libro* listaLibros = nullptr; // Inicializamos la lista de libros como vacía

    int opcion;

    do{
        cout << "Seleccione su opcion: " << endl;
        cout << "1. Agregar un libro" << endl;
        cout << "2. Mostrar todos los  libros" << endl;
        cout << "3. Salir" << endl;
        cin >> opcion; // Aqui si se puede usar cin porque no se necesita leer espacios o una linea completa

        switch (opcion){
            case AGREGAR_LIBRO:
                agregarLibro(listaLibros);
                break;
            case MOSTRAR_LIBROS:
                mostrarLibros(listaLibros);
                break;
            case SALIR:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no permitida." << endl;
                break;
        }
    } while(opcion != 3);

    // Cuando se sale del menu se libera la memoria del heap
    liberarMemoria(listaLibros);

    return 0;
}