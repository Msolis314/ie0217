#include <iostream>
using namespace std;
class MyClass {
    private:
        int member1;
};

class Distance {
    private:
        int meter;
        //friend function
        friend int addFive(Distance);
    public:
        Distance(): meter(0){}
};


int addFive(Distance d){
    //accessing private members from friend function
    d.meter += 5;
    return d.meter;
}

//Ejemplo 2 clases amigos

class ClassB;

class ClassA {
    public:
    // Contructor to initialize numA to 12 
        ClassA() : numA(12) {}
    private:
        int numA;
        // friend function declaration
        friend int add(ClassA, ClassB);

        //friend class declaration
        friend class ClassB; //ahora puede acceder a numA
};

class ClassB {
    public:
    // Contructor to initialize numB to 1
        ClassB() : numB(1) {}

        int add2(){
            ClassA objectA;
            return objectA.numA + numB;
        }
    private:
        int numB;
        // friend function declaration
        friend int add(ClassA, ClassB);
};

// access members of both classes
int add(ClassA objectA, ClassB objectB) {
    return (objectA.numA + objectB.numB); // Esta funcion puede acceder a los atributos privados numA y numB
}


int main(){

    MyClass obj;

    //Error: Cannot access private member
    //obj.member1 = 5;

    //accessing private member from friend function
    Distance D;
    cout << "Distance: " << addFive(D) << endl;

    //Ejemplo 2 clases amigos
    ClassA objectA;
    ClassB objectB;
    cout << "Sum: " << add(objectA, objectB) << endl;
    return 0;
}