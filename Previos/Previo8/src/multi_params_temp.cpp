#include <iostream>
using namespace std;

//Boilerplate function template multiple parameters
template <typename T, typename U>
T multiply(T a, U b) {
    return a * b;
}

//Boilerplate class template multiple parameters
template <class T, class U, class V = int>
//El usuario debe especificar los tipos de datos
//T,U
//V es un parametro por defecto
//Puede ser especificado por el usuario o no
class ClassName {
    private:
        T member1;
        U member2;
        V member3;
    public:
        //CODE
};

template <class T, class U, class V = char>
class ClassTemplate {
    private:
    //T,U,V son los parametros de tipo generico
        T var1;
        U var2;
        V var3;
    public:
        //Constructor
        ClassTemplate(T v1, U v2, V v3): var1(v1), var2(v2), var3(v3) {}

        void printVar() {
            cout << "var1 = " << var1 << endl;
            cout << "var2 = " << var2 << endl;
            cout << "var3 = " << var3 << endl;
        }
};

int main(){
    //Ejemplo de uso de la funcion template con multiples parametros
    int a = 3;
    double b = 4.5;
    int result = multiply<int,double>(a, b);
    cout << "Result: " << result << endl;

    //Ejemplo de uso de la clase template con multiples parametros
    
    //create object with int, double, char types
    //como char es un parametro por defecto
    //no es necesario especificarlo
    ClassTemplate<int, double> obj1(7, 7.7, 'c');
    cout << "obj1 values: " << endl;
    obj1.printVar();

    //create object with double , char, bool types
    ClassTemplate<double, char, bool> obj2(8.8, 'a', false);
    cout << "\nobj2 values: " << endl;
    obj2.printVar();

    return 0;
}