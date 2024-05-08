/*! @file tools.hpp
 @brief Declaracion de las funciones de la clase Tools
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

#ifndef TOOL_HPP
#define TOOL_HPP

#include <iostream>
#include <string>
/// @brief Estructura que contiene los parametros que el usuario debe ingresar en el programa
struct menu{
    int rowsA , colsA, rowsB, colsB;
    std::string input;
    int operacion;
    int tipoDato;
    int complexType;
    int beginRandom;
    int whichMatrix;

} typedef menu;
enum whichMatrix
{
    A = 1,
    B,
    BOTH
};
enum Operation
{
    SUMA = 1,
    RESTA,
    MULTIPLICACION
};
enum DataType
{
    INT = 1,
    FLOAT,
    DOUBLE,
    COMPLEX
};
enum MenuOptions
{
    GENERATE_RANDOM_NUMBERS = 1,
    PRINT_MATRICES,
    DO_OPERATION,
    EXIT
};

/// @brief Funcion para generar un numero aleatorio
/// @tparam T 
/// @param type 
/// @return 
template <typename T>
T randomNum(int type);


#endif // TOOL_HPP
