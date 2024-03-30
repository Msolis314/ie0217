#include <iostream>
using namespace std;

class Animal{
    public:
        void setEdad(int age){
            edad = age;
        }
        int getEdad(){
            return edad;
        }
    private:
        int edad;
    protected:
        string nombre;

};

class Perro : public Animal {
    public:
        void setNombre(string n){
            nombre = n;
        }
        string getNombre(){
            return nombre;
        }
    
};

int main(){
    Perro miPerro;
    miPerro.setNombre("Toby");
    miPerro.setEdad(3);

    cout << "Mi perro se llama " << miPerro.getNombre() << " y tiene " << miPerro.getEdad() << " años" << endl;
    cout << "y tiene " << miPerro.getEdad() << " años" << endl;
    return 0;
}