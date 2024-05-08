#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include "operaciones.hpp"
#include "matrix.hpp"
#include "checkInput.hpp"
#include "menuFuncs.hpp"

using namespace std;

template<class T>
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

template <class T>
void printMatrices(menu &m, Matrix<T> &a, Matrix<T> &b){
    cout << "Matriz A: " << endl;
    a.printMatrix();
    cout << "Matriz B: " << endl;
    b.printMatrix();
}


template <class T>
void doOperation(menu &m, Matrix<T> &a, Matrix<T> &b){
    OperacionesBasicas<T> operaciones;
    switch (m.operacion)
    {
    case SUMA:
        cout << "A + B = \n";
        if (operaciones.validarSumaResta(a, b)) {
            (a + b).printMatrix();}
        else {
            cout << "No se puede realizar la suma" << endl;
            return;
        }

        break;
    case RESTA:
        cout << "A - B = \n";
        if (operaciones.validarSumaResta(a, b)) {
            (a - b).printMatrix();}
        else {
            cout << "No se puede realizar la resta" << endl;
            return;
        }
        break;
    case MULTIPLICACION:
        cout << "A * B = \n";
        if (operaciones.validarMultiplicacion(a, b)){
            (a * b).printMatrix();}
        else {
            cout << "No se puede realizar la multiplicacion" << endl;
            return;
        }
        break;
    default:
        break;
    }
}

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