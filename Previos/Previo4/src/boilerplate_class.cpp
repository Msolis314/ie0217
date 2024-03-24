#include <iostream>
using namespace std;

class NombreClase {
    private:
        int atributo1;
        double atributo2;
    public:
        // Constructores
        NombreClase(int atributo1_p, double atributo2_p): atributo1(atributo1_p), atributo2(atributo2_p) {
            cout << "Probando si se puede imprimir" << endl;
        }
        
        //Destructor
        ~NombreClase();

        // Metodos publicos de la clase

        void metodo1(){
            cout << "Hola soy el metodo 1" << endl;
        }

        void metodo2(){
            cout << "Hola soy el metodo 2" << endl;
        }

};
class Molde {
    public:
        double largo;
        double ancho;
        double alto;

        // Lo primero que se ejecuta al instanciar un objeto
        Molde(double largo_p, double ancho_p, double alto_p): largo(largo_p), ancho(ancho_p), alto(alto_p) {}
        /*Molde(double largo_p, double ancho_p, double alto_p) {
            largo = largo_p;
            ancho = ancho_p;
            alto = alto_p;
        }
        */

       ~Molde(){
        cout << "Saludos desde el destructor de la clase Molde" << endl;
       }
    double calcularArea(){
        return largo * ancho;
    }

    double calcularVolumen(){
        return largo * ancho * alto;
    }

};

int main(){
    int variable_entera;
    Molde pared(10.0,20.0,35.0); //instanciando 

    cout << pared.largo << endl;

    //accediendo a los miembros de una clase
    pared.largo = 20.0;

    cout << pared.largo << endl;
    pared.ancho = 13.2;
    pared.alto = 23.4;

    cout << "El area es:" << pared.calcularArea() << endl;
    cout << "El volumen es:" << pared.calcularVolumen() << endl;

    return 0;
}