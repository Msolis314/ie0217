#include <iostream>
using namespace std;
class Animal{
    public:
        void eat(){
            std::cout << "I can eat" << std::endl;
        }
        void sleep(){
            std::cout << "I can sleep" << std::endl;
        }
    //eat() function
    // sleep() function
};

class Dog : public Animal{
    //bark() function
    public:
        void bark(){
            std::cout << "I can bark" << std::endl;
        }
};

//Ejemplo sobreescritura de funciones

class Base{
    public:
        void print(){
            cout << "Base function" << endl;
        }
};

class Derived : public Base{
    //Queda la ultima definicion de la funcion print()
    public:
        void print(){
            cout << "Derived function" << endl;
        }
};

int main(){
    Dog dog1;

    //calling members of the base class
    dog1.eat();
    dog1.sleep();

    //calling member of the derived class
    dog1.bark();

    //Ejemplo sobreescritura de funciones

    Derived derived1, derived2;
    derived1.print();

    //access print() function of the base class
    derived2.Base::print(); // Objeto.Clase_Buscada::Metodo()
    return 0;
}