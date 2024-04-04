#include "EmpleadoAsalariado.hpp"

EmpleadoAsalariado::EmpleadoAsalariado(std::string _nombre,int _edad,double _salario)
    : Empleado(_nombre,_edad,_salario) {}

//Este metodo por ser virtual puro en la clase padre debe sobreescribirse
double EmpleadoAsalariado::calcularPago() const {
    return salario;
}