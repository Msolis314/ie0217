#include <iostream>
using namespace std;

//function definition to swap values
//Reference parameters without pointers
void swap (int &n1, int &n2){
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}

//With pointers
void swap2(int *n1, int *n2){
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int main(){
    //initialize variables
    int a =1 , b =2;
    cout << "Before swapping: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    //call function to swap numbers
    swap(a,b);

    cout << "\nAfter swapping: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    //with pointers
    int x = 3, y = 4;
    cout << "Before swapping: " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    //call function to swap numbers with pointers
    swap2(&x,&y);

    cout << "\nAfter swapping: " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}