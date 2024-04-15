#ifndef STRUCT_CONTACTO_HPP
#define STRUCT_CONTACTO_HPP

#include <iostream>
#include <string>
using namespace std;
#define MAX_CONTACTOS 1000


/// @brief Estructura de un contacto
///
/// @note Estructura de un contacto en la memoria celular
typedef struct Contacto Contacto;

//Variables globales
extern int numContactos;
extern Contacto *contactos[MAX_CONTACTOS];
//Lista de punteros a contactos


/// @brief Estructura de un contacto
///
/// Contiene el nombre y el telefono de un contacto
struct Contacto{
    string nombre;
    int telefono;  
};

/// @brief Agrega un contacto a la memoria celular
///
/// @param nombre Nombre del contacto
/// @param telefono Telefono del contacto
void agregarContacto(string nombre, int telefono);

/// @brief Verifica si un contacto existe en la memoria celular
///
/// @param nombre Nombre del contacto a verificar
int checkContactosExits(string nombre);

/// @brief Imprime los contactos en orden alfabetico
///
/// Imprime los contactos en orden alfabetico de la memoria celular
void printContactosAlphabetically();

/// @brief Libera la memoria de los contactos
///
/// Libera la memoria de los contactos de la memoria celular
void freeMemory();

/// @brief Elimina un contacto de la memoria celular
///
/// @param nombre Nombre del contacto a eliminar
void deleteContact(string nombre);


/// @brief Convierte un string de minusculas a mayusculas
void lowerCasetoUpper(string str);

/// @brief Muestra los contactos de la memoria celular
///
/// Muestra los contactos de la memoria celular 
/// @note Se muestra el nombre es para el menu
void showContactos();

/// @brief Intercambia los valores de dos punteros a contactos
void swapValues(Contacto **i, Contacto **j);

#endif //STRUCT_CONTACTO_HPP