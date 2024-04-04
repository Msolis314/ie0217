#include "Empleado.hpp"
#include <iostream>

//Esta es la clase base
Empleado::Empleado(std::string _nombre,int _edad,double _salario):
    nombre(_nombre), edad(_edad), salario(_salario) {}

//Los metodos que no se definen en la clase se definen en las clases hijas

void Empleado::mostrarDetalles() const {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Edad: " << edad << std::endl;
    std::cout << "Salario: " << salario << std::endl;
}