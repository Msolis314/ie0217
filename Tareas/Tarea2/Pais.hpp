#ifndef PAIS_HPP
#define PAIS_HPP
#include <string>
#include "Tools.hpp"


extern int id_list[MAX_COUNTRIES];
/// @brief Clase abstracta que representa un país.
class Pais{
    protected:
        int id;
        bool G5;
        int habitantes;
        double PIB;
        std::string nombre;
        int typeCountry;
        bool airport;

    public:
        Pais( int typeCountry, std::string nombre);
        int getId();
        virtual int generateId() const = 0;
        std::string getNombre();

        bool getG5();
        double calculatePIB(int typeCountry) const;
        double getPIB();

        bool hasAirport();

        int getHabitantes();
        bool setG5();
        double generateHabitantes() const;
        void print();
};

#endif // PAIS_HPP