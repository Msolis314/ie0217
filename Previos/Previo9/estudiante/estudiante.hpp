#ifndef ESTUDiANTE_HPP
#define ESTUDiANTE_HPP

#include <string>

class Estudiante {
public:
    Estudiante(const std::string& nombre,int edad);
    void mostrarDatos();
private:
    std::string nombre;
    int edad;
    int edad2;
};
#endif // ESTUDiANTE_HPP