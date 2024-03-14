#include <iostream>
using namespace std;
//Comentario de una linea

/**
 * Comentario de multiples lineas
 * Para doxygen
*/

int main(){
    cout << "Hello World!\n";

    int var1 = 0;
    int var2;

    var2 = (var1 == 0) ? 15 : 27; //Operador ternario
    cout << "var2: \n" << var2 << "";

    //switch
    var1 = 2;
    
    switch (var1){
        case 1:
            std::cout << "Case 1!\n";
            break;
        case 2:
        case 3:
            std::cout << "Case Final!\n";
            break;
        default:
            break;
    }
    return 0;
}