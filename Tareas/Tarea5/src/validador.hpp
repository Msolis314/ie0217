/*! @file Validador.hpp
 @brief definicion de la clase ValidadorEmail
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

#ifndef VALIDADOR_HPP
#define VALIDADOR_HPP 
#include <string>

/// @brief Clase que valida un correo electronico
/// @details La clase ValidadorEmail valida un correo electronico, verificando que tenga un solo @, que tenga un nombre, un dominio y una extension
class ValidadorEmail {
    private: 
        /// @brief Correo electronico
        std::string email;
    public:
        void validarCorreo(std::string email,bool &valido);


        /// @brief Metodo que cuenta cuantas veces se repite un patron en una cadena
        /// @param email string que se va a analizar
        /// @param pattern patron regex que se va a buscar
        /// @return numero de veces que se repite el patron en la cadena
        int countCharMatch(std::string email, std::string pattern);

        /// @brief Metodo que valida la extension de un correo electronico
        /// @param email correo electronico
        /// @return true si la extension es valida, false si no
        bool valExtention(std::string email);

        /// @brief metodo que valida el dominio de un correo electronico
        /// @param email correo electronico
        /// @return true si el dominio es valido, false si no
        bool valDomain(std::string email);

        /// @brief Metodo que obtiene el dominio de un correo electronico
        /// @param email correo electronico
        /// @return dominio del correo electronico
        std::string getDomain(std::string email);

        /// @brief Metodo que valida el nombre de un correo electronico
        /// @param email correo electronico
        /// @return true si el nombre es valido, false si no

        bool valName(std::string email);
};

#endif // VALIDADOR_HPP