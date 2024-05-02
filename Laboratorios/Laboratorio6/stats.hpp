#ifndef STATS_HPP
#define STATS_HPP
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
template <class T>
class Statistics {
    public:
    // Se define el constructor y se pasa el vector de datos
    // & para pasar por referencia los valores
        Statistics(const std:: vector<T>& data);

        //Se definen las funciones mean y standardDeviation
        double mean() const;
        double standardDeviation() const;
    private:
    //EL vector de datos
    //Privado, solo puede ser accedido por la clase y por amigas
        std::vector<T> data;
};
#endif // STATS_HPP