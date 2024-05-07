#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
#include <random>
#include "matrix.hpp"
#include "checkInput.hpp"
#include "menuFuncs.hpp"
#include "operaciones.hpp"
using namespace std;

void askParams(menu &m){

    //Se pide el numero de filas de A
    //Si el cin falla, se limpia el buffer y se pide de nuevo
    while(cout << "Ingrese el numero de filas en la matriz A: " && !(cin >> m.rowsA)){
        cin.clear();
        //Se limpia el buffer
        //numeric_limits<streamsize>::max() es el maximo numero de 
        //bytes en el stream
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //Se le indica al usuario que la entrada es invalida
        cout << "Entrada invalida. Intente de nuevo." << endl;
    }

    //Se pide el numero de columnas de A
    //Se hace lo mismo que en el caso anterior
    //Para verificar que la entrada sea valida
    while(cout << "Ingrese el numero de columnas en la matriz A: " && !(cin >> m.colsA)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Intente de nuevo." << endl;
    }

    //Se pide el numero de filas de B
    while(cout << "Ingrese el numero de filas en la matriz B: " && !(cin >> m.rowsB)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Intente de nuevo." << endl;
    }

    //Se pide el numero de columnas de B
    while(cout << "Ingrese el numero de columnas en la matriz B: " && !(cin >> m.colsB)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Intente de nuevo." << endl;
    }

    //Se pide el tipo de dato de las matrices
    while(cout << "Ingrese el tipo de dato de las matrices:\n 1) Int \n 2) Float \n 3) Double \n 4) Complex\n " && !(cin >> m.tipoDato) || m.tipoDato < 1 || m.tipoDato > 4){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Intente de nuevo." << endl;
    }

    if (m.tipoDato == COMPLEX){
        while(cout << "Ingrese el tipo de dato complejo de las matrices:\n 1) Int \n 2) Float \n 3) Double\n " && !(cin >> m.complexType) || m.complexType < 1 || m.complexType > 3){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Intente de nuevo." << endl;
        }
    }

    //Se pide la operacion a realizar
    while(cout << "Ingrese la operacion a realizar:\n 1) Suma \n 2) Resta \n 3) Multiplicacion\n " && !(cin >> m.operacion) || m.operacion < 1 || m.operacion > 3){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Intente de nuevo." << endl;
    }

    //Se pide al usuario si quiere llenar las matrices con numeros random
    while(cout << "Desea llenar las matrices con numeros random?\n 1) Si \n 2) No\n " && !(cin >> m.beginRandom) || m.beginRandom < 1 || m.beginRandom > 2){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Intente de nuevo." << endl;
    }


}


template <typename T>
T randomNum(int type){
    //Para generar numeros random
    //Se usa la libreria random
    //Se usa un random_device para obtener un seed
    random_device rd;

    //Se usa un motor de numeros random
    //Se le pasa el seed
    default_random_engine gen(rd());
    //Se usa una distribucion uniforme
    //Se le pasa el tipo de dato
    uniform_real_distribution<T> dist(1, 100);

    //Se regresa un numero random
    return dist(gen);
}

template <typename T>
void generarRandomNumbers(menu &m, Matrix<T> &a, Matrix<T> &b){
    while (cout << "Cual matriz desea llenar con numeros random?\n 1) Matriz A \n 2) Matriz B\n 3) A y B\n " && !(cin >> m.whichMatrix) || m.whichMatrix < 1 || m.whichMatrix > 3){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Intente de nuevo." << endl;
    }

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
template <typename T>
void printMatrices(menu &m, Matrix<T> &a, Matrix<T> &b){
    cout << "Matriz A: " << endl;
    a.printMatrix();
    cout << "Matriz B: " << endl;
    b.printMatrix();
}

template <typename T>
void doOperation(menu &m, Matrix<T> &a, Matrix<T> &b){

    switch (m.operacion)
    {
    case SUMA:
        cout << "A + B = \n";
        (a + b).printMatrix();
        break;
    case RESTA:
        cout << "A - B = \n";
        (a - b).printMatrix();
        break;
    case MULTIPLICACION:
        cout << "A * B = \n";
        (a * b).printMatrix();
        break;
    default:
        break;
    }
}

template <typename T>
void menuDisplay(menu &m, Matrix<T> &a, Matrix<T> &b){
    switch (m.input)
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
        cout << "Saliendo del programa" << endl;
        break;
    default:
        break;
    }
}
