/// @file Header de la clase Continente
///
/// @brief Clase que representa un continente.

/*!
MIT License

Copyright (c) 2024 Msolis314

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#ifndef CONTINENTE_HPP
#define CONTINENTE_HPP
#include <string>
#include <iostream>
#include "Pais.hpp"
#include "TiposPaises.hpp"


/// @brief Clase que representa un continente.
///
/// Esta clase se encuentra compuesta por un nombre, un entero que indica la cantidad de paises del primer mundo, un entero que indica la cantidad de paises en desarrollo, un arreglo de paises del primer mundo y un arreglo de paises en desarrollo.
class Continente{
    private:
            std::string nombre;
            int numPaisesPrimerMundo;
            int numPaisesDesarrollo;
            PrimerMundo* paisesPrimerMundo[MAX_COUNTRIES]; //arreglo de paises del primer mundo
            Desarrollo* paisesDesarrollo[MAX_COUNTRIES];//arreglo de paises en desarrollo
        public:
            /// @brief Constructor de la clase Continente, inicializa el nombre del continente.
            /// @param nombre nombre del continente
            Continente(std::string nombre);

            /// @brief Establecer los paises del primer mundo.
            /// @note en caso que el continente no sea real por defecto se pregunta al usuario si desea agregar paises del primer mundo.
            void setPaisesPrimerMundo();

            /// @brief Establecer los paises en desarrollo.
            /// @note en caso que el continente no sea real por defecto se pregunta al usuario si desea agregar paises en desarrollo.
            void setPaisesDesarrollo();

            /// @brief Contar la cantidad de paises con aeropuerto.
            int countCountriesAirport();

            /// @brief Establecer paises por defecto.
            void defaulCountries();

            /// @brief Acceder al atributo nombre.
            std::string getNombre();

            /// @brief Agregar un pais al continente.
            /// @param typeCountry Tipo de pais. Puede ser DESARROLLO o PRIMER_MUNDO.
            /// @param nombre nombre del pais
            void addCountry(int typeCountry, std::string nombre);

            /// @brief Eliminar un pais del continente.
            void deleteCountry();

            /// @brief Imprimir los paises del continente.
            void printCountries();

            /// @brief Comparar dos paises.
            /// @param nombre1 nombre del primer pais
            /// @param nombre2 nombre del segundo pais
            void compareCountries(std::string nombre1, std::string nombre2);

            /// @brief Mostrar la informacion general del continente.
            /// @note Se muestra el nombre del continente y la cantidad de paises del primer mundo y en desarrollo.
            void printGeneralInfo();

            /// @brief Mostrar la informacion de los paises del continente.
            void print();

        /// @brief Destructor de la clase Continente.
        /// Elimina los objetos paises del primer mundo y en desarrollo.
        ~Continente();
};
#endif // CONTINENTE_HPP