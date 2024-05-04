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
using namespace std;

template <class T>
class Matrix{
    private:
        vector<vector<T>> matrix;
        int rows;
        int cols;
        friend class OperacionesBasicas<T>;
    public:
        Matrix(int rows, int cols);
        bool setDimensiones(int rows, int cols);
        void llenarMatriz();
        void printMatrix();
        void getDims(int *rows, int *cols);
    ~Matrix();

};

#endif // MATRIX_HPP