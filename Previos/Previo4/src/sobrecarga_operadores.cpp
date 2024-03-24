#include <iostream>
using namespace std;

class Fraccion{
    int numerador, denominador;
    public:
        Fraccion(int n, int d): numerador(n), denominador(d){} //constructor necesita numerador y denominador
        Fraccion operator+ (const Fraccion &f){ //Se pasa una referencia al objeto Fraccion
            Fraccion resultado{
                numerador * f.denominador + f.numerador * denominador,
                denominador * f.denominador
            }; // f representa la otra y se accede a sus atributos
            return resultado; //Se retorna el objeto Fraccion
        }
        
        void imprimir(){
            cout << this -> numerador << "/" << this -> denominador << endl;
        }
};

int main(){
    Fraccion f1(1, 2);
    Fraccion f2(3, 4);
    Fraccion f3 = f1 + f2;
    f3.imprimir();
    return 0;
}