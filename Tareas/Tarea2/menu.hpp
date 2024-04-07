#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>
#include "TiposPaises.hpp"
#include "Tools.hpp"
#include "Continente.hpp"
#include "Planeta.hpp"

/// @brief En esta funcion se agrega un pais a un continente.
///
/// @param planeta puntero a la clase planeta.
void agregarPais(Planeta &planeta);

/// @brief En esta funcion se elimina un pais de un continente.
///
/// @param planeta puntero a la clase planeta.
void eliminarPais(Planeta &planeta);

/// @brief En esta funcion se comparan dos paises en la clase planeta.
///
/// @param planeta puntero a la clase planeta.
void compararPaises(Planeta &planeta);
#endif // MENU_HPP