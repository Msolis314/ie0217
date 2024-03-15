#include <iostream>
using namespace std;
int main(){
    
    int var = 5;
    //declare pointer variable
    int *pointvar;

    //store address of var
    pointvar = &var;

    //print pointed var 
    cout <<"*pointvar: " << *pointvar << endl;

    cout << "Changing value of var to 7: " << endl;
    var = 7;

    //print  var
    cout << "var: " << var << endl;

    //print pointed var 
    cout <<"*pointvar: " << *pointvar << endl;

    //change value of var to 16
    cout << "Changing value of var to 16: " << endl; 
    *pointvar = 16;

    // print var
    cout << "var: " << var << endl;

    //print pointed var
    cout <<"*pointvar: " << *pointvar << endl;
    
    //Errores comunes 

    /*int var, *varPoint;
    Wrong: varPoint = var;
    varPoint is an address, var is not 
    Correct: varPoint = &var;
    */

   /*
   Wrong: *varPoint = &var;
   &var is an address
   *varPoint is the value stored in &var
    Correct: varPoint = &var;
   */
    return 0;

}