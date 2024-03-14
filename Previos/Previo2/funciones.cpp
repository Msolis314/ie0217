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

//declaring add function
int add(int a, int b){
    return a + b;
}

//function prototype
int add2(int, int);

//same name different arguments
int test() {}
int test(int a) {}
float test(float a) {}
int test(int a, int b) {}

//function with float type parameter
float absolute(float var){
    if (var < 0.0)
        return -var;
    
    return var;
}

//function with int type parameter
int absolute(int var){
    if (var < 0)
        return -var;
    
    return var;
}

//function with 2 parameters
void display(int var1,double var2){
    cout << "Integer number: " << var1;
    cout << " and double number: " << var2 << endl;
}

//function with double type single parameter
void display(double var){
    cout << "Double number: " << var << endl;
}

//function with int type single parameter
void display(int var){
    cout << "Integer number: " << var << endl;
}

//Ejemplos valores por defecto

//Invalid
//void add(int a, int b = 3, int c , int d);

//Invalid
//void add(int a, int b = 3, int c , int d = 4);

//Valid
//void add(int a, int c, int b = 3, int d = 4);

int main(int argc, char* argv[]){
    int num1 = 5;
    double num2 = 5.5;
    int sum;

    //calling the function
    displayNum(num1, num2);

    //Argumentos de la funcion main 

    cout << "argc:  " << argc << endl;
    cout << "argv[0]: " << argv[0] << endl;
    cout << "argv[1]: " << argv[1] << endl;
    cout << "argv[2]: " << argv[2] << endl;
    cout << "argv[3]: " << argv[3] << endl;

    //Ejemplo presentacion argumentos de main 

    cout << "Numero de argumentos:" << argc << endl;
    cout << "Nombre del programa: " << argv[0] << endl;

    //imprimir argumentos adicionales
    if (argc > 1){
        cout << "Argumentos adicionales: " << endl;
        for (int i = 1; i < argc; ++i){
            cout << "argv[" << i << "]: " << argv[i] << endl;
        }
    }

    /*calling the function and storing
    the returned value in the variable sum*/
    sum = add(100,78);

    cout << "100 + 78 = " << sum << endl;

    /*calling the function and storing
    the returned value in the variable sum*/
    sum = add2(100,78);

    cout << "100 + 78 = " << sum << endl;

    //call function with int type parameter
    cout <<"Absolute value of -5: " << absolute(-5) << endl;

    //call function with float type parameter
    cout <<"Absolute value of -5.5: " << absolute(-5.5f) << endl;

    int a = 5;
    double b = 5.5;
    //call function with int type parameter
    display(a);

    //call function with double type parameter
    display(b);

    //call function with 2 parameters
    display(a, b);


    return 0;
}

// function definition
int add2(int a, int b){
    return a + b;
}