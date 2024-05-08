/*! @file operaciones.cpp
 @brief Implementacion de la clase OperacionesBasicas
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


#ifndef OPERACIONES_CPP
#define OPERACIONES_CPP

#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
#include "checkInput.hpp"
#include "matrix.hpp"
#include "operaciones.hpp"
using namespace std;

/// @details Para que las operaciones basicas se puedan realizar, las matrices deben tener las mismas dimensiones
/// @tparam T Puede ser int, float, double o complex
template <class T>
bool OperacionesBasicas<T>:: validarSumaResta(Matrix<T> &a, Matrix<T> &b){
    //Se obtienen las dimensiones de las matrices
    int rowsA, colsA, rowsB, colsB;
    a.getDims(&rowsA, &colsA);
    b.getDims(&rowsB, &colsB);
    //Se valida si las matrices tienen las mismas dimensiones
    try {
        if (rowsA != rowsB || colsA != colsB){
            throw invalid_argument("Las matrices no tienen las mismas dimensiones");
        }
        return true;
    }
    catch (invalid_argument &e){
        //Si las matrices no tienen las mismas dimensiones, se imprime un mensaje de error
        cout << e.what() << endl;
        return false;
    }
}

/// @details Para que la multiplicacion de matrices se pueda realizar, el numero de columnas de la matriz A debe ser igual al numero de filas de la matriz B
template <class T>
bool OperacionesBasicas<T>:: validarMultiplicacion(Matrix<T> &a, Matrix<T> &b){
    int rowsA, colsA, rowsB, colsB;
    a.getDims(&rowsA, &colsA);
    b.getDims(&rowsB, &colsB);
    //Se valida si el numero de columnas de la matriz A es igual al numero de filas de la matriz B
    try {
        if (colsA != rowsB){
            throw invalid_argument("El numero de columnas de la matriz A no es igual al numero de filas de la matriz B");
        }
        return true;
    }
    catch (invalid_argument &e){
        cout << e.what() << endl;
        return false;
    }
}

template <class T>
Matrix<T> OperacionesBasicas<T>::suma(Matrix<T> &a, Matrix<T> &b,int tipoDato,int complexType,int beginRandom){
    //Se inicializa la variable isOP en true para indicar que se esta realizando una operacion
    //Y que se llenara la matriz con numeros random
    isOP = true;
    int rowsA, colsA, rowsB, colsB;

    //Se obtienen las dimensiones de las matrices
    a.getDims(&rowsA, &colsA);
    b.getDims(&rowsB, &colsB);

    //Se crea una matriz resultante de la suma
    Matrix<T> resultSum(rowsA, colsA, tipoDato, complexType, beginRandom);
    if (tipoDato == COMPLEX){
        for ( int i = 0; i <rowsA; i++){
            //Se utiliza la funcion transform para sumar las matrices
            transform(a.matrixCompleja[i].begin(), a.matrixCompleja[i].end(), b.matrixCompleja[i].begin(), resultSum.matrixCompleja[i].begin(), plus<complex<T>>());
        }
        //a + b = resultSum
        return resultSum;
    } else {
        for ( int i = 0; i <rowsA; i++){
            transform(a.matrix[i].begin(), a.matrix[i].end(), b.matrix[i].begin(), resultSum.matrix[i].begin(), plus<T>());
        }
        //a + b = resultSum
        return resultSum;
    }

}

/// @details Se realiza la resta de dos matrices
template <class T>
Matrix<T> OperacionesBasicas<T>::resta(Matrix<T> &a, Matrix<T> &b,int tipoDato,int complexType,int beginRandom){
    //Se inicializa la variable isOP en true para indicar que se esta realizando una operacion
    isOP = true;
    int rowsA, colsA, rowsB, colsB;
    a.getDims(&rowsA, &colsA);
    b.getDims(&rowsB, &colsB);

    //Se crea una matriz resultante de la resta
    Matrix<T> resultResta(rowsA, colsA, tipoDato, complexType, beginRandom);

    //Si es una matriz compleja, se realiza la resta de las matriz complejas
    if (tipoDato == COMPLEX ){
        for ( int i = 0; i <rowsA; i++){
            transform(a.matrixCompleja[i].begin(), a.matrixCompleja[i].end(), b.matrixCompleja[i].begin(), resultResta.matrixCompleja[i].begin(), minus<complex<T>>());
        }
        //a - b = resultResta
        return resultResta;
    } else {
        for ( int i = 0; i <rowsA; i++){
            transform(a.matrix[i].begin(), a.matrix[i].end(), b.matrix[i].begin(), resultResta.matrix[i].begin(), minus<T>());
        }
        //a - b = resultResta
        return resultResta;
    }
    
}

/// @details Se realiza la multiplicacion de dos matrices
template <class T>
Matrix<T> OperacionesBasicas<T>::multiplicacion(Matrix<T> &a,Matrix<T> &b,int tipoDato,int complexType,int beginRandom){
    //Se inicializa la variable isOP en true para indicar que se esta realizando una operacion
    isOP = true;
    int rowsA, colsA, rowsB, colsB;
    a.getDims(&rowsA, &colsA);
    b.getDims(&rowsB, &colsB);

    //Se crea una matriz resultante de la multiplicacion
    Matrix<T> resultMult(rowsA, colsB, tipoDato, complexType, beginRandom);
    if (tipoDato == COMPLEX ){
        //Para multiplicar dos matrices, se utiliza un ciclo for anidado
        //Ya que la multiplicacion es el producto punto de las filas de la matriz A y las columnas de la matriz B
        for(int i = 0; i < rowsA; i++){
            for (int j = 0; j < colsB; j++){
                for (int k = 0; k < colsA; k++){
                    resultMult.matrixCompleja[i][j] += a.matrixCompleja[i][k] * b.matrixCompleja[k][j];
                }
            }
        }
        //a * b = resultMult
        return resultMult;
    } else {
        for(int i = 0; i < rowsA; i++){
            for (int j = 0; j < colsB; j++){
                for (int k = 0; k < colsA; k++){
                    resultMult.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
                }
            }
        }
        //a * b = resultMult
        return resultMult;
    }
    
}

#endif // OPERACIONES_CPP


