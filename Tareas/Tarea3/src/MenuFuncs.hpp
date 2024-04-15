#ifndef MENU_FUNCS_HPP
#define MENU_FUNCS_HPP

#include <iostream>
#include <string>
#include "Struct_Contacto.hpp"
#include "HashTable.hpp"
using namespace std;


/// @brief Enumeracion de las opciones del menu
enum MenuOptions{
    AGREGAR_CONTACTO = 1,
    ELIMINAR_CONTACTO,
    IMPRIMIR_CONTACTOS,
    IMPRIMIR_CONTACTOS_ALPHABETICALLY,
    SALIR
};

/// @brief Enumeracion de las opciones de eliminacion
enum DeleteOptions{
    DELETE_IN_MEMORY = 1,
    DELETE_IN_HASH_TABLE,
    DELETE_IN_BOTH,
    DELETE_EXIT
};

/// @brief Funcion que agrega un contacto a la memoria celular y a la tabla hash
/// @param tabla objeto de la tabla hash
void agregarContactoMemoria(HashTable *tabla);

/// @brief Funcion que elimina un contacto de la memoria celular y de la tabla hash
///
/// Pregunta al usuario si desea eliminar el contacto de la memoria celular, de la tabla hash o de ambos
void eliminarContacto(HashTable *tabla);

/// @brief Funcion que imprime los contactos de la tabla hash
void imprimirContactosHash(HashTable *tabla);

/// @brief Funcion que imprime los contactos de la memoria celular
void imprimirContactosMemoria();

/// @brief Funcion que imprime los nombres de los contactos que estan en la memoria celular y en la tabla hash
/// @param tabla objeto de la tabla hash
void printNamesBoth(HashTable *tabla);

/// @brief Funcion que imprime un dibujo ASCII
void printArt();
#endif //MENU_FUNCS_HPP