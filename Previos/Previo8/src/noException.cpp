#include <iostream>
#include <stdexcept>
using namespace std;

int main () {
    int numerador, denominador, resultado;
    cout << "Ingrese numerador: ";
    cin >> numerador;

    cout << "Ingrese denominador: ";
    cin >> denominador;
    
    //Mala practica
    //No hay manejo de excepciones
    resultado = numerador / denominador;
    cout << "El resultado es: " << resultado << endl;

    //Buena practica
    try {
        //Se lanza una excepcion si el denominador es 0
        if (denominador == 0){
            throw runtime_error("Error: el denominador no puede ser cero.");

        }
        resultado = numerador / denominador;
        cout << "El resultado es: " << resultado << endl;
    } catch (const exception& e) {
        //const exception& e en una forma
        // de acceder a la excepcion
        // ya definida en la libreria estandar de C++
        cerr << e.what() << endl;
    }

    return 0;

}