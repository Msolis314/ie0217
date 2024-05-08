#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
#include "checkInput.hpp"
#include "tools.hpp"
using namespace std;
/// @brief Clase Matrix
/// @tparam T tipo de dato generico
///
/// Clase que representa una matriz de tipo generico
template <class T>
class Matrix{
    private:
        int rows;
        int cols;
        int tipoDato;
        int complexType;
        //friend class OperacionesBasicas;
    public:
        /// @brief Constructor de la clase Matrix default
        /// @param no recibe parametros
        Matrix();

        /// @brief Atributo de la clase Matrix
        /// Necesita ser publico para poder ser accedido por la clase OperacionesBasicas
        vector<vector<T>> matrix;
        vector<vector<complex<T>>> matrixCompleja;

        /// @brief Constructor de la clase Matrix
        /// @param rows Numero de filas de la matriz
        /// @param cols  Numero de columnas de la matriz
        /// @param menu Estructura que contiene los parametros que el usuario debe ingresar
        Matrix(int rows, int cols, int tipoDato, int complexType,int beginRandom);

        /// @brief Sobrecarga del operador +
        /// @return this + b  Matriz resultante de la suma
        Matrix operator+ (Matrix &b);

        /// @brief Sobrecarga del operador -
        /// @return this - b  Matriz resultante de la resta
        Matrix operator- (Matrix &b);

        /// @brief Sobrecarga del operador *
        /// @return this * b  Matriz resultante de la multiplicacion
        Matrix operator* (Matrix &b);

        /// @brief Metodo que setea las dimensiones de la matriz
        bool setDimensiones(int rows, int cols);

        /// @brief Metodo que llena la matriz
        /// Se llama cuando se crea una matriz
        void llenarMatriz();

        void llenarMatrizCompleja();
        /// @brief Metodo que imprime la matriz
        void printMatrix();

        /// @brief Metodo que obtiene las dimensiones de la matriz
        /// @param rows puntero a la variable que almacena el numero de filas
        /// @param cols puntero a la variable que almacena el numero de columnas
        void getDims(int *rows, int *cols);

        void fillMatrixRandom();
    ~Matrix();

};

#endif // MATRIX_HPP