#ifndef EMPLEADOASALARIADO_HPP
#define EMPLEADOASALARIADO_HPP

#include "Empleado.hpp"

//Esta clase hereda de manera publica de Empleado
class EmpleadoAsalariado : public Empleado {
    public:
        EmpleadoAsalariado(std::string _nombre,int _edad,double _salario);
        double calcularPago() const override;
};

#endif // EMPLEADOASALARIADO_HPP