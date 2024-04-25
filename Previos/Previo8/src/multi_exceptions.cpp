#include <iostream>
using namespace std;

//Sino se conoce el tipo de excepcion
/*
try {
    //code
}
catch(...){
    //code
}
*/

// Tambien es util con un try con multiples catch
/*
try {
    //code
}
catch (exception1){
    //code
}
catch (exception2){
    //code
}
catch(...){
    //code
}
*/

int main(){
    double numerator, denominator,arr[4]= {0.0,0.0,0.0,0.0},divide;
    int index;

    cout << "Enter array index: ";
    cin >> index;

    try {
        //throw exception if index is out of bounds
        if (index >= 4 )
            throw "Error:Array out of bounds";
        
        //not executed if array is out of bounds
        cout << "Enter numerator: ";
        cin >> numerator;

        cout << "Enter denominator: ";
        cin >> denominator;

        //throw exception if denominator is 0
        if (denominator == 0)
            throw 0;
        
        //not executed if denominator is 0
        arr[index] = numerator / denominator;
        cout << arr[index] << endl;
    }

    //catch "Array out of bounds" exception
    //Este catch si el argumento de throw es un string
    catch (const char* msg){
        cout << msg << endl;
    }

    //catch "Divide by 0" exception
    //Este catch se activa si el argumento de throw es un int
    catch (int num ) {
        cout << "Error: Cannot divide by " << num << endl;
    }

    //catch any other exception
    //Este es como el default pero para excepciones
    catch(...){
        cout << "Unexpected exception!" << endl;

    }
    return 0;
}