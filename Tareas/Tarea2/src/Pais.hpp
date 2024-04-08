#ifndef PAIS_HPP
#define PAIS_HPP
#include <string>
#include "Tools.hpp"


extern int id_list[MAX_COUNTRIES];
/// @brief Clase base que representa un país.
///
/// Esta clase se encuentra compuesta por un id, un booleano que indica si el país pertenece al G5, un entero que indica la cantidad de habitantes, un double que indica el PIB, un string que indica el nombre del país, un entero que indica el tipo de país y un booleano que indica si el país tiene aeropuerto.
class Pais{
    protected:
        /// @note id_list es una lista de ids de paises.
        /// @note id_list es una variable global.
        int id;
        bool G5;
        int habitantes;
        double PIB;
        std::string nombre;
        int typeCountry;
        bool airport;

    public:
        /// @brief Constructor de la clase Pais, inicializa el nombre del país y el tipo de país.
        /// @param typeCountry tipo de pais
        /// @note typeCountry es un entero que indica el tipo de país.Puede ser DESARROLLO o PRIMER_MUNDO.
        /// @param nombre nombre del país
        Pais( int typeCountry, std::string nombre);

        /// @brief Sobrecarga del operador ==, compara dos paises.
        /// @param p pais a comparar
        /// @return Pais
        Pais operator==(const Pais& p);

        /// @brief Acceder al atributo id.
        /// @return numero de id
        int getId();

        /// @brief Generar un id para el país.
        /// @return id
        /// @note Se sobreescribe en las clases hijas.
        int generateId();

        /// @brief Acceder al atributo nombre.
        std::string getNombre();

        /// @brief Acceder al atributo G5.
        bool getG5();

        /// @brief Calcular el PIB del país.
        /// @param typeCountry tipo de pais
        /// @return PIB
        double calculatePIB(int typeCountry) const;

        /// @brief Acceder al atributo PIB.
        /// @return PIB
        double getPIB();

        /// @brief Determinar si el país tiene aeropuerto.
        bool hasAirport();

        /// @brief Acceder al atributo habitantes.
        int getHabitantes();

        /// @brief Determinar si el pais tiene 5G
        /// @return true si el pais tiene 5G, false si no
        bool setG5();

        /// @brief Acceder al atributo airport.
        /// @return true si el pais tiene aeropuerto, false si no
        bool getAirport();

        /// @brief Generar la cantidad de habitantes del país.
        /// @return cantidad de habitantes
        double generateHabitantes() const;

        /// @brief Imprimir la información del país.
        ///
        /// Se sobreescribe en las clases hijas.
        void print();
};

#endif // PAIS_HPP