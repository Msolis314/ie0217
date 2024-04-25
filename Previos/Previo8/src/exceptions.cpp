#include <iostream>
using namespace std;

/*
try {
    //code that may raise an exception
    throw argument;
}
catch (exception){
    //code to handle the exception
}*/

int main(){
    double numerator, denominator,divide;
    cout << "Enter numerator: ";
    cin >> numerator;

    cout << "Enter denominator: ";
    cin >> denominator;

    //El try se utiliza para 
    //chequear si hay una excepcion
    try {

        //throw an exception if denominator is 0 
        if (denominator == 0)
            //cuando se hace un throw
            //se va a la seccion catch
            throw 0;
        
        //not executed if denominator is 0
        divide = numerator / denominator;

        cout << numerator << " / " << denominator << " = " << divide << endl;
    }

    //Solo se activa si se dispara una excepcion
    //el argumento de catch es lo que se lanza en throw
    catch (int num_exception){
        //aqui se maneja la excepcion
        cout << "Error: Cannot divide by " << num_exception <<  endl;
    }

    

    return 0;
}