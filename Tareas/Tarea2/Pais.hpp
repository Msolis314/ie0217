#ifndef PAIS_HPP
#define PAIS_HPP
#include <string>


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
        virtual void setG5() = 0;
        double generateHabitantes() const;
        void print();
};

#endif // PAIS_HPP