#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include "operaciones.hpp"
#include "matrix.hpp"
#include "checkInput.hpp"
#include "menuFuncs.hpp"

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


}


