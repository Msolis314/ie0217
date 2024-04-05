#ifndef TIPOS_PAISES_HPP
#define TIPOS_PAISES_HPP
#include <string>
#include <iostream>
#include "Pais.hpp"
#include "Tools.hpp"
/// @brief Clase que representa un país del primer mundo.
///
/// @details Esta clase hereda de la clase Pais y representa un país del primer mundo.
///Se encarga de calcular la población activa y de imprimir los datos del país.
class PrimerMundo : public Pais{
    private:
        int workingPopulation;

        /// @brief Calcular la poblacion trabajadora.
        /// @return Numero de habitantes trabajadores.
        int calculateWorkingPopulation() const;
    public:
        PrimerMundo(std::string nombre);

        /// @brief Establecer si el país tiene la tecnología 5G.
        void setG5();

        /// @brief Generar un id primo unico para el país.
        /// @return Id del país.
        int generateId() const;

        /// @brief Establecer si el pais tiene centros de investigacion.
        /// @return True si tiene centros de investigacion, false en caso contrario.
        bool investigationCenter();

        /// @brief Devolver la poblacion trabajadora.
        void getWorkingPopulation();

        /// @brief Imprimir los datos del país.
        void print();

};

class Desarrollo : public Pais{
    public:
        Desarrollo(std::string nombre);
        void setG5();
        int generateId() const;
        void print();
};

#endif // TIPOS_PAISES_HPP