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
/*
/// @brief Estructura que contiene los parametros que el usuario debe ingresar en el programa
struct menu{
    int rowsA , colsA, rowsB, colsB;
    string input;
    int operacion;
    int tipoDato;
    int complexType;
    int beginRandom;
    int whichMatrix;

} ;
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
};*/

/// @brief Funcion para pedirle al usuario los parametros a elegir del programa
/// @param menu estructura que contiene los parametros que el usuario debe ingresar
template <typename T>
void generarRandomNumbers(menu &menu, Matrix<T> &a, Matrix<T> &b);

/// @brief Funcion para imprimir las matrices
/// @tparam T Dato generico de la matriz
/// @param menu estructura que contiene los parametros que el usuario debe ingresar
/// @param a Matriz a
/// @param b Matriz b
template <typename T>
void printMatrices(menu &menu, Matrix<T> &a, Matrix<T> &b);

/// @brief Funcion para realizar la operacion seleccionada por el usuario
/// @tparam T Dato generico de la matriz
/// @param menu estructura que contiene los parametros que el usuario debe ingresar
/// @param a Matriz a
/// @param b Matriz b
template <typename T>
void doOperation(menu &menu, Matrix<T> &a, Matrix<T> &b);

template <typename T>
T randomNum(int type);

template <typename T>
void menuDisplay(menu &menu, Matrix<T> &a, Matrix<T> &b);


#endif // MENU_HPP