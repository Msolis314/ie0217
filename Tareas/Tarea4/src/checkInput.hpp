/*! @file CheckInput.hpp
 @brief Declaracion de la clase ValidadorDeEntrada
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


#ifndef CHECKINPUT_HPP
#define CHECKINPUT_HPP
#include <iostream>
#include <string>

/// @brief Clase ValidadorDeEntrada
/// @tparam T Parametro generico
template <class T>
class ValidadorDeEntrada {
    public:
        /// @brief Este metodo valida si el usuario ingreso un numero que corresponde al tipo de dato que se espera
        /// @param input entrada del usuario
        /// @param value puntero que va a contener el valor convertido
        /// @return True si el valor ingresado es del tipo de dato esperado, False si no
        bool validarTipoDato(std::string input, T *value);

        /// @brief Este metodo valida si el tamaño de la matriz es mayor a 0
        /// @param tamano El tamaño de la matriz
        /// @return True si el tamaño de la matriz es mayor a 0, False si no
        bool validarDimensiones(int tamano);
};
#endif // CHECKINPUT_HPP