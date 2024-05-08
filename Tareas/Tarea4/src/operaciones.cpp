
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
bool isOP;
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
Matrix<T> OperacionesBasicas<T>::suma(Matrix<T> &a, Matrix<T> &b,int tipoDato,int complexType,int beginRandom){
    isOP = true;
    int rowsA, colsA, rowsB, colsB;
    a.getDims(&rowsA, &colsA);
    b.getDims(&rowsB, &colsB);
    Matrix<T> resultSum(rowsA, colsA, tipoDato, complexType, beginRandom);
    for ( int i = 0; i <rowsA; i++){
        transform(a.matrix[i].begin(), a.matrix[i].end(), b.matrix[i].begin(), resultSum.matrix[i].begin(), plus<T>());
    }
    //a + b = resultSum
    return resultSum;
}

template <class T>
Matrix<T> OperacionesBasicas<T>::resta(Matrix<T> &a, Matrix<T> &b,int tipoDato,int complexType,int beginRandom){
    isOP = true;
    int rowsA, colsA, rowsB, colsB;
    a.getDims(&rowsA, &colsA);
    b.getDims(&rowsB, &colsB);
    Matrix<T> resultResta(rowsA, colsA, tipoDato, complexType, beginRandom);
    for ( int i = 0; i <rowsA; i++){
        transform(a.matrix[i].begin(), a.matrix[i].end(), b.matrix[i].begin(), resultResta.matrix[i].begin(), minus<T>());
    }
    //a - b = resultResta
    return resultResta;
}


template <class T>
Matrix<T> OperacionesBasicas<T>::multiplicacion(Matrix<T> &a,Matrix<T> &b,int tipoDato,int complexType,int beginRandom){
    isOP = true;
    int rowsA, colsA, rowsB, colsB;
    a.getDims(&rowsA, &colsA);
    b.getDims(&rowsB, &colsB);
    Matrix<T> resultMult(rowsA, colsB, tipoDato, complexType, beginRandom);
    for(int i = 0;i < rowsA; i++){
        for (int j = 0; j < colsB; j++){
            for (int k = 0; k < colsA; k++){
                resultMult.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
            }
        }
    }
    //a * b = resultMult
    return resultMult;
}

#endif // OPERACIONES_CPP


