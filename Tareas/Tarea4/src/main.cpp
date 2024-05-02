#include <iostream>
#include <string>
#include <vector>
#include "matrix.hpp"

using namespace std;

int main(){
    int rows, cols;
    cout << "Ingrese el numero de filas de la matriz: ";
    cin >> rows;
    cout << "Ingrese el numero de columnas de la matriz: ";
    cin >> cols;
    Matrix<int> matrix(rows, cols);
    matrix.printMatrix();
    return 0;
}

#include "matrix.cpp"