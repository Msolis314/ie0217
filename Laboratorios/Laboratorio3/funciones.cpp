#include <iostream>
#include <string>
#include "estructura.hpp"
#include "funciones.hpp"
using namespace std;

// Se este mandando la  referencia de una variable de tipo Libro puntero
void agregarLibro(Libro *&lista){
    Libro* nuevoLibro = new Libro(); // Reservamos memoria para un nuevo libro

    cout << "Ingrese el titulo del libro: " << endl;
    cin.ignore(); // Se usa para limpiar la entrada
    getline(cin, nuevoLibro->titulo);
    // getline devuelve el valor ingresado por el usuario aunque contenga espacios

    cout << "Ingrese el autor del libro: " << endl;
    getline(cin, nuevoLibro->autor);

    cout << "Ingrese el genero del libro: " << endl;
    getline(cin, nuevoLibro->genero);

    nuevoLibro->siguiente = lista; // Se asigna el puntero de lista al nuevo libro

    lista  = nuevoLibro; //Se asigna el nuevo puntero a lista

    cout << "Libro agregado correctamente" << endl;


}

void mostrarLibros(Libro *lista){
    //Lista es un puntero a la estructura Libro
    if (lista == nullptr){
        cout << "La libreria no tiene libros" << endl;
        return; // Termina la ejecución de la función
    }

    cout << "Lista de libros: " << endl;

    while(lista != nullptr){
        cout << "Titulo: " << lista->titulo << endl;
        cout << "Autor: " << lista->autor << endl;
        cout << "Genero: " << lista->genero << endl << endl;
        lista = lista->siguiente;
    }
}

void liberarMemoria(Libro*& lista){
    //Antes de liberar memoria se deben actualizar los punteros
    while(lista != nullptr){
        Libro* temp = lista;// Se guarda la direccion del primer libro
        lista = lista->siguiente; // Se guarda la direccion del siguiente libro
        delete temp; // Se libera la memoria del libro guardado en temp
    }
    // Se libera la memoria del último libro
}