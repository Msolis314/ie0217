#include <iostream>
#include <string>
using namespace std;

//Global variable:
int g;

int main(){
    //Local variable:
    int a, b;
    int c;

    //initialization
    a = 10;
    b = 20;
    c = a + b;

    g = a + b;

    cout << g << endl;

    cout << c;

    //Entradas del usuario 
    int x; //declaring a variable
    cout << "Type a number:"; // Type a number and hit enter
    cin >> x; // Get user input from the keyboard
    cout << "Your number is: " << x; // Display the value

    //Declaracion string

    string str = "Hello";

    //declare and initialize an array
    int x[6]= {19, 10, 8, 17, 9, 15};

    int test[2][3]= {{2,4,5},{9,0,19}};
    return 0;
}