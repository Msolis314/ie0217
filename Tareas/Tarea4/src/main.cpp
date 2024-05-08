#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include <ctime>
#include "matrix.hpp"
#include "operaciones.hpp"
#include "menuFuncs.hpp"
#include "tools.hpp" 

bool isOP;
using namespace std;
void askParams(menu &m);
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

    while(cout << "Desea llenar las matrices con numeros random?\n 1) Si \n 2) No\n " && !(cin >> m.beginRandom) || m.beginRandom < 1 || m.beginRandom > 2){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Intente de nuevo." << endl;
    }

    //Se pide la operacion a realizar
    while(cout << "Ingrese la operacion a realizar:\n 1) Suma \n 2) Resta \n 3) Multiplicacion\n " && !(cin >> m.operacion) || m.operacion < 1 || m.operacion > 3){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada invalida. Intente de nuevo." << endl;
    }
}

int main(){
    isOP = false;
    srand(static_cast<unsigned int>(time(0)));
    Matrix<int> a;
    Matrix<int> b;
    Matrix<float> a_float;
    Matrix<float> b_float;
    Matrix<double> a_double;
    Matrix<double> b_double;
    menu m;
    askParams(m);
    
    int typeData = m.tipoDato;
    int complexType = m.complexType;
    int beginRandom = m.beginRandom;
    switch (typeData){
        case INT:
            a = Matrix<int>(m.rowsA, m.colsA,typeData,complexType,beginRandom);
            b = Matrix<int>(m.rowsB, m.colsB,typeData,complexType,beginRandom);
            menuDisplay(m, a, b);
            break;
        case FLOAT:
            a_float = Matrix<float>(m.rowsA, m.colsA,typeData,complexType,beginRandom);
            b_float = Matrix<float>(m.rowsB, m.colsB,typeData,complexType,beginRandom);
            menuDisplay(m, a_float, b_float);
            break;
        case DOUBLE:
            a_double = Matrix<double>(m.rowsA, m.colsA,typeData,complexType,beginRandom);
            b_double = Matrix<double>(m.rowsB, m.colsB,typeData,complexType,beginRandom);
            menuDisplay(m, a_double, b_double);
            break;
        case COMPLEX:
            a = Matrix<int>(m.rowsA, m.colsA,typeData,complexType,beginRandom);
            b = Matrix<int>(m.rowsB, m.colsB,typeData,complexType,beginRandom);
            menuDisplay(m, a, b);
            break;
        default:
            break;
    }
   
    return 0;
}

#include "matrix.cpp"
#include "operaciones.cpp"
#include "menuFuncs.cpp"
#include "tools.cpp"
#include "checkInput.cpp"