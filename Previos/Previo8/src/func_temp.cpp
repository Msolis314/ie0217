#include <iostream>
using namespace std;

template <typename T>
//typename es una palabra clave que se usa para declarar un tipo de dato generico

T functionName(T parameter1, T parameter2) {
    //code
}
//T es el argumento de tipo
//Se utiliza un unico tipo de dato
/*
Cuando se llama a la funcion
con un tipo de dato especifico
el compilador cambia T por el tipo de dato
*/

template <typename T>
T add(T num1, T num2) {
    return num1 + num2;
}

int main(){
    int result1;
    double result2;

    //calling function with int parameters
    /*
    int add(int num1, int num2) {
        return num1 + num2;
    }
    */
    result1 = add<int>(5, 4);
    cout<< "5 + 4 = " << result1 << endl;

    //calling function with double parameters
    /*
    double add(double num1, double num2) {
        return num1 + num2;
    }
    */
    result2 = add<double>(2.2, 3.3);
    cout << "2.2 + 3.3 = "<< result2 << endl;

    return 0;
}