#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP

#include <string>

//La idea de una clase es usarla como un molde para crear objetos o otras clases
class Empleado {
    protected:
    //protected es como private pero se puede acceder desde una clase hija
        std::string nombre;
        int edad;
        double salario;
    public:
    //Constructor
        Empleado(std::string _string,int edad, double _salario);
        
        //Destructor, limpia todo lo que la clase utilizo en vida
        virtual ~Empleado(){}

        //De esta manera todos los empleados tienen un metodo calcularPago, pero cada uno lo implementa de manera distinta
        virtual double calcularPago() const = 0; //Metodo virtual puro, si o si debe sobreescribirse en la clase hija

        //Este metodo podria es opcional reescribirlo
        virtual void mostrarDetalles() const;
};

#endif // EMPLEADO_HPP