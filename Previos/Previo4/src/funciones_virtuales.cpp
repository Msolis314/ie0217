#include <iostream>
using namespace std;

class Base {
    public:
    //Yo quiero que la funcion se sobre escriba en la clase derivada
        virtual void print() {
            cout << "Base function" << endl;
        }
};

class Derived : public Base {
    public:
    //Yo tengo que si o si sobreescribir la funcionS
        void print() {
            cout << "Derived function" << endl;
        }
};

int main(){
    Derived derived1;

    //pointer of Base type that points to derived1
    Base *base1 = &derived1;

    //calls member function of the derived class
    base1->print();
    return 0;
}