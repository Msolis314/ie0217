/*! @file menuFuncs.cpp
 @brief Implementacion de las funciones del menu
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

#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include "operaciones.hpp"
#include "matrix.hpp"
#include "checkInput.hpp"
#include "menuFuncs.hpp"

using namespace std;

/// @details Funcion que da la interfaz al usuario para generar numeros random en las matrices
template<class T>
void generarRandomNumbers(menu &m, Matrix<T> &a, Matrix<T> &b){
    //Se le pide al usuario que matriz desea llenar con numeros random
    while (cout << "Cual matriz desea llenar con numeros random?\n 1) Matriz A \n 2) Matriz B\n 3) A y B\n " && !(cin >> m.whichMatrix) || m.whichMatrix < 1 || m.whichMatrix > 3){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Intente de nuevo." << endl;
    }
    //Se llena la matriz seleccionada con numeros random
    //usando el metodo fillMatrixRandom
    switch (m.whichMatrix)
    {
    case A:
        a.fillMatrixRandom();
        break;
    case B:
        b.fillMatrixRandom();
        break;
    case BOTH:
        a.fillMatrixRandom();
        b.fillMatrixRandom();
        break;
    default:
        break;
    }
}

/// @details Funcion que imprime las matrices
template <class T>
void printMatrices(menu &m, Matrix<T> &a, Matrix<T> &b){
    cout << "Matriz A: " << endl;
    a.printMatrix();
    cout << "Matriz B: " << endl;
    b.printMatrix();
}

/// @details Funcion que realiza la operacion seleccionada por el usuario
template <class T>
void doOperation(menu &m, Matrix<T> &a, Matrix<T> &b){
    OperacionesBasicas<T> operaciones;
    isOP = true;
    switch (m.operacion)
    {
    case SUMA:
        cout << "A + B = \n";
        if (operaciones.validarSumaResta(a, b)) {
            //Se imprime la matriz resultante de la suma
            (a + b).printMatrix();
            //Se setea la variable isOP en false para indicar que no se esta realizando una operacion por el momento
            isOP = false;
        } else {
            cout << "No se puede realizar la suma" << endl;
            return;
        }

        break;
    case RESTA:
        cout << "A - B = \n";
        if (operaciones.validarSumaResta(a, b)) {
            //Se imprime la matriz resultante de la resta
            (a - b).printMatrix();
            //Se setea la variable isOP en false para indicar que no se esta realizando una operacion por el momento
            isOP = false;
        } else {
            cout << "No se puede realizar la resta" << endl;
            return;
        }
        break;
    case MULTIPLICACION:
        cout << "A * B = \n";
        if (operaciones.validarMultiplicacion(a, b)){
            //Se imprime la matriz resultante de la multiplicacion
            (a * b).printMatrix();
            //Se setea la variable isOP en false para indicar que no se esta realizando una operacion por el momento
            isOP = false;
        } else {
            cout << "No se puede realizar la multiplicacion" << endl;
            return;
        }
        break;
    default:
        break;
    }
}

/// @details Funcion que muestra el menu de opciones
template <typename T>
void menuDisplay(menu &m, Matrix<T> &a, Matrix<T> &b){
    int option;
    do {
        cout << "Menu de opciones: \n";
        cout << "1) Generar numeros random\n";
        cout << "2) Imprimir matrices\n";
        cout << "3) Realizar operacion\n";
        cout << "4) Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> option;
        switch (option)
        {
        case GENERATE_RANDOM_NUMBERS:
            generarRandomNumbers(m, a, b);
            break;
        case PRINT_MATRICES:
            printMatrices(m, a, b);
            break;
        case DO_OPERATION:
            doOperation(m, a, b);
            break;
        case EXIT:
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
            break;
        }
    } while (option != 4);
}