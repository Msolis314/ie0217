#ifndef CONTINENTE_HPP
#define CONTINENTE_HPP
#include <string>
#include <iostream>
#include "Pais.hpp"
#include "TiposPaises.hpp"

class Continente{
    private:
            std::string nombre;
            int numPaisesPrimerMundo;
            int numPaisesDesarrollo;
            PrimerMundo* paisesPrimerMundo[MAX_COUNTRIES];
            Desarrollo* paisesDesarrollo[MAX_COUNTRIES];
        public:
            Continente(std::string nombre);
            void setPaisesPrimerMundo();
            void setPaisesDesarrollo();
            int countCountriesAirport();
            void defaulCountries();
            std::string getNombre();
            void addCountry(int typeCountry, std::string nombre);
            void deleteCountry(int id);
            void printGeneralInfo();
            void print();

        ~Continente();
};
#endif // CONTINENTE_HPP