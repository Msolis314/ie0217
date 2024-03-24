#include <iostream>
using namespace std;

//Herencia multinivel

class A {
    public:
        void display(){
            cout << "Base class content." << endl;
        }
};

class B: public A {};
class C: public B {};

//Herencia multiple

class Mammal{
    public:
        Mammal(){
            cout << "Mammals can give direct birth" << endl;}
        
};
class WingedAnimal{
    public:
        WingedAnimal(){
            cout << "Winged animal can flap" << endl;
        }
};
//Herencia Jerarquica
class Animal {
    public:
        void info(){cout << "I am an animal" << endl;}

};
class Dog: public Animal{
    public:
        void bark(){cout << "I can Dog.Woof woof" << endl;}
};
class Cat: public Animal{
    public:
        void meow(){cout << "I can Cat.Meow meow" << endl;}
};

class Bat: public Mammal, public WingedAnimal{};
int main(){
    //Herencia multinivel
    C obj;
    obj.display();

    //Herencia multiple
    Bat b1;

    //Herencia Jerarquica

    //Create an object of Dog class
    class Dog dog1;
    cout << "Dog class"<< endl;
    dog1.info();
    dog1.bark();

    //Create an object of Cat class
    class Cat cat1;
    cout << "Cat class"<< endl;
    cat1.info(); //Parent class function
    cat1.meow(); 

    return 0;
}