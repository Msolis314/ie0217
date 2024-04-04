#include "EmpleadoPorHoras.hpp"

//Aqui se utiliza el constructor de la clase padre para inicializar los atributos de la clase padre y de la clase hija el atributo de la clase hija
EmpleadoPorHoras:: EmpleadoPorHoras(std:: string _nombre, int _edad, double _salario, int _horasTrabajadas)
    : Empleado(_nombre, _edad, _salario), horasTrabajadas(_horasTrabajadas) {}


double EmpleadoPorHoras:: calcularPago() const {
    return salario * horasTrabajadas; // Como es un empleado por horas, se multiplica el salario por las horas trabajadas
}