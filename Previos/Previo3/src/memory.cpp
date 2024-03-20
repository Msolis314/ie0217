#include <iostream>
using namespace std;
int main(){
    //declare variables 
    int var1 = 3 , var2 = 24 , var3 = 17;

    //print address of var 1 
    cout << "Address of var1: " << &var1 << endl;

    //print address of var 2
    cout << "Address of var2: " << &var2 << endl;

    //print address of var 3
    cout << "Address of var3: " << &var3 << endl;
    

    //Pointers 

    int var = 5;
    //declare pointer variable
    int *pointvar;
    //store address of var
    pointvar = &var;
    //print var
    cout << "var: " << var << endl;
    //print address of var
    cout << "Address of var(&var): " << &var << endl;
    //print pointer pointvar
    cout << "pointvar: " << pointvar << endl;
    //print the content of the address pointvar
    cout << "Content of the address pointvar(*pointvar): " << *pointvar << endl;    
    return 0;

}