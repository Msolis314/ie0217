#include <iostream>
#include <string>
#include <vector>
#include "matrix.hpp"

using namespace std;

int main(){
    int rows, cols;
    while (cout << "Ingrese el numero de filas: " && !(cin >> rows)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Intente de nuevo." << endl;
    }
    while (cout << "Ingrese el numero de columnas: " && !(cin >> cols)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Intente de nuevo." << endl;
    }
    try {
        Matrix<int> matrix(rows, cols);
        matrix.printMatrix();
    }
    catch (invalid_argument &e){
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}

#include "matrix.cpp"