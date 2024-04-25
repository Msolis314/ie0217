#include <iostream>
using namespace std;

// Boilerplate for class template
template <class T>
class className {
    private:
        T var;
    public:
        T functionName(T arg);

        //function prototype
        void functionName();

};

//Function definition
template <class T>
void  className<T>::functionName() {
    //code
}

template <class T>
class Number {
    private:
        //Variable of type T
        T num;
    public:
        Number(T n): num(n) {} // constructor

        //Funcion miembro de la clase
        T getNum() {
            return num;
        }

        //Function prototype
        T getnum();
};

//Function definition
template <class T>
T Number<T>::getnum() {
    return num;
}
int main() {

    //create an object of class Number
    //Crear un objeto de la clase Number
    //Dando a T el tipo de dato int
    Number<int> numberInt(7);

    //create objecto with double type
    Number<double> numberDouble(7.7);

    cout << "int Number: " << numberInt.getNum() << endl;
    cout << "double Number: " << numberDouble.getNum() << endl;
    return 0;
}