/// @file Header de las clases PrimerMundo y Desarrollo
///
/// @brief Clases que representan paises del primer mundo y en desarrollo.

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

#ifndef TIPOS_PAISES_HPP
#define TIPOS_PAISES_HPP
#include <string>
#include <iostream>
#include "Pais.hpp"
#include "Tools.hpp"
/// @brief Clase que representa un país del primer mundo.
///
/// @details Esta clase hereda de la clase Pais y representa un país del primer mundo.
///Se encarga de calcular la población activa y de imprimir los datos del país.
class PrimerMundo : public Pais{
    private:
        int workingPopulation;

        /// @brief Calcular la poblacion trabajadora.
        /// @return Numero de habitantes trabajadores.
        int calculateWorkingPopulation() const;

        bool hasInvestigationCenter;
    public:
        PrimerMundo(std::string nombre);


        /// @brief Generar un id primo unico para el país.
        /// @return Id del país.
        int generateId() const;

        /// @brief Establecer si el pais tiene centros de investigacion.
        /// @return True si tiene centros de investigacion, false en caso contrario.
        bool investigationCenter();

        /// @brief Devolver la poblacion trabajadora.
        void getWorkingPopulation();

        bool setG5();

        /// @brief Imprimir los datos del país.
        void print();

};


/// @brief Clase que representa un país en desarrollo.
///
/// @details Esta clase hereda de la clase Pais y representa un país en desarrollo.
class Desarrollo : public Pais{
    public:
        Desarrollo(std::string nombre);

        /// @brief Los ids de los paises en desarrollo son numeros pares.
        /// @return id del pais.
        int generateId() const;

        /// @brief Imprimir los datos del país.
        void print();
};

#endif // TIPOS_PAISES_HPP