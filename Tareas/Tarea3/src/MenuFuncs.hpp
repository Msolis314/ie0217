#ifndef MENU_FUNCS_HPP
#define MENU_FUNCS_HPP

#include <iostream>
#include <string>
#include "Struct_Contacto.hpp"
#include "HashTable.hpp"
using namespace std;

enum MenuOptions{
    AGREGAR_CONTACTO = 1,
    ELIMINAR_CONTACTO,
    IMPRIMIR_CONTACTOS,
    IMPRIMIR_CONTACTOS_ALPHABETICALLY,
    SALIR
};

enum DeleteOptions{
    DELETE_IN_MEMORY = 1,
    DELETE_IN_HASH_TABLE,
    DELETE_IN_BOTH,
    DELETE_EXIT
};

void agregarContactoMemoria(HashTable *tabla);

void eliminarContacto(HashTable *tabla);

void imprimirContactosHash(HashTable *tabla);

void imprimirContactosMemoria();

#endif //MENU_FUNCS_HPP