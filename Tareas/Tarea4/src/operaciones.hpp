#ifndef OPERACIONES_HPP
#define OPERACIONES_HPP
#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
#include "checkInput.hpp"
#include "matrix.hpp"
using namespace std;

extern bool isOP;

/// @brief Clase que contiene las operaciones basicas de matrices
/// @tparam T Puede ser int, float, double o complex
template <class T>
class OperacionesBasicas {
    public:
        /// @brief Metodo que valida si se pueden sumar o restar dos matrices
        /// @param a Matriz a objeto tipo Matrix
        /// @param b Matriz b objeto tipo Matrix
        /// @return True si se pueden sumar o restar, False si no se pueden sumar o restar
        bool validarSumaResta(Matrix<T> &a, Matrix<T> &b);

        /// @brief Metodo que valida si se pueden multiplicar dos matrices
        /// @param a Matriz a objeto tipo Matrix
        /// @param b Matriz b objeto tipo Matrix
        /// @return True si se pueden multiplicar, False si no se pueden multiplicar
        bool validarMultiplicacion(Matrix<T> &a, Matrix<T> &b);

        /// @brief Metodo que suma dos matrices
        /// @param a Matriz a objeto tipo Matrix
        /// @param b Matriz b objeto tipo Matrix
        /// @param tipoDato Tipo de dato de la matriz
        /// @param complexType Tipo de dato de la parte real e imaginaria de la matriz compleja
        /// @param beginRandom Indica si se deben llenar las matrices con numeros random al inicio
        /// @return Matriz resultante de la suma
        Matrix<T> suma(Matrix<T> &a, Matrix<T> &b,int tipoDato,int complexType,int beginRandom);

        /// @brief Metodo que resta dos matrices
        /// @param a Matriz a objeto tipo Matrix
        /// @param b Matriz b objeto tipo Matrix
        /// @param tipoDato Tipo de dato de la matriz
        /// @param complexType Tipo de dato de la parte real e imaginaria de la matriz compleja
        /// @param beginRandom Indica si se deben llenar las matrices con numeros random al inicio
        /// @return Matriz resultante de la resta
        Matrix<T> resta(Matrix<T> &a, Matrix<T> &b,int tipoDato,int complexType,int beginRandom);

        /// @brief Metodo que multiplica dos matrices
        /// @param a Matriz a objeto tipo Matrix
        /// @param b Matriz b objeto tipo Matrix
        /// @param tipoDato Tipo de dato de la matriz
        /// @param complexType Tipo de dato de la parte real e imaginaria de la matriz compleja
        /// @param beginRandom Indica si se deben llenar las matrices con numeros random al inicio
        /// @return Matriz resultante de la multiplicacion
        Matrix<T> multiplicacion(Matrix<T> &a, Matrix<T> &b,int tipoDato,int complexType,int beginRandom);
        
};
#endif // OPERACIONES_HPP