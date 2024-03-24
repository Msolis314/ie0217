#include <iostream>
using namespace std;
#include "persona.hpp"

int main(){
    Persona p("Juan", 25);

    cout << "Nombre: " << p.getNombre() << endl;
    cout << "Edad: " << p.getEdad() << endl;

    p.setEdad(26);
    cout << "Nueva eSdad: " << p.getEdad() << endl;
    return 0;
}