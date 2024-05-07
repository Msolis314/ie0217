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
using namespace std;

/// @brief Estructura que contiene los parametros que el usuario debe ingresar en el programa
struct menu{
    int rowsA , colsA, rowsB, colsB;
    string input;
    int operacion;
    int tipoDato;
    int complexType;

} ;

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
    ENTER_PARAMETERS,
    PRINT_MATRICES,
    DO_OPERATION,
    EXIT
};

/// @brief Funcion para pedirle al usuario los parametros a elegir del programa
/// @param menu estructura que contiene los parametros que el usuario debe ingresar
void askParams(menu &menu);

/// @brief Funcion que le permite al usuario elegir si quiere sobreescribir los parametros de la matriz con numeros random
/// @param menu  estructura que contiene los parametros que el usuario debe ingresar
void generarRandomNumbers(menu &menu);

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


#endif // MENU_HPP