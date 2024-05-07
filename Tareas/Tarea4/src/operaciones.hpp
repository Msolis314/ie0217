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
//#include "menuFuncs.hpp"

using namespace std;
template <class T>
class OperacionesBasicas {
    public:
        
        bool validarSumaResta(Matrix<T> &a, Matrix<T> &b) {
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
        
        };
        
        bool validarMultiplicacion(Matrix<T> &a, Matrix<T> &b){
            int rowsA, colsA, rowsB, colsB;
            a->getDims(&rowsA, &colsA);
            b->getDims(&rowsB, &colsB);
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
        };
        
        Matrix<T> suma(Matrix<T> &a, Matrix<T> &b){
            int rowsA, colsA, rowsB, colsB;
            a.getDims(&rowsA, &colsA);
            b.getDims(&rowsB, &colsB);
            Matrix<T> resultSum(rowsA, colsA);
            for ( int i = 0; i <rowsA; i++){
                transform(a.matrix[i].begin(), a.matrix[i].end(), b.matrix[i].begin(), resultSum.matrix[i].begin(), plus<T>());
            }
            //a + b = resultSum
            return resultSum;
        };
        
        Matrix<T> resta(Matrix<T> &a, Matrix<T> &b){
            int rowsA, colsA, rowsB, colsB;
            a.getDims(&rowsA, &colsA);
            b.getDims(&rowsB, &colsB);
            Matrix<T> resultResta(rowsA, colsA);
            for ( int i = 0; i <rowsA; i++){
                transform(a.matrix[i].begin(), a.matrix[i].end(), b.matrix[i].begin(), resultResta.matrix[i].begin(), minus<T>());
            }
            //a - b = resultResta
            return resultResta;
        };
        
        Matrix<T> multiplicacion(Matrix<T> &a, Matrix<T> &b){
            int rowsA, colsA, rowsB, colsB;
            a.getDims(&rowsA, &colsA);
            b.getDims(&rowsB, &colsB);
            Matrix<T> result(rowsA, colsB);
            for (int i = 0; i < rowsA; i++){
                for (int j = 0; j < colsB; j++){
                    for (int k = 0; k < colsA; k++){
                        result.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
                    }
                }
            }
            return result;
        };
        
};


#endif // OPERACIONES_HPP