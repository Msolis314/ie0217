#ifndef PLANETA_HPP
#define PLANETA_HPP
#include <string>
#include <iostream>
#include "Continente.hpp"
#include "Tools.hpp"
#define MAX_CONTINENTS 10
class Planeta{
    private:
        int numContinentes;
        std::string nombre;
        Continente* continentes[MAX_CONTINENTS];
    public:
        Planeta(std::string nombre);
        void setNumContinentes();
        void setContinentes();
        void avion();
        void print();
        ~Planeta();
};
#endif // PLANETA_HPP