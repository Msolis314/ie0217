#include <iostream>
using namespace std;

struct Distance{
    int feet;
    float inch;
};

int main(){
    Distance *ptr, d;

    ptr = &d;

    cout << "Enter feet: ";
    cin >> (*ptr).feet; // d.feet
    cout << "Enter inch: ";
    cin >> (*ptr).inch; // d.inch

    cout << "Displaying information." << endl;
    cout << "Distance = " << (*ptr).feet << " feet " << (*ptr).inch << " inches";

    //Operador flechita 

    cout << "\nEnter feet: ";
    cin >> ptr->feet; // d.feet
    cout << "Enter inch: ";
    cin >> ptr->inch; // d.inch

    cout << "Displaying information." << endl;
    cout << "Distance = " << ptr->feet << " feet " << ptr->inch << " inches";

    //Punteros y arreglos

    float arr[3];

    //Declare pointer variable
    float *ptr1;

    cout << "\nDisplaying address using arrays: " << endl;

    //use for loop to print addresses of all elements of the array
    for (int i =0; i <3;++i){
        cout << "&arr[" << i << "] =" << &arr[i] << endl;
    }

    //ptr1 = &arr[0]
    ptr1 = arr;

    cout << "\nDisplaying address using pointers: " << endl;

    //use for loop to print addresses of all elements of the array
    //using pointer notation
    for (int i = 0;i < 3; ++i){
        cout << "ptr1 +" << i << " = " << ptr1 + i << endl;
    }
    return 0;
}