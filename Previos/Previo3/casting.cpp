#include <iostream>
using namespace std;

int main(){
    //Working of implicit type-conversion
    //assigning an int value to num_int
    int num_int = 9;

    //declaring a double type variable
    double num_double;
    //implicit conversion
    //assigning an int value to a double variable

    num_double = num_int;

    cout << "num_int: " << num_int << endl;
    cout << "num_double: " << num_double << endl;

    //Working of explicit type-conversion
    //initializing a double variable
    double num_double2 = 3.56;
    cout << "num_double2: " << num_double2 << endl;

    //C-style conversion from double to int
    int num_int1= (int)num_double2;
    cout << "num_int1: " << num_int1 << endl;

    //function style conversion from double to int
    int num_int2 = int(num_double2);
    cout << "num_int2: " << num_int2 << endl;

    return 0;
}