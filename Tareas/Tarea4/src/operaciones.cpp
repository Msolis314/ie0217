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

template <class T>
bool OperacionesBasicas<T>:: validarSumaResta(Matrix<T> &a, Matrix<T> &b){
    int rowsA, colsA, rowsB, colsB;
    a.getDims(&rowsA, &colsA);
    b.getDims(&rowsB, &colsB);
    try {
        if (rowsA != rowsB || colsA != colsB){
            throw invalid_argument("Las matrices no tienen las mismas dimensiones");
        }
        return true;
    }
    catch (invalid_argument &e){
        cout << e.what() << endl;
        return false;
    }
}

template <class T>
bool OperacionesBasicas<T>:: validarMultiplicacion(Matrix<T> &a, Matrix<T> &b){
    int rowsA, colsA, rowsB, colsB;
    a.getDims(&rowsA, &colsA);
    b.getDims(&rowsB, &colsB);
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
Matrix<T> OperacionesBasicas<T>::suma(Matrix<T> &a, Matrix<T> &b){
    int rowsA, colsA, rowsB, colsB;
    a.getDims(&rowsA, &colsA);
    b.getDims(&rowsB, &colsB);
    Matrix<T> resultSum(rowsA, colsA);
    for ( int i = 0; i <rowsA; i++){
        for (int j = 0; j < colsA; j++){
            resultSum.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
        }
    }
    //a + b = resultSum
    return resultSum;
}

template <class T>
Matrix<T> OperacionesBasicas<T>::resta(Matrix<T> &a, Matrix<T> &b){
    int rowsA, colsA, rowsB, colsB;
    a.getDims(&rowsA, &colsA);
    b.getDims(&rowsB, &colsB);
    Matrix<T> resultResta(rowsA, colsA);
    for ( int i = 0; i <rowsA; i++){
        for (int j = 0; j < colsA; j++){
            resultResta.matrix[i][j] = a.matrix[i][j] - b.matrix[i][j];
        }
    }
    //a - b = resultResta
    return resultResta;
}


