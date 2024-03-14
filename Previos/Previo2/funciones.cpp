#include <iostream>
using namespace std;
// function declaration
void greet(){
    cout << "Hello World\n";
}

//display a number 
void displayNum(int n1, float n2) {
    cout << "The int number is: "<< n1 << endl;
    cout << "The double number is: "<< n2 << endl;

}

int main(int argc, char* argv[]){
    int num1 = 5;
    double num2 = 5.5;

    //calling the function
    displayNum(num1, num2);

    //Argumentos de la funcion main 

    cout << "argc:  " << argc << endl;
    cout << "argv[0]: " << argv[0] << endl;
    cout << "argv[1]: " << argv[1] << endl;
    cout << "argv[2]: " << argv[2] << endl;
    cout << "argv[3]: " << argv[3] << endl;


    return 0;
}