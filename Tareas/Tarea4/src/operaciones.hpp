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

template <class T>
class OperacionesBasicas {
    public:
        bool validarSumaResta(Matrix<T> &a, Matrix<T> &b);
        bool validarMultiplicacion(Matrix<T> &a, Matrix<T> &b);
        Matrix<T> suma(Matrix<T> &a, Matrix<T> &b);
        Matrix<T> resta(Matrix<T> &a, Matrix<T> &b);
        Matrix<T> multiplicacion(Matrix<T> &a, Matrix<T> &b);
        
};
#endif // OPERACIONES_HPP