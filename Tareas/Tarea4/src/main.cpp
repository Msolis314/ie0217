#include <iostream>
#include <string>
#include <vector>
#include "matrix.hpp"
#include "operaciones.hpp"
#include "menuFuncs.hpp"
#include "tools.hpp"

using namespace std;

int main(){
    menu menu;
    int opcion;
    askParams(menu);

    

    Matrix<int> a;
    Matrix<int> b;
    Matrix<float> a_float;
    Matrix<float> b_float;
    Matrix<double> a_double;
    Matrix<double> b_double;
    int typeData = menu.tipoDato;
    int complexType = menu.complexType;
    int beginRandom = menu.beginRandom;

    switch (menu.tipoDato) {
        case INT:
            a = Matrix<int>(menu.rowsA, menu.colsA, typeData, complexType, beginRandom);
            b = Matrix<int>(menu.rowsB, menu.colsB, typeData, complexType, beginRandom);
            menuDisplay<int>(menu, a, b);
            break;
        case FLOAT:
            a_float = Matrix<float>(menu.rowsA, menu.colsA, typeData, complexType, beginRandom);
            b_float = Matrix<float>(menu.rowsB, menu.colsB, typeData, complexType, beginRandom);
            menuDisplay<float>(menu, a_float, b_float);
            break;
        case DOUBLE:
            a_double = Matrix<double>(menu.rowsA, menu.colsA, typeData, complexType, beginRandom);
            b_double = Matrix<double>(menu.rowsB, menu.colsB, typeData, complexType, beginRandom);
            menuDisplay<double>(menu, a_double, b_double);
            break;
        case COMPLEX:
            if (menu.complexType == INT)
            {
                a = Matrix<int>(menu.rowsA, menu.colsA, typeData, complexType, beginRandom);
                b = Matrix<int>(menu.rowsB, menu.colsB, typeData, complexType, beginRandom);
                menuDisplay<int>(menu, a, b);
            }
            else if (menu.complexType == FLOAT)
            {
                a_float = Matrix<float>(menu.rowsA, menu.colsA, typeData, complexType, beginRandom);
                b_float = Matrix<float>(menu.rowsB, menu.colsB, typeData, complexType, beginRandom);
                menuDisplay<float>(menu, a_float, b_float);
            }
            else if (menu.complexType == DOUBLE)
            {
                a_double = Matrix<double>(menu.rowsA, menu.colsA, typeData, complexType, beginRandom);
                b_double = Matrix<double>(menu.rowsB, menu.colsB, typeData, complexType, beginRandom);
                menuDisplay<double>(menu, a_double, b_double);
            }
            break;
        default:
            break;
    }
   
    
    
    return 0;
}

#include "checkInput.cpp"
#include "operaciones.cpp"
#include "menuFuncs.cpp"
#include "matrix.cpp"

