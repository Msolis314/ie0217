/*! @file menuFuncs.hpp
 @brief Declaracion de las funciones del menu
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

#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
#include "checkInput.hpp"
#include "operaciones.hpp"
#include "matrix.hpp"
#include "tools.hpp"

using namespace std;

/// @brief Funcion para imprimir las matrices
/// @tparam T Dato generico de la matriz
/// @param menu estructura que contiene los parametros que el usuario debe ingresar
/// @param a Matriz a
/// @param b Matriz b
template <class T>
void printMatrices(menu &menu, Matrix<T> &a, Matrix<T> &b);

/// @brief Funcion para realizar la operacion seleccionada por el usuario
/// @tparam T Dato generico de la matriz
/// @param menu estructura que contiene los parametros que el usuario debe ingresar
/// @param a Matriz a
/// @param b Matriz b
template <class T>
void doOperation(menu &menu, Matrix<T> &a, Matrix<T> &b);

/// @brief Funcion para pedirle al usuario los parametros a elegir del programa
/// @param menu estructura que contiene los parametros que el usuario debe ingresar
template <typename T>
void generarRandomNumbers(menu &menu, Matrix<T> &a, Matrix<T> &b);

/// @brief Funcion para mostrar el menu de opciones
/// @param menu estructura que contiene los parametros que el usuario debe ingresar
template <typename T>
void menuDisplay(menu &menu, Matrix<T> &a, Matrix<T> &b);


#endif // MENU_HPP