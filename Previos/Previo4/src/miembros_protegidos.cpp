#include <iostream>
#include <string>
using namespace std;

class Animal {
    private:
    //Por defecto son privados y no se pueden acceder por las clases que hereden de esta
        string color;
    protected:
    //Este si se va a poder acceder por las clases que hereden de esta
        string type;
    public:
    //Todos estos metodos pueden ser accedidos por las otras clases
        void run(){cout << "I can run -- BASE!" << endl;}
        void eat(){cout << "I can eat" << endl;}
        void sleep(){cout << "I can sleep" << endl;}
        void setColor(string clr) {color = clr;}
        string getColor() {return color;}

};

class Dog : public Animal {
    public:
        void run(){cout << "I can run -- DERIVED!" << endl;} //Sobreescritura de la funcion run()
        void setType(string tp){type = tp;}
        void displayInfo(string c){
            cout << "I am a" << type << endl;
            cout << "My color is "<< c << endl;
        }
        /*void setColor(string clr){color = clr;}*/
        void bark(){cout << "I can bark" << endl;}
};
//Ejemplo modos de acceso al realizar herencia

class Base{
    public:
        int x;
    protected:
        int y;
    private:
        int z;
};

class PublicDerived : public Base{
    //x is public
    //y is protected
    //z is not accessible from PublicDerived
};
class ProtectedDerived : protected Base{
    //x is protected
    //y is protected
    //z is not accessible from ProtectedDerived
};
class PrivateDerived : private Base{
    //x is private
    //y is private
    //z is not accessible from PrivateDerived
};
int main(){
    Dog dog1;
    dog1.run();
    dog1.eat();
    dog1.sleep();
    dog1.setColor("black");

    dog1.bark();
    dog1.setType("Doberman");
    //No se puede acceder a la variable color ya que es privada
    dog1.displayInfo(dog1.getColor());
    return 0;
}