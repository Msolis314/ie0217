#ifndef EMPLEADOPORHORAS_HPP
#define EMPLEADOPORHORAS_HPP

#include "Empleado.hpp"

//Esta clase hereda de manera publica de Empleado
class EmpleadoPorHoras : public Empleado {

    private:
        int horasTrabajadas;

    public: 
        EmpleadoPorHoras(std::string _nombre,int  _edad,double _salario,int  _horasTrabajadas);
        //Este metodo se debe modificar ya que es virtual puro
        double calcularPago() const override;
};  
#endif // EMPLEADOPORHORAS_HPP