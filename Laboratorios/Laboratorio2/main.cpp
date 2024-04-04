#include <iostream>
#include "EmpleadoAsalariado.hpp"
#include "EmpleadoPorHoras.hpp"

int main(){
    //nombre, edad, salario
    EmpleadoAsalariado emp1("Marito",30,2000);
    //nombre, edad, salario, horas trabajadas
    EmpleadoPorHoras emp2("Juanita",25,10,40);

    std::cout << "Detalles del empleado asalariado: " << std::endl;
    emp1.mostrarDetalles();

    std::cout << "Pago: $" << emp1.calcularPago() << std::endl;

    std::cout << "\nDetalles del empleado por horas: " << std::endl;
    emp2.mostrarDetalles();
    std::cout << "Pago: $" << emp2.calcularPago() << std::endl;
    return 0;
}